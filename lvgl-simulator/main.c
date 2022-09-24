#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "system.h"
#include "f1c100s_timer.h"
#include "f1c100s_intc.h"
#include "io.h"
#include "display.h"
#include "arm32.h"
#include "lvgl/lvgl.h"
#include "lv_demo_widgets.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "f1c100s_uart.h"

static void hal_init(void);

void timer_init(void);
void timer_irq_handler(void);
void muart_init(void);
void uart0_irq_handler(void);
void uart2_irq_handler(void);

#define UART_MAX 100
uint8_t uart_buffer[UART_MAX];
uint16_t uart_buffer_ind = 0;

void lvgl_print_cb(lv_log_level_t level, const char *file, uint32_t line, const char *func, const char *buf);


lv_ui guider_ui;

int main(int argc, char ** argv)
{

    system_init();
    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LittlevGL*/
    hal_init();
    muart_init();

    

    /*Create a GUI-Guider app */
	setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui); 
    

    //lv_gauge_set_value(&guider_ui.screen_gauge_1,0,50);
    
    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        
        lv_task_handler();
 
    }

    return 0;
}

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void)
{
    system_init(); // Initialize clocks, mmu, cache, uart, ...
    arm32_interrupt_enable(); // Enable interrupts

    printf("Hello from firmware!\r\n");
    timer_init();

    lv_init();
    lv_log_register_print_cb(lvgl_print_cb);
    display_init_lvgl();
    display_set_bl(100);
}


void timer_init(void)
{
    // Configure timer to generate update event every 1ms
    tim_init(TIM0, TIM_MODE_CONT, TIM_SRC_HOSC, TIM_PSC_1);
    tim_set_period(TIM0, 24000000UL / 1000UL);
    tim_int_enable(TIM0);
    // IRQ configuration
    intc_set_irq_handler(IRQ_TIMER0, timer_irq_handler);
    intc_enable_irq(IRQ_TIMER0);

    tim_start(TIM0);
}

void uart_irq_handler(void)
{
    uint8_t in_char = uart_get_rx(UART0);

    if (uart_buffer_ind < UART_MAX)
    {

        uart_buffer[uart_buffer_ind] = in_char;
        uart_buffer_ind++;
        if (in_char == '\r' || in_char == '\n')
        {
            uart_buffer[uart_buffer_ind] = '\0';
            int BufferToInt;
            sscanf(uart_buffer, "%d", &BufferToInt);
            printf("Received ! %d \r\n", BufferToInt);
            uart_buffer_ind = 0;
            memset(uart_buffer, 0, UART_MAX);
            
            dosm(&guider_ui,BufferToInt);
        }
    }
    else
    {
        memset(uart_buffer, 0, UART_MAX);
    }
    
    //printf("Received ! %c\r\n",cha);
}

void muart_init(void)
{
    uart_enable_interrupt(UART0, UART_IEN_RBF);
    intc_set_irq_handler(IRQ_UART0, uart_irq_handler);
    intc_enable_irq(IRQ_UART0);
    printf("uart enabled\r\n");
    
}



void timer_irq_handler(void)
{
    lv_tick_inc(1);
    tim_clear_irq(TIM0);
}

void lvgl_print_cb(lv_log_level_t level, const char *file, uint32_t line, const char *func, const char *buf)
{
    /*Use only the file name not the path*/
    size_t p;
    for (p = strlen(file); p > 0; p--)
    {
        if (file[p] == '/' || file[p] == '\\')
        {
            p++; /*Skip the slash*/
            break;
        }
    }

    static const char *lvl_prefix[] =
        { "Trace", "Info", "Warn", "Error", "User" };
    printf("%s: %s \t(%s #%lu %s())\r\n", lvl_prefix[level], buf, &file[p], line, func);
}

 void sdelay(int loops)
{
    __asm__ __volatile__ ("1:\n" "subs %0, %1, #1\n" "bne 1b":"=r" (loops):"0"(loops));
}
