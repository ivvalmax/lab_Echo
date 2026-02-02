#include "../inc/rgbLed.h"

RGBLed_t led = {.r = 0, .g = 0, .b = 0};

void rgbLedInit(void)
{
  DDRE = (1<<PE3)|(1<<PE4)|(1<<PE5);
}

