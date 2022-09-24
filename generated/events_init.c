/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"

void events_init(lv_ui *ui)
{
}

static void screen2_btn1_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_screen(&guider_ui);
		lv_scr_load(guider_ui.screen);
	}
		break;
	default:
		break;
	}
}

void events_init_screen2(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen2_btn1_1, screen2_btn1_1event_handler);
}
