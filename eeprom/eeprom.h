#ifndef EEPROM_H__
#define EEPROM_H__

#if defined(STM32F407xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F030x6)
#include "stm32f0xx_hal.h"
#else
  #error "module lib for MCU not support"
#endif

typedef struct
{
  uint8_t       firstPage;
  uint8_t       secondPage;
  uint32_t      sizePage;
} Eeprom_t;

typedef enum
{
  EEPROM_OK       = 0x00U,
  EEPROM_ERROR    = 0x01U
} EepromStatusTypeDef;

EepromStatusTypeDef     EepromInit(Eeprom_t * eeprom, void * startAddress, uint16_t len);

EepromStatusTypeDef     EepromReadByte(Eeprom_t * eeprom, uint16_t addr, uint8_t * byte);
EepromStatusTypeDef     EepromReadBytes(Eeprom_t * eeprom, uint16_t addr, uint8_t * data, uint8_t size);

EepromStatusTypeDef     EepromWriteByte(Eeprom_t * eeprom, uint16_t addr, uint8_t byte);
EepromStatusTypeDef     EepromWriteBytes(Eeprom_t * eeprom, uint16_t addr, uint8_t * data, uint8_t size);

#endif
