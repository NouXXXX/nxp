/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *main;
	bool main_del;
	lv_obj_t *main_contMain;
	lv_obj_t *main_imgHalfDome;
	lv_obj_t *main_lblMain;
	lv_obj_t *main_lblClock;
	lv_obj_t *main_imgbtnSettings;
	lv_obj_t *main_imgbtnSettings_label;
	lv_obj_t *main_imgConnected;
	lv_obj_t *main_imgNotConnected;
	lv_obj_t *main_imgTImeOK;
	lv_obj_t *main_imgTimeNotOK;
	lv_obj_t *main_lblDegree;
	lv_obj_t *main_lblDegree2;
	lv_obj_t *main_imgSun;
	lv_obj_t *main_imgIntervals;
	lv_obj_t *main_imgCloud;
	lv_obj_t *main_imgRain;
	lv_obj_t *main_imgThunder;
	lv_obj_t *main_imgSnow;
	lv_obj_t *main_btnTest;
	lv_obj_t *main_btnTest_label;
	lv_obj_t *main_imgSnowOff;
	lv_obj_t *main_imgThunderOff;
	lv_obj_t *main_imgRainOff;
	lv_obj_t *main_imgCloudOff;
	lv_obj_t *main_imgIntervalsOff;
	lv_obj_t *main_imgSunOff;
	lv_obj_t *main_imgDP1;
	lv_obj_t *main_imgDP2;
	lv_obj_t *main_imgL1a;
	lv_obj_t *main_imgL2a;
	lv_obj_t *main_imgL3a;
	lv_obj_t *main_imgL4a;
	lv_obj_t *main_imgL4d;
	lv_obj_t *main_imgL3d;
	lv_obj_t *main_imgL2d;
	lv_obj_t *main_imgL1d;
	lv_obj_t *main_imgL4g;
	lv_obj_t *main_imgL3g;
	lv_obj_t *main_imgL2g;
	lv_obj_t *main_imgL1g;
	lv_obj_t *main_imgL1b;
	lv_obj_t *main_imgL2b;
	lv_obj_t *main_imgL3b;
	lv_obj_t *main_imgL4b;
	lv_obj_t *main_imgL4c;
	lv_obj_t *main_imgL3c;
	lv_obj_t *main_imgL2c;
	lv_obj_t *main_imgL1c;
	lv_obj_t *main_imgL4e;
	lv_obj_t *main_imgL3e;
	lv_obj_t *main_imgL2e;
	lv_obj_t *main_imgL1e;
	lv_obj_t *main_imgL4f;
	lv_obj_t *main_imgL3f;
	lv_obj_t *main_imgL2f;
	lv_obj_t *main_imgL1f;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_main(lv_ui *ui);
LV_IMG_DECLARE(_half_dome_alpha_720x1224);
LV_IMG_DECLARE(_setting_alpha_48x48);
LV_IMG_DECLARE(_connect_alpha_48x48);
LV_IMG_DECLARE(_connected_alpha_48x48);
LV_IMG_DECLARE(_time_alpha_48x48);
LV_IMG_DECLARE(_timeNot_alpha_48x48);
LV_IMG_DECLARE(_sun_alpha_100x100);
LV_IMG_DECLARE(_cloudSun_alpha_100x100);
LV_IMG_DECLARE(_cloud_alpha_100x100);
LV_IMG_DECLARE(_rain_alpha_100x100);
LV_IMG_DECLARE(_thunder_alpha_100x100);
LV_IMG_DECLARE(_snow_alpha_100x100);
LV_IMG_DECLARE(_snowN_alpha_100x100);
LV_IMG_DECLARE(_thunderN_alpha_100x100);
LV_IMG_DECLARE(_rainN_alpha_100x100);
LV_IMG_DECLARE(_cloudN_alpha_100x100);
LV_IMG_DECLARE(_cloudSunN_alpha_100x100);
LV_IMG_DECLARE(_sunN_alpha_100x100);
LV_IMG_DECLARE(_round_alpha_30x130);
LV_IMG_DECLARE(_round_alpha_30x130);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon2_alpha_97x20);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);
LV_IMG_DECLARE(_polygon_alpha_30x132);

LV_FONT_DECLARE(lv_font_JalnanGothicTTF_36)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_JalnanGothicTTF_48)
LV_FONT_DECLARE(lv_font_montserratMedium_48)


#ifdef __cplusplus
}
#endif
#endif
