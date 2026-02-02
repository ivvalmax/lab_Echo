#include "../inc/PWM.h"

void PWMInit(void)
{
  TCCR3A = (1<<COM3A1)|(1<<COM3B1)|(1<<COM3C1)|(1<<WGM30);
  TCCR3B = (1<<WGM32) | (1<<CS31);
  OCR3A = 0;
  OCR3B = 0;
  OCR3C = 0;
}

void PWMChange(RGBLed_t* ledPtr)
{
  OCR3AL = ledPtr->b;
  OCR3BL = ledPtr->g;
  OCR3CL = ledPtr->r;
}