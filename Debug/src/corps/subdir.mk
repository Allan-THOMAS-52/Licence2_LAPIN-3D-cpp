################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/corps/Corps.cpp 

CPP_DEPS += \
./src/corps/Corps.d 

OBJS += \
./src/corps/Corps.o 


# Each subdirectory must supply rules for building sources it contributes
src/corps/%.o: ../src/corps/%.cpp src/corps/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-corps

clean-src-2f-corps:
	-$(RM) ./src/corps/Corps.d ./src/corps/Corps.o

.PHONY: clean-src-2f-corps

