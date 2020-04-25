#include "parser.h"

void parserStart(Parser_t * parser)
{
  parser->state = PARSER_WORK;
  parser->teil = 0;
  parser->argsLen = 0;
}

ParserReturn_t parserPut(Parser_t * parser, uint8_t byte)
{
  if(parser->state == PARSER_WORK)
  {
    *(parser->buffer + parser->teil++) = byte;
    if(parser->end == byte)
    {
      parser->argsLen++;
      parser->state = PARSER_FINISH;
      return PARSER_RET_FINISH;
    }
    else if(byte == parser->split)
    {
        parser->argsLen++;
    }
  }
  
  return PARSER_RET_ERROR;
}

ParserReturn_t parserPuts(Parser_t * parser, uint8_t * data)
{
  ParserReturn_t ret;
  while(*data)
  {
    ret = parserPut(parser, *data++);
  }
  return ret;
}

ParserState_t parserState(Parser_t * parser)
{
  return parser->state;
}

uint8_t parserHowArg(Parser_t * parser)
{
  if(parser->state == PARSER_FINISH)
    return parser->argsLen;
  
  return 0;
}

ParserReturn_t parserGetArg(Parser_t * parser, uint8_t num, uint8_t * arg)
{
  if(parser->state == PARSER_FINISH && parser->argsLen >= num)
  {
    uint8_t * ptr = parserGetArgPointer(parser, num);

    if(ptr == 0)
      return PARSER_RET_ERROR;

    while(*ptr != parser->split && *ptr != parser->end)
    {
      *arg++ = *ptr++;
    }
    *arg = 0;
    return PARSER_RET_OK;
  }
  
  return PARSER_RET_ERROR;
}

uint8_t * parserGetArgPointer(Parser_t * parser, uint8_t num)
{
  uint8_t * ptr = parser->buffer;
  if(parser->state == PARSER_FINISH && parser->argsLen >= num)
  {
    while(num)
    {
      if(*ptr++ == parser->split)
        num--;
    }
    return ptr;
  }
  
  return 0;
}