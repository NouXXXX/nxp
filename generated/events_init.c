/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


static void main_btnTest_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		lv_obj_set_style_text_font(guider_ui.main_lblDegree, &lv_font_JalnanGothicTTF_48, 0);
		lv_label_set_text(guider_ui.main_lblDegree, "298123456789");
		break;
	}
	case LV_EVENT_RELEASED:
	{
		lv_obj_set_style_text_font(guider_ui.main_lblDegree, &lv_font_JalnanGothicTTF_48, 0);
		lv_label_set_text(guider_ui.main_lblDegree, "21");
		break;
	}
	default:
		break;
	}
}
void events_init_main(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->main_btnTest, main_btnTest_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
