################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lvgl/src/misc/lv_anim.c \
../lvgl/lvgl/src/misc/lv_anim_timeline.c \
../lvgl/lvgl/src/misc/lv_area.c \
../lvgl/lvgl/src/misc/lv_async.c \
../lvgl/lvgl/src/misc/lv_bidi.c \
../lvgl/lvgl/src/misc/lv_color.c \
../lvgl/lvgl/src/misc/lv_fs.c \
../lvgl/lvgl/src/misc/lv_gc.c \
../lvgl/lvgl/src/misc/lv_ll.c \
../lvgl/lvgl/src/misc/lv_log.c \
../lvgl/lvgl/src/misc/lv_lru.c \
../lvgl/lvgl/src/misc/lv_math.c \
../lvgl/lvgl/src/misc/lv_mem.c \
../lvgl/lvgl/src/misc/lv_printf.c \
../lvgl/lvgl/src/misc/lv_style.c \
../lvgl/lvgl/src/misc/lv_style_gen.c \
../lvgl/lvgl/src/misc/lv_templ.c \
../lvgl/lvgl/src/misc/lv_timer.c \
../lvgl/lvgl/src/misc/lv_tlsf.c \
../lvgl/lvgl/src/misc/lv_txt.c \
../lvgl/lvgl/src/misc/lv_txt_ap.c \
../lvgl/lvgl/src/misc/lv_utils.c 

C_DEPS += \
./lvgl/lvgl/src/misc/lv_anim.d \
./lvgl/lvgl/src/misc/lv_anim_timeline.d \
./lvgl/lvgl/src/misc/lv_area.d \
./lvgl/lvgl/src/misc/lv_async.d \
./lvgl/lvgl/src/misc/lv_bidi.d \
./lvgl/lvgl/src/misc/lv_color.d \
./lvgl/lvgl/src/misc/lv_fs.d \
./lvgl/lvgl/src/misc/lv_gc.d \
./lvgl/lvgl/src/misc/lv_ll.d \
./lvgl/lvgl/src/misc/lv_log.d \
./lvgl/lvgl/src/misc/lv_lru.d \
./lvgl/lvgl/src/misc/lv_math.d \
./lvgl/lvgl/src/misc/lv_mem.d \
./lvgl/lvgl/src/misc/lv_printf.d \
./lvgl/lvgl/src/misc/lv_style.d \
./lvgl/lvgl/src/misc/lv_style_gen.d \
./lvgl/lvgl/src/misc/lv_templ.d \
./lvgl/lvgl/src/misc/lv_timer.d \
./lvgl/lvgl/src/misc/lv_tlsf.d \
./lvgl/lvgl/src/misc/lv_txt.d \
./lvgl/lvgl/src/misc/lv_txt_ap.d \
./lvgl/lvgl/src/misc/lv_utils.d 

OBJS += \
./lvgl/lvgl/src/misc/lv_anim.o \
./lvgl/lvgl/src/misc/lv_anim_timeline.o \
./lvgl/lvgl/src/misc/lv_area.o \
./lvgl/lvgl/src/misc/lv_async.o \
./lvgl/lvgl/src/misc/lv_bidi.o \
./lvgl/lvgl/src/misc/lv_color.o \
./lvgl/lvgl/src/misc/lv_fs.o \
./lvgl/lvgl/src/misc/lv_gc.o \
./lvgl/lvgl/src/misc/lv_ll.o \
./lvgl/lvgl/src/misc/lv_log.o \
./lvgl/lvgl/src/misc/lv_lru.o \
./lvgl/lvgl/src/misc/lv_math.o \
./lvgl/lvgl/src/misc/lv_mem.o \
./lvgl/lvgl/src/misc/lv_printf.o \
./lvgl/lvgl/src/misc/lv_style.o \
./lvgl/lvgl/src/misc/lv_style_gen.o \
./lvgl/lvgl/src/misc/lv_templ.o \
./lvgl/lvgl/src/misc/lv_timer.o \
./lvgl/lvgl/src/misc/lv_tlsf.o \
./lvgl/lvgl/src/misc/lv_txt.o \
./lvgl/lvgl/src/misc/lv_txt_ap.o \
./lvgl/lvgl/src/misc/lv_utils.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lvgl/src/misc/%.o: ../lvgl/lvgl/src/misc/%.c lvgl/lvgl/src/misc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\source" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\video" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\drivers" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\touchpanel" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\inc" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\font" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\font\mcufont\decoder" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLite\rtos" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLiteKernel" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLiteKernel\rtos" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl\lvgl" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl\lvgl\src" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\device" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\utilities" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\uart" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\serial_manager" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\lists" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\startup" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\xip" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\board" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\freertos\freertos-kernel\include" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\CMSIS" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\custom" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated\guider_customer_fonts" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated\guider_fonts" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\evkmimxrt1170\lvgl_examples\lvgl_guider\cm7" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-lvgl-2f-src-2f-misc

clean-lvgl-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./lvgl/lvgl/src/misc/lv_anim.d ./lvgl/lvgl/src/misc/lv_anim.o ./lvgl/lvgl/src/misc/lv_anim_timeline.d ./lvgl/lvgl/src/misc/lv_anim_timeline.o ./lvgl/lvgl/src/misc/lv_area.d ./lvgl/lvgl/src/misc/lv_area.o ./lvgl/lvgl/src/misc/lv_async.d ./lvgl/lvgl/src/misc/lv_async.o ./lvgl/lvgl/src/misc/lv_bidi.d ./lvgl/lvgl/src/misc/lv_bidi.o ./lvgl/lvgl/src/misc/lv_color.d ./lvgl/lvgl/src/misc/lv_color.o ./lvgl/lvgl/src/misc/lv_fs.d ./lvgl/lvgl/src/misc/lv_fs.o ./lvgl/lvgl/src/misc/lv_gc.d ./lvgl/lvgl/src/misc/lv_gc.o ./lvgl/lvgl/src/misc/lv_ll.d ./lvgl/lvgl/src/misc/lv_ll.o ./lvgl/lvgl/src/misc/lv_log.d ./lvgl/lvgl/src/misc/lv_log.o ./lvgl/lvgl/src/misc/lv_lru.d ./lvgl/lvgl/src/misc/lv_lru.o ./lvgl/lvgl/src/misc/lv_math.d ./lvgl/lvgl/src/misc/lv_math.o ./lvgl/lvgl/src/misc/lv_mem.d ./lvgl/lvgl/src/misc/lv_mem.o ./lvgl/lvgl/src/misc/lv_printf.d ./lvgl/lvgl/src/misc/lv_printf.o ./lvgl/lvgl/src/misc/lv_style.d ./lvgl/lvgl/src/misc/lv_style.o ./lvgl/lvgl/src/misc/lv_style_gen.d ./lvgl/lvgl/src/misc/lv_style_gen.o ./lvgl/lvgl/src/misc/lv_templ.d ./lvgl/lvgl/src/misc/lv_templ.o ./lvgl/lvgl/src/misc/lv_timer.d ./lvgl/lvgl/src/misc/lv_timer.o ./lvgl/lvgl/src/misc/lv_tlsf.d ./lvgl/lvgl/src/misc/lv_tlsf.o ./lvgl/lvgl/src/misc/lv_txt.d ./lvgl/lvgl/src/misc/lv_txt.o ./lvgl/lvgl/src/misc/lv_txt_ap.d ./lvgl/lvgl/src/misc/lv_txt_ap.o ./lvgl/lvgl/src/misc/lv_utils.d ./lvgl/lvgl/src/misc/lv_utils.o

.PHONY: clean-lvgl-2f-lvgl-2f-src-2f-misc

