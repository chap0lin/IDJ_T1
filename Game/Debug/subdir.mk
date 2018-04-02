################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Game.cpp \
../Main.cpp \
../Music.cpp \
../Sprite.cpp \
../State.cpp 

OBJS += \
./Game.o \
./Main.o \
./Music.o \
./Sprite.o \
./State.o 

CPP_DEPS += \
./Game.d \
./Main.d \
./Music.d \
./Sprite.d \
./State.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


