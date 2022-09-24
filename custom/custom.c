/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"
#include "f1c100s_uart.h"

/*********************
 *      DEFINES
 *********************/
//lv_ui *g_ui;
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static void gauge_anim(lv_obj_t *gauge, lv_anim_value_t value);


/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    //g_ui = ui;
    guider_ui = *ui;

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui->screen_gauge2);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)gauge_anim);
    lv_anim_set_values(&a, 0, 180);
    lv_anim_set_time(&a, 2500);
    lv_anim_set_playback_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);
    
}





static void gauge_anim(lv_obj_t *gauge, lv_anim_value_t value)
{
    lv_gauge_set_value(gauge, 0, value);

    //static char buf[64];
    //lv_snprintf(buf, sizeof(buf), "%d", value);
    //lv_obj_t * label = lv_obj_get_child(gauge, NULL);
    //lv_label_set_text(label, buf);
    //lv_obj_align(label, gauge, LV_ALIGN_IN_TOP_MID, 0, lv_obj_get_y(label));
}
