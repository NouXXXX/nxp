# Copyright 2023 NXP
# NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

lv.init()
SDL.init(w=720,h=1280)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(720*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 720
disp_drv.ver_res = 1280
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init()
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    target = e.get_target()
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = target.get_screen()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = target.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, target), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    target = e.get_current_target()
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if target.get_pressed_date(date) == lv.RES.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.clear_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            target.delete()

# Create main
main = lv.obj()
main.set_size(720, 1280)
# Set style for main, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_contMain
main_contMain = lv.obj(main)
main_contMain.set_pos(0, 0)
main_contMain.set_size(720, 1280)
main_contMain.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for main_contMain, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_contMain.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_bg_color(lv.color_hex(0x7C94C1), lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_contMain.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create main_imgHalfDome
main_imgHalfDome = lv.img(main_contMain)
main_imgHalfDome.set_src("B:MicroPython/_half_dome_alpha_720x1224.bin")
main_imgHalfDome.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgHalfDome.set_pivot(50,50)
main_imgHalfDome.set_angle(0)
main_imgHalfDome.set_pos(0, 56)
main_imgHalfDome.set_size(720, 1224)
# Set style for main_imgHalfDome, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgHalfDome.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_lblMain
main_lblMain = lv.label(main_contMain)
main_lblMain.set_text("clock")
main_lblMain.set_long_mode(lv.label.LONG.WRAP)
main_lblMain.set_pos(13, 9)
main_lblMain.set_size(178, 32)
# Set style for main_lblMain, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_lblMain.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_text_font(test_font("JalnanGothicTTF", 36), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblMain.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_lblClock
main_lblClock = lv.label(main_contMain)
main_lblClock.set_text("12:34")
main_lblClock.set_long_mode(lv.label.LONG.WRAP)
main_lblClock.set_pos(562, 11)
main_lblClock.set_size(138, 32)
# Set style for main_lblClock, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_lblClock.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_text_color(lv.color_hex(0x4F434C), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_text_font(test_font("JalnanGothicTTF", 36), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_text_align(lv.TEXT_ALIGN.RIGHT, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblClock.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgbtnSettings
main_imgbtnSettings = lv.imgbtn(main_contMain)
main_imgbtnSettings.set_src(lv.imgbtn.STATE.RELEASED, None, "B:MicroPython/_setting_alpha_48x48.bin", None)
main_imgbtnSettings.add_flag(lv.obj.FLAG.CHECKABLE)
main_imgbtnSettings_label = lv.label(main_imgbtnSettings)
main_imgbtnSettings_label.set_text("")
main_imgbtnSettings_label.set_long_mode(lv.label.LONG.WRAP)
main_imgbtnSettings_label.align(lv.ALIGN.CENTER, 0, 0)
main_imgbtnSettings.set_style_pad_all(0, lv.STATE.DEFAULT)
main_imgbtnSettings.set_pos(533, 2)
main_imgbtnSettings.set_size(48, 48)
# Set style for main_imgbtnSettings, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgbtnSettings.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
main_imgbtnSettings.set_style_text_font(test_font("montserratMedium", 12), lv.PART.MAIN|lv.STATE.DEFAULT)
main_imgbtnSettings.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
main_imgbtnSettings.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for main_imgbtnSettings, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
main_imgbtnSettings.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
main_imgbtnSettings.set_style_text_color(lv.color_hex(0xFF33FF), lv.PART.MAIN|lv.STATE.PRESSED)
main_imgbtnSettings.set_style_text_font(test_font("montserratMedium", 12), lv.PART.MAIN|lv.STATE.PRESSED)
main_imgbtnSettings.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
# Set style for main_imgbtnSettings, Part: lv.PART.MAIN, State: lv.STATE.CHECKED.
main_imgbtnSettings.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.CHECKED)
main_imgbtnSettings.set_style_text_color(lv.color_hex(0xFF33FF), lv.PART.MAIN|lv.STATE.CHECKED)
main_imgbtnSettings.set_style_text_font(test_font("montserratMedium", 12), lv.PART.MAIN|lv.STATE.CHECKED)
main_imgbtnSettings.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.CHECKED)
# Set style for main_imgbtnSettings, Part: lv.PART.MAIN, State: LV_IMGBTN_STATE_RELEASED.
main_imgbtnSettings.set_style_img_opa(255, lv.PART.MAIN|lv.imgbtn.STATE.RELEASED)

# Create main_imgConnected
main_imgConnected = lv.img(main_contMain)
main_imgConnected.set_src("B:MicroPython/_connect_alpha_48x48.bin")
main_imgConnected.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgConnected.set_pivot(50,50)
main_imgConnected.set_angle(0)
main_imgConnected.set_pos(470, 5)
main_imgConnected.set_size(48, 48)
# Set style for main_imgConnected, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgConnected.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgNotConnected
main_imgNotConnected = lv.img(main_contMain)
main_imgNotConnected.set_src("B:MicroPython/_connected_alpha_48x48.bin")
main_imgNotConnected.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgNotConnected.set_pivot(50,50)
main_imgNotConnected.set_angle(0)
main_imgNotConnected.set_pos(470, 5)
main_imgNotConnected.set_size(48, 48)
# Set style for main_imgNotConnected, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgNotConnected.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgTImeOK
main_imgTImeOK = lv.img(main_contMain)
main_imgTImeOK.set_src("B:MicroPython/_time_alpha_48x48.bin")
main_imgTImeOK.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgTImeOK.set_pivot(50,50)
main_imgTImeOK.set_angle(0)
main_imgTImeOK.set_pos(406, 4)
main_imgTImeOK.set_size(48, 48)
# Set style for main_imgTImeOK, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgTImeOK.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgTimeNotOK
main_imgTimeNotOK = lv.img(main_contMain)
main_imgTimeNotOK.set_src("B:MicroPython/_timeNot_alpha_48x48.bin")
main_imgTimeNotOK.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgTimeNotOK.set_pivot(50,50)
main_imgTimeNotOK.set_angle(0)
main_imgTimeNotOK.set_pos(406, 4)
main_imgTimeNotOK.set_size(48, 48)
# Set style for main_imgTimeNotOK, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgTimeNotOK.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_lblDegree
main_lblDegree = lv.label(main_contMain)
main_lblDegree.set_text("21")
main_lblDegree.set_long_mode(lv.label.LONG.WRAP)
main_lblDegree.set_pos(147, 672)
main_lblDegree.set_size(426, 44)
# Set style for main_lblDegree, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_lblDegree.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_text_font(test_font("JalnanGothicTTF", 48), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_text_align(lv.TEXT_ALIGN.RIGHT, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_bg_color(lv.color_hex(0x181C25), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_bg_grad_dir(lv.GRAD_DIR.HOR, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_bg_grad_color(lv.color_hex(0xE3DBD1), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_lblDegree2
main_lblDegree2 = lv.label(main_contMain)
main_lblDegree2.set_text("°")
main_lblDegree2.set_long_mode(lv.label.LONG.WRAP)
main_lblDegree2.set_pos(572, 672)
main_lblDegree2.set_size(22, 44)
# Set style for main_lblDegree2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_lblDegree2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_text_font(test_font("montserratMedium", 48), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_text_align(lv.TEXT_ALIGN.RIGHT, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_bg_color(lv.color_hex(0xE3DBD1), lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_lblDegree2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgSun
main_imgSun = lv.img(main_contMain)
main_imgSun.set_src("B:MicroPython/_sun_alpha_100x100.bin")
main_imgSun.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgSun.set_pivot(50,50)
main_imgSun.set_angle(0)
main_imgSun.set_pos(10, 444)
main_imgSun.set_size(100, 100)
# Set style for main_imgSun, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgSun.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgIntervals
main_imgIntervals = lv.img(main_contMain)
main_imgIntervals.set_src("B:MicroPython/_cloudSun_alpha_100x100.bin")
main_imgIntervals.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgIntervals.set_pivot(50,50)
main_imgIntervals.set_angle(0)
main_imgIntervals.set_pos(130, 444)
main_imgIntervals.set_size(100, 100)
# Set style for main_imgIntervals, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgIntervals.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgCloud
main_imgCloud = lv.img(main_contMain)
main_imgCloud.set_src("B:MicroPython/_cloud_alpha_100x100.bin")
main_imgCloud.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgCloud.set_pivot(50,50)
main_imgCloud.set_angle(0)
main_imgCloud.set_pos(250, 444)
main_imgCloud.set_size(100, 100)
# Set style for main_imgCloud, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgCloud.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgRain
main_imgRain = lv.img(main_contMain)
main_imgRain.set_src("B:MicroPython/_rain_alpha_100x100.bin")
main_imgRain.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgRain.set_pivot(50,50)
main_imgRain.set_angle(0)
main_imgRain.set_pos(370, 444)
main_imgRain.set_size(100, 100)
# Set style for main_imgRain, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgRain.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgThunder
main_imgThunder = lv.img(main_contMain)
main_imgThunder.set_src("B:MicroPython/_thunder_alpha_100x100.bin")
main_imgThunder.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgThunder.set_pivot(50,50)
main_imgThunder.set_angle(0)
main_imgThunder.set_pos(490, 444)
main_imgThunder.set_size(100, 100)
# Set style for main_imgThunder, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgThunder.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgSnow
main_imgSnow = lv.img(main_contMain)
main_imgSnow.set_src("B:MicroPython/_snow_alpha_100x100.bin")
main_imgSnow.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgSnow.set_pivot(50,50)
main_imgSnow.set_angle(0)
main_imgSnow.set_pos(610, 444)
main_imgSnow.set_size(100, 100)
# Set style for main_imgSnow, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgSnow.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_btnTest
main_btnTest = lv.btn(main_contMain)
main_btnTest_label = lv.label(main_btnTest)
main_btnTest_label.set_text("test")
main_btnTest_label.set_long_mode(lv.label.LONG.WRAP)
main_btnTest_label.align(lv.ALIGN.CENTER, 0, 0)
main_btnTest.set_style_pad_all(0, lv.STATE.DEFAULT)
main_btnTest.set_pos(489, 735)
main_btnTest.set_size(100, 50)
# Set style for main_btnTest, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_btnTest.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
main_btnTest.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgSnowOff
main_imgSnowOff = lv.img(main_contMain)
main_imgSnowOff.set_src("B:MicroPython/_snowN_alpha_100x100.bin")
main_imgSnowOff.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgSnowOff.set_pivot(50,50)
main_imgSnowOff.set_angle(0)
main_imgSnowOff.set_pos(610, 444)
main_imgSnowOff.set_size(100, 100)
# Set style for main_imgSnowOff, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgSnowOff.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgThunderOff
main_imgThunderOff = lv.img(main_contMain)
main_imgThunderOff.set_src("B:MicroPython/_thunderN_alpha_100x100.bin")
main_imgThunderOff.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgThunderOff.set_pivot(50,50)
main_imgThunderOff.set_angle(0)
main_imgThunderOff.set_pos(490, 444)
main_imgThunderOff.set_size(100, 100)
# Set style for main_imgThunderOff, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgThunderOff.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgRainOff
main_imgRainOff = lv.img(main_contMain)
main_imgRainOff.set_src("B:MicroPython/_rainN_alpha_100x100.bin")
main_imgRainOff.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgRainOff.set_pivot(50,50)
main_imgRainOff.set_angle(0)
main_imgRainOff.set_pos(370, 444)
main_imgRainOff.set_size(100, 100)
# Set style for main_imgRainOff, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgRainOff.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgCloudOff
main_imgCloudOff = lv.img(main_contMain)
main_imgCloudOff.set_src("B:MicroPython/_cloudN_alpha_100x100.bin")
main_imgCloudOff.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgCloudOff.set_pivot(50,50)
main_imgCloudOff.set_angle(0)
main_imgCloudOff.set_pos(250, 444)
main_imgCloudOff.set_size(100, 100)
# Set style for main_imgCloudOff, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgCloudOff.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgIntervalsOff
main_imgIntervalsOff = lv.img(main_contMain)
main_imgIntervalsOff.set_src("B:MicroPython/_cloudSunN_alpha_100x100.bin")
main_imgIntervalsOff.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgIntervalsOff.set_pivot(50,50)
main_imgIntervalsOff.set_angle(0)
main_imgIntervalsOff.set_pos(130, 444)
main_imgIntervalsOff.set_size(100, 100)
# Set style for main_imgIntervalsOff, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgIntervalsOff.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgSunOff
main_imgSunOff = lv.img(main_contMain)
main_imgSunOff.set_src("B:MicroPython/_sunN_alpha_100x100.bin")
main_imgSunOff.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgSunOff.set_pivot(50,50)
main_imgSunOff.set_angle(0)
main_imgSunOff.set_pos(10, 444)
main_imgSunOff.set_size(100, 100)
# Set style for main_imgSunOff, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgSunOff.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgDP1
main_imgDP1 = lv.img(main_contMain)
main_imgDP1.set_src("B:MicroPython/_round_alpha_30x130.bin")
main_imgDP1.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgDP1.set_pivot(50,50)
main_imgDP1.set_angle(0)
main_imgDP1.set_pos(359, 152)
main_imgDP1.set_size(30, 130)
# Set style for main_imgDP1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgDP1.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgDP2
main_imgDP2 = lv.img(main_contMain)
main_imgDP2.set_src("B:MicroPython/_round_alpha_30x130.bin")
main_imgDP2.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgDP2.set_pivot(50,50)
main_imgDP2.set_angle(0)
main_imgDP2.set_pos(355, 272)
main_imgDP2.set_size(30, 130)
# Set style for main_imgDP2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgDP2.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1a
main_imgL1a = lv.img(main_contMain)
main_imgL1a.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL1a.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1a.set_pivot(50,50)
main_imgL1a.set_angle(0)
main_imgL1a.set_pos(76, 131)
main_imgL1a.set_size(97, 20)
# Set style for main_imgL1a, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1a.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2a
main_imgL2a = lv.img(main_contMain)
main_imgL2a.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL2a.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2a.set_pivot(50,50)
main_imgL2a.set_angle(0)
main_imgL2a.set_pos(225, 134)
main_imgL2a.set_size(97, 20)
# Set style for main_imgL2a, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2a.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3a
main_imgL3a = lv.img(main_contMain)
main_imgL3a.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL3a.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3a.set_pivot(50,50)
main_imgL3a.set_angle(0)
main_imgL3a.set_pos(415, 137)
main_imgL3a.set_size(97, 20)
# Set style for main_imgL3a, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3a.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4a
main_imgL4a = lv.img(main_contMain)
main_imgL4a.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL4a.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4a.set_pivot(50,50)
main_imgL4a.set_angle(0)
main_imgL4a.set_pos(558, 139)
main_imgL4a.set_size(97, 20)
# Set style for main_imgL4a, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4a.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4d
main_imgL4d = lv.img(main_contMain)
main_imgL4d.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL4d.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4d.set_pivot(50,50)
main_imgL4d.set_angle(0)
main_imgL4d.set_pos(546, 268)
main_imgL4d.set_size(97, 20)
# Set style for main_imgL4d, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4d.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3d
main_imgL3d = lv.img(main_contMain)
main_imgL3d.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL3d.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3d.set_pivot(50,50)
main_imgL3d.set_angle(0)
main_imgL3d.set_pos(407, 272)
main_imgL3d.set_size(97, 20)
# Set style for main_imgL3d, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3d.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2d
main_imgL2d = lv.img(main_contMain)
main_imgL2d.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL2d.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2d.set_pivot(50,50)
main_imgL2d.set_angle(0)
main_imgL2d.set_pos(215, 264)
main_imgL2d.set_size(97, 20)
# Set style for main_imgL2d, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2d.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1d
main_imgL1d = lv.img(main_contMain)
main_imgL1d.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL1d.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1d.set_pivot(50,50)
main_imgL1d.set_angle(0)
main_imgL1d.set_pos(64, 263)
main_imgL1d.set_size(97, 20)
# Set style for main_imgL1d, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1d.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4g
main_imgL4g = lv.img(main_contMain)
main_imgL4g.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL4g.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4g.set_pivot(50,50)
main_imgL4g.set_angle(0)
main_imgL4g.set_pos(539, 401)
main_imgL4g.set_size(97, 20)
# Set style for main_imgL4g, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4g.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3g
main_imgL3g = lv.img(main_contMain)
main_imgL3g.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL3g.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3g.set_pivot(50,50)
main_imgL3g.set_angle(0)
main_imgL3g.set_pos(394, 401)
main_imgL3g.set_size(97, 20)
# Set style for main_imgL3g, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3g.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2g
main_imgL2g = lv.img(main_contMain)
main_imgL2g.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL2g.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2g.set_pivot(50,50)
main_imgL2g.set_angle(0)
main_imgL2g.set_pos(202, 398)
main_imgL2g.set_size(97, 20)
# Set style for main_imgL2g, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2g.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1g
main_imgL1g = lv.img(main_contMain)
main_imgL1g.set_src("B:MicroPython/_polygon2_alpha_97x20.bin")
main_imgL1g.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1g.set_pivot(50,50)
main_imgL1g.set_angle(0)
main_imgL1g.set_pos(53, 393)
main_imgL1g.set_size(97, 20)
# Set style for main_imgL1g, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1g.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1b
main_imgL1b = lv.img(main_contMain)
main_imgL1b.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL1b.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1b.set_pivot(50,50)
main_imgL1b.set_angle(0)
main_imgL1b.set_pos(57, 143)
main_imgL1b.set_size(30, 132)
# Set style for main_imgL1b, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1b.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2b
main_imgL2b = lv.img(main_contMain)
main_imgL2b.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL2b.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2b.set_pivot(50,50)
main_imgL2b.set_angle(0)
main_imgL2b.set_pos(153, 144)
main_imgL2b.set_size(30, 132)
# Set style for main_imgL2b, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2b.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3b
main_imgL3b = lv.img(main_contMain)
main_imgL3b.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL3b.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3b.set_pivot(50,50)
main_imgL3b.set_angle(0)
main_imgL3b.set_pos(43, 270)
main_imgL3b.set_size(30, 132)
# Set style for main_imgL3b, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3b.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4b
main_imgL4b = lv.img(main_contMain)
main_imgL4b.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL4b.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4b.set_pivot(50,50)
main_imgL4b.set_angle(0)
main_imgL4b.set_pos(143, 274)
main_imgL4b.set_size(30, 132)
# Set style for main_imgL4b, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4b.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4c
main_imgL4c = lv.img(main_contMain)
main_imgL4c.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL4c.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4c.set_pivot(50,50)
main_imgL4c.set_angle(0)
main_imgL4c.set_pos(290, 277)
main_imgL4c.set_size(30, 132)
# Set style for main_imgL4c, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4c.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3c
main_imgL3c = lv.img(main_contMain)
main_imgL3c.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL3c.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3c.set_pivot(50,50)
main_imgL3c.set_angle(0)
main_imgL3c.set_pos(198, 273)
main_imgL3c.set_size(30, 132)
# Set style for main_imgL3c, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3c.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2c
main_imgL2c = lv.img(main_contMain)
main_imgL2c.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL2c.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2c.set_pivot(50,50)
main_imgL2c.set_angle(0)
main_imgL2c.set_pos(300, 146)
main_imgL2c.set_size(30, 132)
# Set style for main_imgL2c, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2c.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1c
main_imgL1c = lv.img(main_contMain)
main_imgL1c.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL1c.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1c.set_pivot(50,50)
main_imgL1c.set_angle(0)
main_imgL1c.set_pos(210, 146)
main_imgL1c.set_size(30, 132)
# Set style for main_imgL1c, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1c.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4e
main_imgL4e = lv.img(main_contMain)
main_imgL4e.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL4e.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4e.set_pivot(50,50)
main_imgL4e.set_angle(0)
main_imgL4e.set_pos(485, 284)
main_imgL4e.set_size(30, 132)
# Set style for main_imgL4e, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4e.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3e
main_imgL3e = lv.img(main_contMain)
main_imgL3e.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL3e.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3e.set_pivot(50,50)
main_imgL3e.set_angle(0)
main_imgL3e.set_pos(386, 281)
main_imgL3e.set_size(30, 132)
# Set style for main_imgL3e, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3e.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2e
main_imgL2e = lv.img(main_contMain)
main_imgL2e.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL2e.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2e.set_pivot(50,50)
main_imgL2e.set_angle(0)
main_imgL2e.set_pos(493, 149)
main_imgL2e.set_size(30, 132)
# Set style for main_imgL2e, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2e.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1e
main_imgL1e = lv.img(main_contMain)
main_imgL1e.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL1e.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1e.set_pivot(50,50)
main_imgL1e.set_angle(0)
main_imgL1e.set_pos(399, 154)
main_imgL1e.set_size(30, 132)
# Set style for main_imgL1e, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1e.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL4f
main_imgL4f = lv.img(main_contMain)
main_imgL4f.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL4f.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL4f.set_pivot(50,50)
main_imgL4f.set_angle(0)
main_imgL4f.set_pos(626, 282)
main_imgL4f.set_size(30, 132)
# Set style for main_imgL4f, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL4f.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL3f
main_imgL3f = lv.img(main_contMain)
main_imgL3f.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL3f.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL3f.set_pivot(50,50)
main_imgL3f.set_angle(0)
main_imgL3f.set_pos(532, 281)
main_imgL3f.set_size(30, 132)
# Set style for main_imgL3f, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL3f.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL2f
main_imgL2f = lv.img(main_contMain)
main_imgL2f.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL2f.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL2f.set_pivot(50,50)
main_imgL2f.set_angle(0)
main_imgL2f.set_pos(634, 151)
main_imgL2f.set_size(30, 132)
# Set style for main_imgL2f, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL2f.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create main_imgL1f
main_imgL1f = lv.img(main_contMain)
main_imgL1f.set_src("B:MicroPython/_polygon_alpha_30x132.bin")
main_imgL1f.add_flag(lv.obj.FLAG.CLICKABLE)
main_imgL1f.set_pivot(50,50)
main_imgL1f.set_angle(0)
main_imgL1f.set_pos(540, 148)
main_imgL1f.set_size(30, 132)
# Set style for main_imgL1f, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
main_imgL1f.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

main.update_layout()

def main_btnTest_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.PRESSED):
        main_lblDegree.set_style_text_font(test_font("JalnanGothicTTF", 48), 0)
        main_lblDegree.set_text("298123456789")
    if (code == lv.EVENT.RELEASED):
        main_lblDegree.set_style_text_font(test_font("JalnanGothicTTF", 48), 0)
        main_lblDegree.set_text("21")

main_btnTest.add_event_cb(lambda e: main_btnTest_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.scr_load(main)

while SDL.check():
    time.sleep_ms(5)

