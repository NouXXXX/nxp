################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lvgl/src/widgets/lv_arc.c \
../lvgl/lvgl/src/widgets/lv_bar.c \
../lvgl/lvgl/src/widgets/lv_btn.c \
../lvgl/lvgl/src/widgets/lv_btnmatrix.c \
../lvgl/lvgl/src/widgets/lv_canvas.c \
../lvgl/lvgl/src/widgets/lv_checkbox.c \
../lvgl/lvgl/src/widgets/lv_dropdown.c \
../lvgl/lvgl/src/widgets/lv_img.c \
../lvgl/lvgl/src/widgets/lv_label.c \
../lvgl/lvgl/src/widgets/lv_line.c \
../lvgl/lvgl/src/widgets/lv_objx_templ.c \
../lvgl/lvgl/src/widgets/lv_roller.c \
../lvgl/lvgl/src/widgets/lv_slider.c \
../lvgl/lvgl/src/widgets/lv_switch.c \
../lvgl/lvgl/src/widgets/lv_table.c \
../lvgl/lvgl/src/widgets/lv_textarea.c 

C_DEPS += \
./lvgl/lvgl/src/widgets/lv_arc.d \
./lvgl/lvgl/src/widgets/lv_bar.d \
./lvgl/lvgl/src/widgets/lv_btn.d \
./lvgl/lvgl/src/widgets/lv_btnmatrix.d \
./lvgl/lvgl/src/widgets/lv_canvas.d \
./lvgl/lvgl/src/widgets/lv_checkbox.d \
./lvgl/lvgl/src/widgets/lv_dropdown.d \
./lvgl/lvgl/src/widgets/lv_img.d \
./lvgl/lvgl/src/widgets/lv_label.d \
./lvgl/lvgl/src/widgets/lv_line.d \
./lvgl/lvgl/src/widgets/lv_objx_templ.d \
./lvgl/lvgl/src/widgets/lv_roller.d \
./lvgl/lvgl/src/widgets/lv_slider.d \
./lvgl/lvgl/src/widgets/lv_switch.d \
./lvgl/lvgl/src/widgets/lv_table.d \
./lvgl/lvgl/src/widgets/lv_textarea.d 

OBJS += \
./lvgl/lvgl/src/widgets/lv_arc.o \
./lvgl/lvgl/src/widgets/lv_bar.o \
./lvgl/lvgl/src/widgets/lv_btn.o \
./lvgl/lvgl/src/widgets/lv_btnmatrix.o \
./lvgl/lvgl/src/widgets/lv_canvas.o \
./lvgl/lvgl/src/widgets/lv_checkbox.o \
./lvgl/lvgl/src/widgets/lv_dropdown.o \
./lvgl/lvgl/src/widgets/lv_img.o \
./lvgl/lvgl/src/widgets/lv_label.o \
./lvgl/lvgl/src/widgets/lv_line.o \
./lvgl/lvgl/src/widgets/lv_objx_templ.o \
./lvgl/lvgl/src/widgets/lv_roller.o \
./lvgl/lvgl/src/widgets/lv_slider.o \
./lvgl/lvgl/src/widgets/lv_switch.o \
./lvgl/lvgl/src/widgets/lv_table.o \
./lvgl/lvgl/src/widgets/lv_textarea.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lvgl/src/widgets/%.o: ../lvgl/lvgl/src/widgets/%.c lvgl/lvgl/src/widgets/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\source" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\video" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\drivers" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\touchpanel" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\inc" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\font" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\font\mcufont\decoder" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLite\rtos" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLiteKernel" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLiteKernel\rtos" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl\lvgl" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl\lvgl\src" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\device" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\utilities" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\uart" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\serial_manager" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\lists" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\startup" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\xip" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\board" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\freertos\freertos-kernel\include" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\CMSIS" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\custom" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated\guider_customer_fonts" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated\guider_fonts" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\evkmimxrt1170\lvgl_examples\lvgl_guider\cm7" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-lvgl-2f-src-2f-widgets

clean-lvgl-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./lvgl/lvgl/src/widgets/lv_arc.d ./lvgl/lvgl/src/widgets/lv_arc.o ./lvgl/lvgl/src/widgets/lv_bar.d ./lvgl/lvgl/src/widgets/lv_bar.o ./lvgl/lvgl/src/widgets/lv_btn.d ./lvgl/lvgl/src/widgets/lv_btn.o ./lvgl/lvgl/src/widgets/lv_btnmatrix.d ./lvgl/lvgl/src/widgets/lv_btnmatrix.o ./lvgl/lvgl/src/widgets/lv_canvas.d ./lvgl/lvgl/src/widgets/lv_canvas.o ./lvgl/lvgl/src/widgets/lv_checkbox.d ./lvgl/lvgl/src/widgets/lv_checkbox.o ./lvgl/lvgl/src/widgets/lv_dropdown.d ./lvgl/lvgl/src/widgets/lv_dropdown.o ./lvgl/lvgl/src/widgets/lv_img.d ./lvgl/lvgl/src/widgets/lv_img.o ./lvgl/lvgl/src/widgets/lv_label.d ./lvgl/lvgl/src/widgets/lv_label.o ./lvgl/lvgl/src/widgets/lv_line.d ./lvgl/lvgl/src/widgets/lv_line.o ./lvgl/lvgl/src/widgets/lv_objx_templ.d ./lvgl/lvgl/src/widgets/lv_objx_templ.o ./lvgl/lvgl/src/widgets/lv_roller.d ./lvgl/lvgl/src/widgets/lv_roller.o ./lvgl/lvgl/src/widgets/lv_slider.d ./lvgl/lvgl/src/widgets/lv_slider.o ./lvgl/lvgl/src/widgets/lv_switch.d ./lvgl/lvgl/src/widgets/lv_switch.o ./lvgl/lvgl/src/widgets/lv_table.d ./lvgl/lvgl/src/widgets/lv_table.o ./lvgl/lvgl/src/widgets/lv_textarea.d ./lvgl/lvgl/src/widgets/lv_textarea.o

.PHONY: clean-lvgl-2f-lvgl-2f-src-2f-widgets

