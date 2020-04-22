################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SocketServer.cpp \
../src/html_page_2.cpp \
../src/main_prog_server.cpp 

OBJS += \
./src/SocketServer.o \
./src/html_page_2.o \
./src/main_prog_server.o 

CPP_DEPS += \
./src/SocketServer.d \
./src/html_page_2.d \
./src/main_prog_server.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


