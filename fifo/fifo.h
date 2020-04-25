#ifndef FIFO_H__
#define FIFO_H__

#if defined(STM32F407xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F030x6)
#include "stm32f0xx_hal.h"
#elif defined(STM32F042x6)
#include "stm32f0xx_hal.h"
#else
  #error "module for MCU not support"
#endif

typedef enum
{
  FIFO_TYPE_REWRITE,
  FIFO_TYPE_NO_REWRITE
} FifoType_t;

typedef enum
{
  FIFO_RET_OK = 0,
  FIFO_RET_ERROR,
  FIFO_RET_EMPTY,
  FIFO_RET_FULL
} FifoReturn_t;

typedef struct
{
  FifoType_t    type;
  uint8_t *     buffer;
  uint16_t      bufferLen;
  uint16_t      head;
  uint16_t      len;
} Fifo_t;

FifoReturn_t fifoClear(Fifo_t * fifo);

FifoReturn_t fifoPut(Fifo_t * fifo, uint8_t byte);
FifoReturn_t fifoGet(Fifo_t * fifo, uint8_t * byte);

FifoReturn_t fifoWrite(Fifo_t * fifo, uint8_t *data, uint8_t dataLen);
FifoReturn_t fifoRead(Fifo_t * fifo, uint8_t *data, uint8_t dataLen);

uint16_t     fifoLen(Fifo_t * fifo);

#endif