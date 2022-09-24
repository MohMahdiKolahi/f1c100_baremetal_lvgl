/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_gauge2;
	lv_obj_t *screen_gauge_1;
	lv_obj_t *screen2;
	lv_obj_t *screen2_label0;
	lv_obj_t *screen2_btn1_1;
	lv_obj_t *screen2_btn1_1_label;
	lv_obj_t *screen2_chart2;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_screen2(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif