################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/oreille/Oreille.cpp 

CPP_DEPS += \
./src/oreille/Oreille.d 

OBJS += \
./src/oreille/Oreille.o 


# Each subdirectory must supply rules for building sources it contributes
src/oreille/%.o: ../src/oreille/%.cpp src/oreille/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-oreille

clean-src-2f-oreille:
	-$(RM) ./src/oreille/Oreille.d ./src/oreille/Oreille.o

.PHONY: clean-src-2f-oreille

