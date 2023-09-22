################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/DIO.c \
../MCAL/GIE.c \
../MCAL/ICU.c \
../MCAL/TIMER.c \
../MCAL/USART.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/DIO.o \
./MCAL/GIE.o \
./MCAL/ICU.o \
./MCAL/TIMER.o \
./MCAL/USART.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/DIO.d \
./MCAL/GIE.d \
./MCAL/ICU.d \
./MCAL/TIMER.d \
./MCAL/USART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\embedded_tasks\RC_CAR_PROJECT\APP" -I"E:\embedded_tasks\RC_CAR_PROJECT\HAL" -I"E:\embedded_tasks\RC_CAR_PROJECT\LIB" -I"E:\embedded_tasks\RC_CAR_PROJECT\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


