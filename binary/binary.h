#ifndef BINARY_H__
#define BINARY_H__

#if defined(STM32F407xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F030x6)
#include "stm32f0xx_hal.h"
#else
  #error "module lib for MCU not support"
#endif

#define BIT(bit) (1<<bit)

#define BITSET(byte, bit) (byte|= (BIT(bit))
#define BITCLR(byte, bit) (byte &= ~BIT(bit)

#define GETBIT(byte, bit) ((byte & BIT(bit)) > 0)
#define ISSETBIT(byte, bit) (GETBIT(byte, bit))
#define ISCLRBIT(byte, bit) ((byte & BIT(bit)) == 0)

#define SWAP2BYTE(data) (((data << 8) & 0xFF00) + ((data >> 8) & 0x00FF))
#define SWAP4BYTE(data) (((data << 24) & 0xFF000000) + ((data << 8) & 0x00FF0000) + ((data >> 8) & 0x0000FF00) + ((data >> 24) & 0x000000FF))

#endif