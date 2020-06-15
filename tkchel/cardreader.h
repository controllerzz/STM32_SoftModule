#ifndef TKCHEL_CARDREADER_H__
#define TKCHEL_CARDREADER_H__

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

#pragma pack(push,1)
typedef struct
{
  uint8_t addr;
  uint8_t func;
  uint32_t regAddr;
  uint16_t crc;
} CardReaderRequest_t;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
  uint8_t addr;
  uint8_t func;
  uint8_t len;
  uint32_t data1;
  uint32_t data0;
  uint16_t crc;
} CardReaderAnswer_t;
#pragma pack(pop)

typedef enum
{
  CARDREADER_DELAY = 0,
  CARDREADER_START,
  CARDREADER_FINISH
} CardReaderState_t;

typedef struct
{
  uint8_t addr;
  CardReaderRequest_t request;
  uint8_t head;
  CardReaderState_t state;
} CardReader_t;


CardReaderState_t CardReaderRxByte(CardReader_t * cr, uint8_t byte);


#endif