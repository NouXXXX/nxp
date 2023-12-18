/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_main(lv_ui *ui)
{
	//Write codes main
	ui->main = lv_obj_create(NULL);
	lv_obj_set_size(ui->main, 720, 1280);

	//Write style for main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_contMain
	ui->main_contMain = lv_obj_create(ui->main);
	lv_obj_set_pos(ui->main_contMain, 0, 0);
	lv_obj_set_size(ui->main_contMain, 720, 1280);
	lv_obj_set_scrollbar_mode(ui->main_contMain, LV_SCROLLBAR_MODE_OFF);

	//Write style for main_contMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_contMain, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_contMain, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_contMain, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_contMain, lv_color_hex(0x7C94C1), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgHalfDome
	ui->main_imgHalfDome = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgHalfDome, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgHalfDome, &_half_dome_alpha_720x1224);
	lv_img_set_pivot(ui->main_imgHalfDome, 50,50);
	lv_img_set_angle(ui->main_imgHalfDome, 0);
	lv_obj_set_pos(ui->main_imgHalfDome, 0, 56);
	lv_obj_set_size(ui->main_imgHalfDome, 720, 1224);

	//Write style for main_imgHalfDome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgHalfDome, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_lblMain
	ui->main_lblMain = lv_label_create(ui->main_contMain);
	lv_label_set_text(ui->main_lblMain, "clock");
	lv_label_set_long_mode(ui->main_lblMain, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_lblMain, 13, 9);
	lv_obj_set_size(ui->main_lblMain, 178, 32);

	//Write style for main_lblMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_lblMain, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_lblMain, &lv_font_JalnanGothicTTF_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_lblMain, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_lblMain, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_lblMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_lblClock
	ui->main_lblClock = lv_label_create(ui->main_contMain);
	lv_label_set_text(ui->main_lblClock, "12:34");
	lv_label_set_long_mode(ui->main_lblClock, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_lblClock, 562, 11);
	lv_obj_set_size(ui->main_lblClock, 138, 32);

	//Write style for main_lblClock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_lblClock, lv_color_hex(0x4F434C), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_lblClock, &lv_font_JalnanGothicTTF_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_lblClock, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_lblClock, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_lblClock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgbtnSettings
	ui->main_imgbtnSettings = lv_imgbtn_create(ui->main_contMain);
	lv_imgbtn_set_src(ui->main_imgbtnSettings, LV_IMGBTN_STATE_RELEASED, NULL, &_setting_alpha_48x48, NULL);
	ui->main_imgbtnSettings_label = lv_label_create(ui->main_imgbtnSettings);
	lv_label_set_text(ui->main_imgbtnSettings_label, "");
	lv_label_set_long_mode(ui->main_imgbtnSettings_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_imgbtnSettings_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_imgbtnSettings, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_imgbtnSettings, 533, 2);
	lv_obj_set_size(ui->main_imgbtnSettings, 48, 48);

	//Write style for main_imgbtnSettings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_imgbtnSettings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_imgbtnSettings, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_imgbtnSettings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_imgbtnSettings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_imgbtnSettings, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_imgbtnSettings, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_imgbtnSettings, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_imgbtnSettings, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_imgbtnSettings, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_imgbtnSettings, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_imgbtnSettings, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_imgbtnSettings, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_imgbtnSettings, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_imgbtnSettings, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_imgbtnSettings, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_imgbtnSettings, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_imgConnected
	ui->main_imgConnected = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgConnected, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgConnected, &_connect_alpha_48x48);
	lv_img_set_pivot(ui->main_imgConnected, 50,50);
	lv_img_set_angle(ui->main_imgConnected, 0);
	lv_obj_set_pos(ui->main_imgConnected, 470, 5);
	lv_obj_set_size(ui->main_imgConnected, 48, 48);

	//Write style for main_imgConnected, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgConnected, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgNotConnected
	ui->main_imgNotConnected = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgNotConnected, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgNotConnected, &_connected_alpha_48x48);
	lv_img_set_pivot(ui->main_imgNotConnected, 50,50);
	lv_img_set_angle(ui->main_imgNotConnected, 0);
	lv_obj_set_pos(ui->main_imgNotConnected, 470, 5);
	lv_obj_set_size(ui->main_imgNotConnected, 48, 48);

	//Write style for main_imgNotConnected, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgNotConnected, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgTImeOK
	ui->main_imgTImeOK = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgTImeOK, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgTImeOK, &_time_alpha_48x48);
	lv_img_set_pivot(ui->main_imgTImeOK, 50,50);
	lv_img_set_angle(ui->main_imgTImeOK, 0);
	lv_obj_set_pos(ui->main_imgTImeOK, 406, 4);
	lv_obj_set_size(ui->main_imgTImeOK, 48, 48);

	//Write style for main_imgTImeOK, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgTImeOK, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgTimeNotOK
	ui->main_imgTimeNotOK = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgTimeNotOK, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgTimeNotOK, &_timeNot_alpha_48x48);
	lv_img_set_pivot(ui->main_imgTimeNotOK, 50,50);
	lv_img_set_angle(ui->main_imgTimeNotOK, 0);
	lv_obj_set_pos(ui->main_imgTimeNotOK, 406, 4);
	lv_obj_set_size(ui->main_imgTimeNotOK, 48, 48);

	//Write style for main_imgTimeNotOK, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgTimeNotOK, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_lblDegree
	ui->main_lblDegree = lv_label_create(ui->main_contMain);
	lv_label_set_text(ui->main_lblDegree, "21");
	lv_label_set_long_mode(ui->main_lblDegree, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_lblDegree, 147, 672);
	lv_obj_set_size(ui->main_lblDegree, 426, 44);

	//Write style for main_lblDegree, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_lblDegree, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_lblDegree, &lv_font_JalnanGothicTTF_48, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_lblDegree, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_lblDegree, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_lblDegree, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_lblDegree, lv_color_hex(0x181C25), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->main_lblDegree, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->main_lblDegree, lv_color_hex(0xE3DBD1), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_lblDegree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_lblDegree2
	ui->main_lblDegree2 = lv_label_create(ui->main_contMain);
	lv_label_set_text(ui->main_lblDegree2, "°");
	lv_label_set_long_mode(ui->main_lblDegree2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_lblDegree2, 572, 672);
	lv_obj_set_size(ui->main_lblDegree2, 22, 44);

	//Write style for main_lblDegree2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_lblDegree2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_lblDegree2, &lv_font_montserratMedium_48, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_lblDegree2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_lblDegree2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_lblDegree2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_lblDegree2, lv_color_hex(0xE3DBD1), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_lblDegree2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgSun
	ui->main_imgSun = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgSun, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgSun, &_sun_alpha_100x100);
	lv_img_set_pivot(ui->main_imgSun, 50,50);
	lv_img_set_angle(ui->main_imgSun, 0);
	lv_obj_set_pos(ui->main_imgSun, 10, 444);
	lv_obj_set_size(ui->main_imgSun, 100, 100);

	//Write style for main_imgSun, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgSun, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgIntervals
	ui->main_imgIntervals = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgIntervals, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgIntervals, &_cloudSun_alpha_100x100);
	lv_img_set_pivot(ui->main_imgIntervals, 50,50);
	lv_img_set_angle(ui->main_imgIntervals, 0);
	lv_obj_set_pos(ui->main_imgIntervals, 130, 444);
	lv_obj_set_size(ui->main_imgIntervals, 100, 100);

	//Write style for main_imgIntervals, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgIntervals, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgCloud
	ui->main_imgCloud = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgCloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgCloud, &_cloud_alpha_100x100);
	lv_img_set_pivot(ui->main_imgCloud, 50,50);
	lv_img_set_angle(ui->main_imgCloud, 0);
	lv_obj_set_pos(ui->main_imgCloud, 250, 444);
	lv_obj_set_size(ui->main_imgCloud, 100, 100);

	//Write style for main_imgCloud, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgCloud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgRain
	ui->main_imgRain = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgRain, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgRain, &_rain_alpha_100x100);
	lv_img_set_pivot(ui->main_imgRain, 50,50);
	lv_img_set_angle(ui->main_imgRain, 0);
	lv_obj_set_pos(ui->main_imgRain, 370, 444);
	lv_obj_set_size(ui->main_imgRain, 100, 100);

	//Write style for main_imgRain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgRain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgThunder
	ui->main_imgThunder = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgThunder, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgThunder, &_thunder_alpha_100x100);
	lv_img_set_pivot(ui->main_imgThunder, 50,50);
	lv_img_set_angle(ui->main_imgThunder, 0);
	lv_obj_set_pos(ui->main_imgThunder, 490, 444);
	lv_obj_set_size(ui->main_imgThunder, 100, 100);

	//Write style for main_imgThunder, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgThunder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgSnow
	ui->main_imgSnow = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgSnow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgSnow, &_snow_alpha_100x100);
	lv_img_set_pivot(ui->main_imgSnow, 50,50);
	lv_img_set_angle(ui->main_imgSnow, 0);
	lv_obj_set_pos(ui->main_imgSnow, 610, 444);
	lv_obj_set_size(ui->main_imgSnow, 100, 100);

	//Write style for main_imgSnow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgSnow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_btnTest
	ui->main_btnTest = lv_btn_create(ui->main_contMain);
	ui->main_btnTest_label = lv_label_create(ui->main_btnTest);
	lv_label_set_text(ui->main_btnTest_label, "test");
	lv_label_set_long_mode(ui->main_btnTest_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_btnTest_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_btnTest, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_btnTest, 489, 735);
	lv_obj_set_size(ui->main_btnTest, 100, 50);

	//Write style for main_btnTest, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_btnTest, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_btnTest, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_btnTest, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_btnTest, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_btnTest, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_btnTest, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_btnTest, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_btnTest, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgSnowOff
	ui->main_imgSnowOff = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgSnowOff, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgSnowOff, &_snowN_alpha_100x100);
	lv_img_set_pivot(ui->main_imgSnowOff, 50,50);
	lv_img_set_angle(ui->main_imgSnowOff, 0);
	lv_obj_set_pos(ui->main_imgSnowOff, 610, 444);
	lv_obj_set_size(ui->main_imgSnowOff, 100, 100);

	//Write style for main_imgSnowOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgSnowOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgThunderOff
	ui->main_imgThunderOff = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgThunderOff, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgThunderOff, &_thunderN_alpha_100x100);
	lv_img_set_pivot(ui->main_imgThunderOff, 50,50);
	lv_img_set_angle(ui->main_imgThunderOff, 0);
	lv_obj_set_pos(ui->main_imgThunderOff, 490, 444);
	lv_obj_set_size(ui->main_imgThunderOff, 100, 100);

	//Write style for main_imgThunderOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgThunderOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgRainOff
	ui->main_imgRainOff = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgRainOff, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgRainOff, &_rainN_alpha_100x100);
	lv_img_set_pivot(ui->main_imgRainOff, 50,50);
	lv_img_set_angle(ui->main_imgRainOff, 0);
	lv_obj_set_pos(ui->main_imgRainOff, 370, 444);
	lv_obj_set_size(ui->main_imgRainOff, 100, 100);

	//Write style for main_imgRainOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgRainOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgCloudOff
	ui->main_imgCloudOff = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgCloudOff, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgCloudOff, &_cloudN_alpha_100x100);
	lv_img_set_pivot(ui->main_imgCloudOff, 50,50);
	lv_img_set_angle(ui->main_imgCloudOff, 0);
	lv_obj_set_pos(ui->main_imgCloudOff, 250, 444);
	lv_obj_set_size(ui->main_imgCloudOff, 100, 100);

	//Write style for main_imgCloudOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgCloudOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgIntervalsOff
	ui->main_imgIntervalsOff = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgIntervalsOff, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgIntervalsOff, &_cloudSunN_alpha_100x100);
	lv_img_set_pivot(ui->main_imgIntervalsOff, 50,50);
	lv_img_set_angle(ui->main_imgIntervalsOff, 0);
	lv_obj_set_pos(ui->main_imgIntervalsOff, 130, 444);
	lv_obj_set_size(ui->main_imgIntervalsOff, 100, 100);

	//Write style for main_imgIntervalsOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgIntervalsOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgSunOff
	ui->main_imgSunOff = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgSunOff, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgSunOff, &_sunN_alpha_100x100);
	lv_img_set_pivot(ui->main_imgSunOff, 50,50);
	lv_img_set_angle(ui->main_imgSunOff, 0);
	lv_obj_set_pos(ui->main_imgSunOff, 10, 444);
	lv_obj_set_size(ui->main_imgSunOff, 100, 100);

	//Write style for main_imgSunOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgSunOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgDP1
	ui->main_imgDP1 = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgDP1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgDP1, &_round_alpha_30x130);
	lv_img_set_pivot(ui->main_imgDP1, 50,50);
	lv_img_set_angle(ui->main_imgDP1, 0);
	lv_obj_set_pos(ui->main_imgDP1, 359, 152);
	lv_obj_set_size(ui->main_imgDP1, 30, 130);

	//Write style for main_imgDP1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgDP1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgDP2
	ui->main_imgDP2 = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgDP2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgDP2, &_round_alpha_30x130);
	lv_img_set_pivot(ui->main_imgDP2, 50,50);
	lv_img_set_angle(ui->main_imgDP2, 0);
	lv_obj_set_pos(ui->main_imgDP2, 355, 272);
	lv_obj_set_size(ui->main_imgDP2, 30, 130);

	//Write style for main_imgDP2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgDP2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1a
	ui->main_imgL1a = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1a, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1a, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL1a, 50,50);
	lv_img_set_angle(ui->main_imgL1a, 0);
	lv_obj_set_pos(ui->main_imgL1a, 76, 131);
	lv_obj_set_size(ui->main_imgL1a, 97, 20);

	//Write style for main_imgL1a, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1a, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2a
	ui->main_imgL2a = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2a, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2a, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL2a, 50,50);
	lv_img_set_angle(ui->main_imgL2a, 0);
	lv_obj_set_pos(ui->main_imgL2a, 225, 134);
	lv_obj_set_size(ui->main_imgL2a, 97, 20);

	//Write style for main_imgL2a, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2a, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3a
	ui->main_imgL3a = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3a, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3a, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL3a, 50,50);
	lv_img_set_angle(ui->main_imgL3a, 0);
	lv_obj_set_pos(ui->main_imgL3a, 415, 137);
	lv_obj_set_size(ui->main_imgL3a, 97, 20);

	//Write style for main_imgL3a, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3a, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4a
	ui->main_imgL4a = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4a, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4a, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL4a, 50,50);
	lv_img_set_angle(ui->main_imgL4a, 0);
	lv_obj_set_pos(ui->main_imgL4a, 558, 139);
	lv_obj_set_size(ui->main_imgL4a, 97, 20);

	//Write style for main_imgL4a, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4a, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4d
	ui->main_imgL4d = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4d, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4d, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL4d, 50,50);
	lv_img_set_angle(ui->main_imgL4d, 0);
	lv_obj_set_pos(ui->main_imgL4d, 546, 268);
	lv_obj_set_size(ui->main_imgL4d, 97, 20);

	//Write style for main_imgL4d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3d
	ui->main_imgL3d = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3d, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3d, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL3d, 50,50);
	lv_img_set_angle(ui->main_imgL3d, 0);
	lv_obj_set_pos(ui->main_imgL3d, 407, 272);
	lv_obj_set_size(ui->main_imgL3d, 97, 20);

	//Write style for main_imgL3d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2d
	ui->main_imgL2d = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2d, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2d, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL2d, 50,50);
	lv_img_set_angle(ui->main_imgL2d, 0);
	lv_obj_set_pos(ui->main_imgL2d, 215, 264);
	lv_obj_set_size(ui->main_imgL2d, 97, 20);

	//Write style for main_imgL2d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1d
	ui->main_imgL1d = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1d, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1d, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL1d, 50,50);
	lv_img_set_angle(ui->main_imgL1d, 0);
	lv_obj_set_pos(ui->main_imgL1d, 64, 263);
	lv_obj_set_size(ui->main_imgL1d, 97, 20);

	//Write style for main_imgL1d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4g
	ui->main_imgL4g = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4g, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4g, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL4g, 50,50);
	lv_img_set_angle(ui->main_imgL4g, 0);
	lv_obj_set_pos(ui->main_imgL4g, 539, 401);
	lv_obj_set_size(ui->main_imgL4g, 97, 20);

	//Write style for main_imgL4g, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4g, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3g
	ui->main_imgL3g = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3g, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3g, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL3g, 50,50);
	lv_img_set_angle(ui->main_imgL3g, 0);
	lv_obj_set_pos(ui->main_imgL3g, 394, 401);
	lv_obj_set_size(ui->main_imgL3g, 97, 20);

	//Write style for main_imgL3g, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3g, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2g
	ui->main_imgL2g = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2g, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2g, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL2g, 50,50);
	lv_img_set_angle(ui->main_imgL2g, 0);
	lv_obj_set_pos(ui->main_imgL2g, 202, 398);
	lv_obj_set_size(ui->main_imgL2g, 97, 20);

	//Write style for main_imgL2g, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2g, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1g
	ui->main_imgL1g = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1g, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1g, &_polygon2_alpha_97x20);
	lv_img_set_pivot(ui->main_imgL1g, 50,50);
	lv_img_set_angle(ui->main_imgL1g, 0);
	lv_obj_set_pos(ui->main_imgL1g, 53, 393);
	lv_obj_set_size(ui->main_imgL1g, 97, 20);

	//Write style for main_imgL1g, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1g, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1b
	ui->main_imgL1b = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1b, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1b, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL1b, 50,50);
	lv_img_set_angle(ui->main_imgL1b, 0);
	lv_obj_set_pos(ui->main_imgL1b, 57, 143);
	lv_obj_set_size(ui->main_imgL1b, 30, 132);

	//Write style for main_imgL1b, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1b, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2b
	ui->main_imgL2b = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2b, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2b, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL2b, 50,50);
	lv_img_set_angle(ui->main_imgL2b, 0);
	lv_obj_set_pos(ui->main_imgL2b, 153, 144);
	lv_obj_set_size(ui->main_imgL2b, 30, 132);

	//Write style for main_imgL2b, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2b, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3b
	ui->main_imgL3b = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3b, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3b, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL3b, 50,50);
	lv_img_set_angle(ui->main_imgL3b, 0);
	lv_obj_set_pos(ui->main_imgL3b, 43, 270);
	lv_obj_set_size(ui->main_imgL3b, 30, 132);

	//Write style for main_imgL3b, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3b, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4b
	ui->main_imgL4b = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4b, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4b, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL4b, 50,50);
	lv_img_set_angle(ui->main_imgL4b, 0);
	lv_obj_set_pos(ui->main_imgL4b, 143, 274);
	lv_obj_set_size(ui->main_imgL4b, 30, 132);

	//Write style for main_imgL4b, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4b, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4c
	ui->main_imgL4c = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4c, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4c, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL4c, 50,50);
	lv_img_set_angle(ui->main_imgL4c, 0);
	lv_obj_set_pos(ui->main_imgL4c, 290, 277);
	lv_obj_set_size(ui->main_imgL4c, 30, 132);

	//Write style for main_imgL4c, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4c, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3c
	ui->main_imgL3c = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3c, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3c, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL3c, 50,50);
	lv_img_set_angle(ui->main_imgL3c, 0);
	lv_obj_set_pos(ui->main_imgL3c, 198, 273);
	lv_obj_set_size(ui->main_imgL3c, 30, 132);

	//Write style for main_imgL3c, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3c, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2c
	ui->main_imgL2c = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2c, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2c, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL2c, 50,50);
	lv_img_set_angle(ui->main_imgL2c, 0);
	lv_obj_set_pos(ui->main_imgL2c, 300, 146);
	lv_obj_set_size(ui->main_imgL2c, 30, 132);

	//Write style for main_imgL2c, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2c, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1c
	ui->main_imgL1c = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1c, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1c, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL1c, 50,50);
	lv_img_set_angle(ui->main_imgL1c, 0);
	lv_obj_set_pos(ui->main_imgL1c, 210, 146);
	lv_obj_set_size(ui->main_imgL1c, 30, 132);

	//Write style for main_imgL1c, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1c, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4e
	ui->main_imgL4e = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4e, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4e, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL4e, 50,50);
	lv_img_set_angle(ui->main_imgL4e, 0);
	lv_obj_set_pos(ui->main_imgL4e, 485, 284);
	lv_obj_set_size(ui->main_imgL4e, 30, 132);

	//Write style for main_imgL4e, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4e, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3e
	ui->main_imgL3e = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3e, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3e, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL3e, 50,50);
	lv_img_set_angle(ui->main_imgL3e, 0);
	lv_obj_set_pos(ui->main_imgL3e, 386, 281);
	lv_obj_set_size(ui->main_imgL3e, 30, 132);

	//Write style for main_imgL3e, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3e, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2e
	ui->main_imgL2e = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2e, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2e, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL2e, 50,50);
	lv_img_set_angle(ui->main_imgL2e, 0);
	lv_obj_set_pos(ui->main_imgL2e, 493, 149);
	lv_obj_set_size(ui->main_imgL2e, 30, 132);

	//Write style for main_imgL2e, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2e, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1e
	ui->main_imgL1e = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1e, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1e, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL1e, 50,50);
	lv_img_set_angle(ui->main_imgL1e, 0);
	lv_obj_set_pos(ui->main_imgL1e, 399, 154);
	lv_obj_set_size(ui->main_imgL1e, 30, 132);

	//Write style for main_imgL1e, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1e, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL4f
	ui->main_imgL4f = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL4f, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL4f, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL4f, 50,50);
	lv_img_set_angle(ui->main_imgL4f, 0);
	lv_obj_set_pos(ui->main_imgL4f, 626, 282);
	lv_obj_set_size(ui->main_imgL4f, 30, 132);

	//Write style for main_imgL4f, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL4f, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL3f
	ui->main_imgL3f = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL3f, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL3f, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL3f, 50,50);
	lv_img_set_angle(ui->main_imgL3f, 0);
	lv_obj_set_pos(ui->main_imgL3f, 532, 281);
	lv_obj_set_size(ui->main_imgL3f, 30, 132);

	//Write style for main_imgL3f, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL3f, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL2f
	ui->main_imgL2f = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL2f, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL2f, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL2f, 50,50);
	lv_img_set_angle(ui->main_imgL2f, 0);
	lv_obj_set_pos(ui->main_imgL2f, 634, 151);
	lv_obj_set_size(ui->main_imgL2f, 30, 132);

	//Write style for main_imgL2f, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL2f, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_imgL1f
	ui->main_imgL1f = lv_img_create(ui->main_contMain);
	lv_obj_add_flag(ui->main_imgL1f, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_imgL1f, &_polygon_alpha_30x132);
	lv_img_set_pivot(ui->main_imgL1f, 50,50);
	lv_img_set_angle(ui->main_imgL1f, 0);
	lv_obj_set_pos(ui->main_imgL1f, 540, 148);
	lv_obj_set_size(ui->main_imgL1f, 30, 132);

	//Write style for main_imgL1f, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_imgL1f, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->main);

	
	//Init events for screen.
	events_init_main(ui);
}
