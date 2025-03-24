/**
 * @file tim.h
 *
 */

#ifndef __TIM_H__
#define __TIM_H__

/*********************
 *      INCLUDES
 *********************/

#include "main.h"

/*********************
 *      DEFINES
 *********************/

extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim1;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void x35_TIM4_init();
void x35_TIM2_init();
void x35_TIM1_Init();

#endif
