/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen2(lv_ui *ui){

	//Write codes screen2
	ui->screen2 = lv_obj_create(NULL, NULL);

	//Write style LV_OBJ_PART_MAIN for screen2
	static lv_style_t style_screen2_main;
	lv_style_reset(&style_screen2_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_main
	lv_style_set_bg_color(&style_screen2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2, LV_OBJ_PART_MAIN, &style_screen2_main);

	//Write codes screen2_label0
	ui->screen2_label0 = lv_label_create(ui->screen2, NULL);
	lv_label_set_text(ui->screen2_label0, "screen2");
	lv_label_set_long_mode(ui->screen2_label0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_label0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen2_label0
	static lv_style_t style_screen2_label0_main;
	lv_style_reset(&style_screen2_label0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_label0_main
	lv_style_set_radius(&style_screen2_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_label0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_label0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_label0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen2_label0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_label0_main, LV_STATE_DEFAULT, &lv_font_arial_12);
	lv_style_set_text_letter_space(&style_screen2_label0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_label0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_label0, LV_LABEL_PART_MAIN, &style_screen2_label0_main);
	lv_obj_set_pos(ui->screen2_label0, 180, 240);
	lv_obj_set_size(ui->screen2_label0, 100, 0);

	//Write codes screen2_btn1_1
	ui->screen2_btn1_1 = lv_btn_create(ui->screen2, NULL);

	//Write style LV_BTN_PART_MAIN for screen2_btn1_1
	static lv_style_t style_screen2_btn1_1_main;
	lv_style_reset(&style_screen2_btn1_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_btn1_1_main
	lv_style_set_radius(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen2_btn1_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_btn1_1, LV_BTN_PART_MAIN, &style_screen2_btn1_1_main);
	lv_obj_set_pos(ui->screen2_btn1_1, 30, 235);
	lv_obj_set_size(ui->screen2_btn1_1, 100, 25);
	ui->screen2_btn1_1_label = lv_label_create(ui->screen2_btn1_1, NULL);
	lv_label_set_text(ui->screen2_btn1_1_label, "Previous Screen");
	lv_obj_set_style_local_text_color(ui->screen2_btn1_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen2_btn1_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_arial_12);

	//Write codes screen2_chart2
	ui->screen2_chart2 = lv_chart_create(ui->screen2, NULL);

	//Write style LV_CHART_PART_BG for screen2_chart2
	static lv_style_t style_screen2_chart2_bg;
	lv_style_reset(&style_screen2_chart2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen2_chart2_bg
	lv_style_set_bg_color(&style_screen2_chart2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_chart2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_chart2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_chart2_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen2_chart2_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_screen2_chart2_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_screen2_chart2_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_screen2_chart2_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen2_chart2, LV_CHART_PART_BG, &style_screen2_chart2_bg);

	//Write style LV_CHART_PART_SERIES_BG for screen2_chart2
	static lv_style_t style_screen2_chart2_series_bg;
	lv_style_reset(&style_screen2_chart2_series_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen2_chart2_series_bg
	lv_style_set_line_color(&style_screen2_chart2_series_bg, LV_STATE_DEFAULT, lv_color_make(0xe8, 0xe8, 0xe8));
	lv_style_set_line_width(&style_screen2_chart2_series_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_line_opa(&style_screen2_chart2_series_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_chart2, LV_CHART_PART_SERIES_BG, &style_screen2_chart2_series_bg);
	lv_obj_set_pos(ui->screen2_chart2, 129, 36);
	lv_obj_set_size(ui->screen2_chart2, 205, 155);
	lv_chart_set_type(ui->screen2_chart2,LV_CHART_TYPE_LINE);
	lv_chart_set_range(ui->screen2_chart2,0,100);
	lv_chart_set_div_line_count(ui->screen2_chart2, 3, 5);
	lv_chart_set_point_count(ui->screen2_chart2, 5);
	lv_chart_series_t * screen2_chart2_0 = lv_chart_add_series(ui->screen2_chart2, lv_color_make(0x00, 0x00, 0x00));
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,10);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,20);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,30);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,40);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,10);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,50);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,70);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,30);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,10);
	lv_chart_set_next(ui->screen2_chart2, screen2_chart2_0,30);

	//Init events for screen
	events_init_screen2(ui);
}