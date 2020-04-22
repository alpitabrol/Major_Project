################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/piHiPri.c \
../src/softPwm.c \
../src/softTone.c \
../src/wiringPi.c 

CPP_SRCS += \
../src/SocketClient.cpp \
../src/main_prog_client.cpp 

OBJS += \
./src/SocketClient.o \
./src/main_prog_client.o \
./src/piHiPri.o \
./src/softPwm.o \
./src/softTone.o \
./src/wiringPi.o 

C_DEPS += \
./src/piHiPri.d \
./src/softPwm.d \
./src/softTone.d \
./src/wiringPi.d 

CPP_DEPS += \
./src/SocketClient.d \
./src/main_prog_client.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/devil/Documents/tools/arm-bcm2708/arm-linux-gnueabihf/arm-linux-gnueabihf/include/c++/4.9.3/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/home/devil/Documents/tools/arm-bcm2708/arm-linux-gnueabihf/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


