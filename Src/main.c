/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32g031xx.h"

#define G031_SYS_CLOCK	16000
#define TOGGLE_LDG 		GPIOC->ODR ^= GPIO_ODR_OD6

uint8_t tim16_irq = 0 ;
uint8_t tim16_irq_0 = 0 ;
uint16_t tim16_arr = 0 ;
void ldg_init ( void ) ;
void config_tim16 ( uint16_t ) ;
void start_tim16 ( uint16_t ) ;
void tim16_off ( void ) ;
void reset_sr_uif_bit ( void ) ;

int main(void)
{
	ldg_init () ;
	tim16_irq = 0 ;
	start_tim16 ( (uint16_t) 1000 ) ;
	while  ( 1 )
	{
		if ( tim16_irq == 1 )
		{
			tim16_irq = 0 ;
			TOGGLE_LDG ;
			start_tim16 ( 1000 ) ;
		}
	}
}

void ldg_init ( void ) // LDG = PC6
{
	RCC->IOPENR 	|=  RCC_IOPENR_GPIOCEN ;
	GPIOC->MODER 	|= 	GPIO_MODER_MODE6_0 ;
	GPIOC->MODER 	&= 	~GPIO_MODER_MODE6_1 ;
	GPIOC->OTYPER 	&= 	~GPIO_OTYPER_OT6 ;
	GPIOC->OSPEEDR 	&= 	~GPIO_OSPEEDR_OSPEED6 ;
	GPIOC->PUPDR 	&= 	~GPIO_PUPDR_PUPD6 ;
}

void config_tim16 ( uint16_t sys_config) // LDG = PC6
{
	RCC->APBENR2	|= RCC_APBENR2_TIM16EN ; 	// Enable TIM16 clock
	TIM16->PSC 		= sys_config - 1 ; 			// default: 0,001 s = 1000 Hz = ( 16 000 000 Hz / 16 000 )
	//reset_sr_uif_bit () ;
	TIM16->DIER 	|= TIM_DIER_UIE ; 			// Enable interrupt generation
	NVIC_SetPriority 	( TIM16_IRQn , 0 ) ;	// Configure interrupt priority
	NVIC_EnableIRQ 		( TIM16_IRQn ) ;		// Enable interrupt
}

void start_tim16 ( uint16_t tim16_arr ) // LDG = PC6
{
	config_tim16 ( (uint16_t) G031_SYS_CLOCK ) ;
	TIM16->ARR 	=  tim16_arr - 1 ;		// default: 2 s = 2000 * 0,001s
	TIM16->CR1 	|= TIM_CR1_CEN ;		// Start count TIM16
}

void tim16_off ( void ) // Save energy and Disable TIM16 clock
{
	TIM16->SR 		&= ~TIM_SR_UIF ;			//Clean UIF Flag
	TIM16->CR1 		&= ~TIM_CR1_CEN ;			// Disable TIM16 counter
	RCC->APBENR2 	&= ~RCC_APBENR2_TIM16EN ; 	// Save energy: disable TIM16 clock
}

void reset_sr_uif_bit ( void )
{
	TIM16->CNT = (uint16_t) 0 ;
	TIM16->SR &= ~TIM_SR_UIF ;		// Clear IRQ flag
	TIM16->SR &= ~TIM_SR_CC1IF ; 	// CC1IF: Capture/Compare 1 interrupt flag
}

void TIM16_IRQHandler ( void )
{
	tim16_irq = 1 ;
	tim16_off () ;
	/*
	if ( TIM16->SR && TIM_SR_UIF && tim16_irq_0 )
	{
		tim16_irq = 1 ;
	}
	else
	{
		tim16_irq_0 = 1 ;
	}
	*/
}
