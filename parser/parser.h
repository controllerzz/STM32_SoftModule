#ifndef PARSER_H__
#define PARSER_H__

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
  PARSER_TYPE_CMD_ARGS,
  PARSER_TYPE_ARGS
} ParserType_t;

typedef enum
{
  PARSER_RET_OK,
  PARSER_RET_ERROR,
  PARSER_RET_FINISH
} ParserReturn_t;

typedef enum
{
  PARSER_STOP,
  PARSER_WORK,
  PARSER_FINISH
} ParserState_t;

typedef struct
{
  ParserType_t type;
  uint8_t * buffer;
  uint16_t teil;
  uint16_t len;
  uint8_t end;
  uint8_t cmdSplit;
  uint8_t split;
  uint8_t argsLen;
  ParserState_t state;
} Parser_t;

void parserStart(Parser_t * parser);
ParserReturn_t parserPut(Parser_t * parser, uint8_t byte);
ParserReturn_t parserPuts(Parser_t * parser, uint8_t * data);
ParserState_t parserState(Parser_t * parser);
uint8_t parserHowArg(Parser_t * parser);
ParserReturn_t parserGetArg(Parser_t * parser, uint8_t num, uint8_t * arg);
uint8_t * parserGetArgPointer(Parser_t * parser, uint8_t num);

#endif
