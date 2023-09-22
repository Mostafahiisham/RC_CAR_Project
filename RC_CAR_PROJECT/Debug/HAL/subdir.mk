################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DC_Motor.c \
../HAL/UltraSonic.c 

OBJS += \
./HAL/DC_Motor.o \
./HAL/UltraSonic.o 

C_DEPS += \
./HAL/DC_Motor.d \
./HAL/UltraSonic.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\embedded_tasks\RC_CAR_PROJECT\APP" -I"E:\embedded_tasks\RC_CAR_PROJECT\HAL" -I"E:\embedded_tasks\RC_CAR_PROJECT\LIB" -I"E:\embedded_tasks\RC_CAR_PROJECT\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


