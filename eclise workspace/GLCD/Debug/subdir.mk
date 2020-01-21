################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GLCD_2D.c \
../GLCD_characters.c \
../glcd.c \
../main.c \
../spi.c 

OBJS += \
./GLCD_2D.o \
./GLCD_characters.o \
./glcd.o \
./main.o \
./spi.o 

C_DEPS += \
./GLCD_2D.d \
./GLCD_characters.d \
./glcd.d \
./main.d \
./spi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


