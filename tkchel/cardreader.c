#include "cardreader.h"

CardReaderState_t CardReaderRxByte(CardReader_t * cr, uint8_t byte)
{
  switch(cr->state)
  {
  case CARDREADER_FINISH:
      cr->state = CARDREADER_DELAY;
  case CARDREADER_DELAY:
    if(byte == cr->addr){
      cr->state = CARDREADER_START;
      cr->request.addr = byte;
      cr->head = 1;
    }
    break;
    
  case CARDREADER_START:
    ((uint8_t *) &cr->request)[cr->head++] = byte;
    
    if(cr->head >= sizeof(CardReaderRequest_t)){
      cr->state = CARDREADER_FINISH;
    }
    break;

  default:
    cr->state = CARDREADER_DELAY;
  }
  
  return cr->state;
}
