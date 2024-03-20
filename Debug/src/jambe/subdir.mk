################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/jambe/Jambe.cpp 

CPP_DEPS += \
./src/jambe/Jambe.d 

OBJS += \
./src/jambe/Jambe.o 


# Each subdirectory must supply rules for building sources it contributes
src/jambe/%.o: ../src/jambe/%.cpp src/jambe/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-jambe

clean-src-2f-jambe:
	-$(RM) ./src/jambe/Jambe.d ./src/jambe/Jambe.o

.PHONY: clean-src-2f-jambe

