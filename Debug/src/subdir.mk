################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/String.cpp \
../src/StringProject.cpp \
../src/TestString.cpp 

OBJS += \
./src/String.o \
./src/StringProject.o \
./src/TestString.o 

CPP_DEPS += \
./src/String.d \
./src/StringProject.d \
./src/TestString.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/ozerov/cpp_workspace/gtest-1.7.0/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


