#ifndef CRC16_H__
#define CRC16_H__

#if defined(STM32F407xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F030x6)
#include "stm32f0xx_hal.h"
#elif defined(STM32F042x6)
#include "stm32f0xx_hal.h"
#elif defined(STM32F103xE)
#include "stm32f1xx_hal.h"
#else
  #error "module for MCU not support"
#endif

uint16_t calculateCrc16 (const uint8_t *nData, uint16_t wLength);

#endif
