/*
 * my_tims.c
 *
 *  Created on: Sep 29, 2023
 *      Author: mzeml
 */

#include "stm32g031xx.h"
#include "my_tims.h"

void config_my_tim16 ( uint32_t my_tim_clock )
{
	RCC->APBENR2		|= RCC_APBENR2_TIM16EN ; 	// Enable TIM16 clock
	TIM16->PSC 			= (uint16_t) ( my_tim_clock / 1000 ) - 1 ; // default: 0,001 s = 1000 Hz = ( 16 000 000 Hz / 16 000 )
	TIM16->EGR			|= TIM_EGR_UG ; 			// Force EGR.UG update
	TIM16->SR 			&= ~TIM_SR_UIF ;			//Clean UIF Flag
	TIM16->DIER 		|= TIM_DIER_UIE ; 			// Enable interrupt generation
	NVIC_SetPriority 	( TIM16_IRQn , 0 ) ;		// Configure interrupt priority
	NVIC_EnableIRQ 		( TIM16_IRQn ) ;			// Enable interrupt
}

void start_my_tim16 ( uint16_t my_tim16_arr )
{
	RCC->APBENR2	|= RCC_APBENR2_TIM16EN ; 	// Enable TIM16 clock
	TIM16->ARR 		=  my_tim16_arr - 1 ;	// default: 2 s = 2000 * 0,001s
	TIM16->CR1 		|= TIM_CR1_CEN ;		// Start counting TIM16
}

void stop_my_tim16 ()
{
	TIM16->SR 	&= ~TIM_SR_UIF ;		//Clean UIF Flag
	TIM16->CR1 	&= ~TIM_CR1_CEN ;		// Stop counting TIM16
}

void off_my_tim16 () // Save energy and Disable TIM16 clock
{
	stop_my_tim16 () ;
	RCC->APBENR2 	&= ~RCC_APBENR2_TIM16EN ; 	// Save energy: disable TIM16 clock
}

