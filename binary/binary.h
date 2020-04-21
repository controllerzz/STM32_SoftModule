#ifndef BINARY_H__
#define BINARY_H__

#if defined(STM32F407xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F030x6)
#include "stm32f0xx_hal.h"
#else
  #error "NRF24L01P lib for MCU not support"
#endif

#define BIT(n) (1<<n)
#define BITSET(byte, bit) (byte|= (BIT(bit))
#define BITCLR(byte, bit) (byte &= ~BIT(bit)

#endif