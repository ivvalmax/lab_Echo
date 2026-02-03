#include "../inc/echo.h"

uint16_t dist = 0;

void echoInit(void)
{
  TCCR1A = 0;
  TCCR1B = (1 << CS10);

  EIMSK |= (1 << INT7);
  EICRB |= (1 << ISC70);
  DDRE = (1 << PE6);
}

void echoTrig(void)
{
  PORTE |= (1 << PE6);

  TCNT1 = 0;
  while(111 > TCNT1);

  PORTE &= ~(1 << PE6);
}

ISR (INT7_vect)
{
  if((PINE & (1<<7)) != 0) 
  {
    TCNT1H = 0;
    TCNT1L = 0;
  }
  else 
  { 
    dist = TCNT1;
  }
  dist/=65;

}