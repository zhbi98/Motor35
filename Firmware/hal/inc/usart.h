/**
 * @file usart.h
 *
 */

#ifndef __USART_H__
#define __USART_H__

/*********************
 *      INCLUDES
 *********************/

#include "main.h"

/*********************
 *      DEFINES
 *********************/

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void x35_usart1_init();
void x35_usart2_init();

#endif /*__USART_H__*/
