/**
 * @file lv_demo_widgets.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
//#include "../../lv_examples.h"
#include "lv_demo_widgets.h"
#include "lvgl/lvgl.h"

#if 1

/*********************
 *      DEFINES
 *********************/

#define LV_DEMO_WIDGETS_SLIDESHOW 1

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void controls_create(lv_obj_t * parent);
static void visuals_create(lv_obj_t * parent);
static void selectors_create(lv_obj_t * parent);
static void slider_event_cb(lv_obj_t * slider, lv_event_t e);
static void ta_event_cb(lv_obj_t * ta, lv_event_t e);
static void kb_event_cb(lv_obj_t * ta, lv_event_t e);
static void bar_anim(lv_task_t * t);
static void arc_anim(lv_obj_t * arc, lv_anim_value_t value);
static void linemeter_anim(lv_obj_t * linemeter, lv_anim_value_t value);
static void gauge_anim(lv_obj_t * gauge, lv_anim_value_t value);
static void table_event_cb(lv_obj_t * table, lv_event_t e);
#if LV_USE_THEME_MATERIAL
static void color_chg_event_cb(lv_obj_t * sw, lv_event_t e);
#endif
#if LV_DEMO_WIDGETS_SLIDESHOW
static void tab_content_anim_create(lv_obj_t * parent);
static void tab_changer_task_cb(lv_task_t * task);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * tv;
static lv_obj_t * t1;
static lv_obj_t * t2;
static lv_obj_t * t3;
static lv_obj_t * kb;

static lv_style_t style_box;

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_label0;
	lv_obj_t *screen_btn1;
	lv_obj_t *screen_btn1_label;
	lv_obj_t *screen_gauge2;
	lv_obj_t *screen2;
	lv_obj_t *screen2_label0;
	lv_obj_t *screen2_btn1_1;
	lv_obj_t *screen2_btn1_1_label;
	lv_obj_t *screen2_chart2;
}lv_ui;

lv_ui *ui;
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_demo_widgets(void)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write style LV_OBJ_PART_MAIN for screen
	static lv_style_t style_screen_main;
	lv_style_reset(&style_screen_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_main
	lv_style_set_bg_color(&style_screen_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen, LV_OBJ_PART_MAIN, &style_screen_main);

	//Write codes screen_label0
	ui->screen_label0 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label0, "screen1");
	lv_label_set_long_mode(ui->screen_label0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label0
	static lv_style_t style_screen_label0_main;
	lv_style_reset(&style_screen_label0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label0_main
	lv_style_set_radius(&style_screen_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_label0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//lv_style_set_text_font(&style_screen_label0_main, LV_STATE_DEFAULT, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_label0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label0, LV_LABEL_PART_MAIN, &style_screen_label0_main);
	lv_obj_set_pos(ui->screen_label0, 300, 423);
	lv_obj_set_size(ui->screen_label0, 166, 0);

	//Write codes screen_btn1
	ui->screen_btn1 = lv_btn_create(ui->screen, NULL);

	//Write style LV_BTN_PART_MAIN for screen_btn1
	static lv_style_t style_screen_btn1_main;
	lv_style_reset(&style_screen_btn1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn1_main
	lv_style_set_radius(&style_screen_btn1_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_btn1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_btn1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_btn1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_btn1_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_btn1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_btn1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_btn1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_btn1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_btn1, LV_BTN_PART_MAIN, &style_screen_btn1_main);
	lv_obj_set_pos(ui->screen_btn1, 575, 414);
	lv_obj_set_size(ui->screen_btn1, 166, 44);
	ui->screen_btn1_label = lv_label_create(ui->screen_btn1, NULL);
	lv_label_set_text(ui->screen_btn1_label, "Next Screen");
	lv_obj_set_style_local_text_color(ui->screen_btn1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//lv_obj_set_style_local_text_font(ui->screen_btn1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_arial_20);

	//Write codes screen_gauge2
	ui->screen_gauge2 = lv_gauge_create(ui->screen, NULL);

	//Write style LV_GAUGE_PART_MAIN for screen_gauge2
	static lv_style_t style_screen_gauge2_main;
	lv_style_reset(&style_screen_gauge2_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_gauge2_main
	lv_style_set_bg_color(&style_screen_gauge2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_gauge2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_gauge2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_gauge2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_gauge2_main, LV_STATE_DEFAULT, lv_color_make(0x39, 0x3c, 0x41));
	//lv_style_set_text_font(&style_screen_gauge2_main, LV_STATE_DEFAULT, &lv_font_arial_20);
	lv_style_set_text_letter_space(&style_screen_gauge2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_inner(&style_screen_gauge2_main, LV_STATE_DEFAULT, 15);
	lv_style_set_line_color(&style_screen_gauge2_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_line_width(&style_screen_gauge2_main, LV_STATE_DEFAULT, 3);
	lv_style_set_line_opa(&style_screen_gauge2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_screen_gauge2_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_end_color(&style_screen_gauge2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_scale_width(&style_screen_gauge2_main, LV_STATE_DEFAULT, 9);
	lv_style_set_scale_border_width(&style_screen_gauge2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_scale_end_border_width(&style_screen_gauge2_main, LV_STATE_DEFAULT, 5);
	lv_style_set_scale_end_line_width(&style_screen_gauge2_main, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(ui->screen_gauge2, LV_GAUGE_PART_MAIN, &style_screen_gauge2_main);

	//Write style LV_GAUGE_PART_MAJOR for screen_gauge2
	static lv_style_t style_screen_gauge2_major;
	lv_style_reset(&style_screen_gauge2_major);

	//Write style state: LV_STATE_DEFAULT for style_screen_gauge2_major
	lv_style_set_line_color(&style_screen_gauge2_major, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_line_width(&style_screen_gauge2_major, LV_STATE_DEFAULT, 5);
	lv_style_set_line_opa(&style_screen_gauge2_major, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_screen_gauge2_major, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_end_color(&style_screen_gauge2_major, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_scale_width(&style_screen_gauge2_major, LV_STATE_DEFAULT, 16);
	lv_style_set_scale_end_line_width(&style_screen_gauge2_major, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen_gauge2, LV_GAUGE_PART_MAJOR, &style_screen_gauge2_major);

	//Write style LV_GAUGE_PART_NEEDLE for screen_gauge2
	static lv_style_t style_screen_gauge2_needle;
	lv_style_reset(&style_screen_gauge2_needle);

	//Write style state: LV_STATE_DEFAULT for style_screen_gauge2_needle
	lv_style_set_size(&style_screen_gauge2_needle, LV_STATE_DEFAULT, 21);
	lv_style_set_bg_color(&style_screen_gauge2_needle, LV_STATE_DEFAULT, lv_color_make(0x41, 0x48, 0x5a));
	lv_style_set_bg_grad_color(&style_screen_gauge2_needle, LV_STATE_DEFAULT, lv_color_make(0x41, 0x48, 0x5a));
	lv_style_set_bg_grad_dir(&style_screen_gauge2_needle, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_gauge2_needle, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_inner(&style_screen_gauge2_needle, LV_STATE_DEFAULT, 0);
	lv_style_set_line_width(&style_screen_gauge2_needle, LV_STATE_DEFAULT, 4);
	lv_style_set_line_opa(&style_screen_gauge2_needle, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_gauge2, LV_GAUGE_PART_NEEDLE, &style_screen_gauge2_needle);
	lv_obj_set_pos(ui->screen_gauge2, 245, 35);
	lv_obj_set_size(ui->screen_gauge2, 333, 333);
	lv_gauge_set_scale(ui->screen_gauge2, 300, 37, 19);
	lv_gauge_set_range(ui->screen_gauge2, 0, 180);
	static lv_color_t needle_colors_screen_gauge2[1];
	needle_colors_screen_gauge2[0] = lv_color_make(0xff, 0x00, 0x00);
	lv_gauge_set_needle_count(ui->screen_gauge2, 1, needle_colors_screen_gauge2);
	lv_gauge_set_critical_value(ui->screen_gauge2, 120);
	lv_gauge_set_value(ui->screen_gauge2, 0, 0);

  lv_obj_t * lmeter = lv_linemeter_create(ui->screen, NULL);
    lv_obj_set_drag_parent(lmeter, true);
    lv_linemeter_set_value(lmeter, 50);
    lv_obj_set_size(lmeter, 100, 100);
    lv_obj_add_style(lmeter, LV_LINEMETER_PART_MAIN, &style_box);
    lv_obj_set_style_local_value_str(lmeter, LV_LINEMETER_PART_MAIN, LV_STATE_DEFAULT, "Line meter");

    lv_obj_t * label = lv_label_create(lmeter, NULL);
    lv_obj_align(label, lmeter, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_theme_get_font_title());


       lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, lmeter);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)linemeter_anim);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_time(&a, 4000);
    lv_anim_set_playback_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);


}


static void linemeter_anim(lv_obj_t * linemeter, lv_anim_value_t value)
{
    lv_linemeter_set_value(linemeter, value);

    static char buf[64];
    lv_snprintf(buf, sizeof(buf), "%d", value);
    lv_obj_t * label = lv_obj_get_child(linemeter, NULL);
    lv_label_set_text(label, buf);
    lv_obj_align(label, linemeter, LV_ALIGN_CENTER, 0, 0);
}
#endif
