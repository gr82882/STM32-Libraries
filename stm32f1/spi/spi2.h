/**
 ******************************************************************************
 * @file	spi2.h
 * @author	Hampus Sandberg
 * @version	0.1
 * @date	2014-04-05
 * @brief	Manage SPI2
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SPI2_H_
#define SPI2_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Defines -------------------------------------------------------------------*/
/* Typedefs ------------------------------------------------------------------*/
/* Function prototypes -------------------------------------------------------*/
void SPI2_Init();
uint8_t SPI2_WriteRead(uint8_t Data);
void SPI2_Write(uint8_t Data);

#endif /* SPI2_H_ */
