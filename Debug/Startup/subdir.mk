################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32g031k8tx.s 

OBJS += \
./Startup/startup_stm32g031k8tx.o 

S_DEPS += \
./Startup/startup_stm32g031k8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -DDEBUG -c -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/CMSIS/Include" -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/CMSIS/Device/ST/STM32G0xx/Include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32g031k8tx.d ./Startup/startup_stm32g031k8tx.o

.PHONY: clean-Startup

