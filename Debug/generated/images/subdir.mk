################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generated/images/_cloudN_alpha_100x100.c \
../generated/images/_cloudSunN_alpha_100x100.c \
../generated/images/_cloudSun_alpha_100x100.c \
../generated/images/_cloud_alpha_100x100.c \
../generated/images/_connect_alpha_48x48.c \
../generated/images/_connected_alpha_48x48.c \
../generated/images/_half_dome_alpha_720x1224.c \
../generated/images/_polygon2_alpha_97x20.c \
../generated/images/_polygon_alpha_30x132.c \
../generated/images/_rainN_alpha_100x100.c \
../generated/images/_rain_alpha_100x100.c \
../generated/images/_round_alpha_30x130.c \
../generated/images/_setting_alpha_48x48.c \
../generated/images/_snowN_alpha_100x100.c \
../generated/images/_snow_alpha_100x100.c \
../generated/images/_sunN_alpha_100x100.c \
../generated/images/_sun_alpha_100x100.c \
../generated/images/_thunderN_alpha_100x100.c \
../generated/images/_thunder_alpha_100x100.c \
../generated/images/_timeNot_alpha_48x48.c \
../generated/images/_time_alpha_48x48.c \
../generated/images/images.c 

C_DEPS += \
./generated/images/_cloudN_alpha_100x100.d \
./generated/images/_cloudSunN_alpha_100x100.d \
./generated/images/_cloudSun_alpha_100x100.d \
./generated/images/_cloud_alpha_100x100.d \
./generated/images/_connect_alpha_48x48.d \
./generated/images/_connected_alpha_48x48.d \
./generated/images/_half_dome_alpha_720x1224.d \
./generated/images/_polygon2_alpha_97x20.d \
./generated/images/_polygon_alpha_30x132.d \
./generated/images/_rainN_alpha_100x100.d \
./generated/images/_rain_alpha_100x100.d \
./generated/images/_round_alpha_30x130.d \
./generated/images/_setting_alpha_48x48.d \
./generated/images/_snowN_alpha_100x100.d \
./generated/images/_snow_alpha_100x100.d \
./generated/images/_sunN_alpha_100x100.d \
./generated/images/_sun_alpha_100x100.d \
./generated/images/_thunderN_alpha_100x100.d \
./generated/images/_thunder_alpha_100x100.d \
./generated/images/_timeNot_alpha_48x48.d \
./generated/images/_time_alpha_48x48.d \
./generated/images/images.d 

OBJS += \
./generated/images/_cloudN_alpha_100x100.o \
./generated/images/_cloudSunN_alpha_100x100.o \
./generated/images/_cloudSun_alpha_100x100.o \
./generated/images/_cloud_alpha_100x100.o \
./generated/images/_connect_alpha_48x48.o \
./generated/images/_connected_alpha_48x48.o \
./generated/images/_half_dome_alpha_720x1224.o \
./generated/images/_polygon2_alpha_97x20.o \
./generated/images/_polygon_alpha_30x132.o \
./generated/images/_rainN_alpha_100x100.o \
./generated/images/_rain_alpha_100x100.o \
./generated/images/_round_alpha_30x130.o \
./generated/images/_setting_alpha_48x48.o \
./generated/images/_snowN_alpha_100x100.o \
./generated/images/_snow_alpha_100x100.o \
./generated/images/_sunN_alpha_100x100.o \
./generated/images/_sun_alpha_100x100.o \
./generated/images/_thunderN_alpha_100x100.o \
./generated/images/_thunder_alpha_100x100.o \
./generated/images/_timeNot_alpha_48x48.o \
./generated/images/_time_alpha_48x48.o \
./generated/images/images.o 


# Each subdirectory must supply rules for building sources it contributes
generated/images/%.o: ../generated/images/%.c generated/images/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\source" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\video" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\drivers" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\touchpanel" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\inc" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\font" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\font\mcufont\decoder" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLite\rtos" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLiteKernel" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\vglite\VGLiteKernel\rtos" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl\lvgl" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl\lvgl\src" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\lvgl" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\device" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\utilities" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\uart" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\serial_manager" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\component\lists" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\startup" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\xip" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\board" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\freertos\freertos-kernel\include" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\CMSIS" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\custom" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated\guider_customer_fonts" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\generated\guider_fonts" -I"C:\gui-guider-tutorial\evkmimxrt1170_lvgl_guider_cm7\evkmimxrt1170\lvgl_examples\lvgl_guider\cm7" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-generated-2f-images

clean-generated-2f-images:
	-$(RM) ./generated/images/_cloudN_alpha_100x100.d ./generated/images/_cloudN_alpha_100x100.o ./generated/images/_cloudSunN_alpha_100x100.d ./generated/images/_cloudSunN_alpha_100x100.o ./generated/images/_cloudSun_alpha_100x100.d ./generated/images/_cloudSun_alpha_100x100.o ./generated/images/_cloud_alpha_100x100.d ./generated/images/_cloud_alpha_100x100.o ./generated/images/_connect_alpha_48x48.d ./generated/images/_connect_alpha_48x48.o ./generated/images/_connected_alpha_48x48.d ./generated/images/_connected_alpha_48x48.o ./generated/images/_half_dome_alpha_720x1224.d ./generated/images/_half_dome_alpha_720x1224.o ./generated/images/_polygon2_alpha_97x20.d ./generated/images/_polygon2_alpha_97x20.o ./generated/images/_polygon_alpha_30x132.d ./generated/images/_polygon_alpha_30x132.o ./generated/images/_rainN_alpha_100x100.d ./generated/images/_rainN_alpha_100x100.o ./generated/images/_rain_alpha_100x100.d ./generated/images/_rain_alpha_100x100.o ./generated/images/_round_alpha_30x130.d ./generated/images/_round_alpha_30x130.o ./generated/images/_setting_alpha_48x48.d ./generated/images/_setting_alpha_48x48.o ./generated/images/_snowN_alpha_100x100.d ./generated/images/_snowN_alpha_100x100.o ./generated/images/_snow_alpha_100x100.d ./generated/images/_snow_alpha_100x100.o ./generated/images/_sunN_alpha_100x100.d ./generated/images/_sunN_alpha_100x100.o ./generated/images/_sun_alpha_100x100.d ./generated/images/_sun_alpha_100x100.o ./generated/images/_thunderN_alpha_100x100.d ./generated/images/_thunderN_alpha_100x100.o ./generated/images/_thunder_alpha_100x100.d ./generated/images/_thunder_alpha_100x100.o ./generated/images/_timeNot_alpha_48x48.d ./generated/images/_timeNot_alpha_48x48.o ./generated/images/_time_alpha_48x48.d ./generated/images/_time_alpha_48x48.o ./generated/images/images.d ./generated/images/images.o

.PHONY: clean-generated-2f-images

