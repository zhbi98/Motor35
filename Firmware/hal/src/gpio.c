/**
 * For example, when the official PWM 
 * peripheral initialization function is called, 
 * the initialization function will check 
 * whether the corresponding named MSP 
 * function exists, and if it exists, it will 
 * be called.
 * Therefore, for MCU firmware libraries that 
 * do not support this feature, they can 
 * implement a similar mechanism by 
 * themselves.
 */

/**
 * @file gpio.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "stm32f1xx_hal.h"
#include "gpio.h"

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initializes the GPIOx peripheral according to the specified parameters in the GPIO_Init.
 * @param GPIOx where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
 */
void x35_gpio_init()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*GPIO Ports Clock Enable*/
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*Configure GPIO pin Output Level*/
    /*HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);*/

    /*Configure GPIO pin Output Level*/
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);

    /*Configure GPIO pin : LED 0*/
    /*GPIO_InitStruct.Pin = GPIO_PIN_12;*/
    /*GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;*/
    /*GPIO_InitStruct.Pull = GPIO_PULLUP;*/
    /*GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;*/
    /*HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);*/

    /*Configure GPIO pin : LED 1*/
    /*GPIO_InitStruct.Pin = GPIO_PIN_1;*/
    /*GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;*/
    /*GPIO_InitStruct.Pull = GPIO_PULLUP;*/
    /*GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;*/
    /*HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);*/

    /*Configure GPIO pin : KEY 0*/
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Enable the Serial wire JTAG configuration
    NOJTAG: JTAG-DP Disabled and SW-DP Enabled*/
    __HAL_RCC_AFIO_CLK_ENABLE();
    __HAL_AFIO_REMAP_SWJ_NOJTAG();

    /*PB3 is used for Jlink JTDO purposes*/

    /*Configure GPIO pin : KEY 1*/
    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pin : RS485 Receive Enable Pin*/
    /*GPIO_InitStruct.Pin = GPIO_PIN_8;*/
    /*GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;*/
    /*GPIO_InitStruct.Pull = GPIO_PULLUP;*/
    /*GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;*/
    /*HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);*/


    /*Configure GPIO pin : TJA1051T CAN Silent Pin*/
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : SPI1 cs Pin*/
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


    /*Configure GPIO pin : TB67 Am Pin*/
    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : TB67 Ap Pin*/
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : TB67 Bm Pin*/
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pin : TB67 Bp Pin*/
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*EXTI interrupt init*/
}
