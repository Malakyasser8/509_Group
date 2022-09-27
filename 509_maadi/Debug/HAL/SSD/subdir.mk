################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SSD/SSD_Prog.c 

OBJS += \
./HAL/SSD/SSD_Prog.o 

C_DEPS += \
./HAL/SSD/SSD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SSD/%.o: ../HAL/SSD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\Buzzer" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\AT24C16A" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\I2C" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\SPI" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\HC05" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\UART" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\Timer" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\LM35" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\ADC" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\Keypad" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\EXT_INT" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\LCD" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\APP\Old Projects" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\SSD" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\PB" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\APP" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\HAL\LED" -I"C:\Users\malak\Downloads\AMIT\Eclipse Files\509_maadi\MCAL\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


