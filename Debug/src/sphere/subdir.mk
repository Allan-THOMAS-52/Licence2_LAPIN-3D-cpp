################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/sphere/Sphere.cpp 

CPP_DEPS += \
./src/sphere/Sphere.d 

OBJS += \
./src/sphere/Sphere.o 


# Each subdirectory must supply rules for building sources it contributes
src/sphere/%.o: ../src/sphere/%.cpp src/sphere/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-sphere

clean-src-2f-sphere:
	-$(RM) ./src/sphere/Sphere.d ./src/sphere/Sphere.o

.PHONY: clean-src-2f-sphere

