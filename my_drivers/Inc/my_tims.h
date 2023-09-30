/*
 * my_tims.h
 *
 *  Created on: Sep 29, 2023
 *      Author: mzeml
 */

#ifndef MY_TIMS_H_
#define MY_TIMS_H_

#define G031_STD_SYS_CLOCK	(uint16_t) 16000

void config_my_tim16	( uint16_t ) ;
void start_my_tim16 	( uint16_t ) ;
void stop_my_tim16 		( void ) ;
void off_my_tim16 		( void ) ;

#endif /* MY_TIMS_H_ */
