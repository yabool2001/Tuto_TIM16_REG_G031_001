################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../my_drivers/Src/my_tims.c 

OBJS += \
./my_drivers/Src/my_tims.o 

C_DEPS += \
./my_drivers/Src/my_tims.d 


# Each subdirectory must supply rules for building sources it contributes
my_drivers/Src/%.o my_drivers/Src/%.su my_drivers/Src/%.cyclo: ../my_drivers/Src/%.c my_drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32G0 -DSTM32G031K8Tx -c -I../Inc -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/CMSIS/Include" -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/CMSIS/Device/ST/STM32G0xx/Include" -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/my_drivers" -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/my_drivers/Inc" -I"C:/Users/mzeml/embedded/Tuto_TIM16_REG_G031_001/my_drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-my_drivers-2f-Src

clean-my_drivers-2f-Src:
	-$(RM) ./my_drivers/Src/my_tims.cyclo ./my_drivers/Src/my_tims.d ./my_drivers/Src/my_tims.o ./my_drivers/Src/my_tims.su

.PHONY: clean-my_drivers-2f-Src

