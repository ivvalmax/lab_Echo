#include "inc/common.h"
#include "inc/echo.h"
#include "inc/PWM.h"
#include "inc/rgbLed.h"
#include "inc/sevenSegment.h"

extern uint16_t dist;
extern RGBLed_t led;

void allInit(void);

int main(void)
{
  allInit();
  sevenSegmentClear();

  while(1)
  {
    echoTrig();
    
    sevenSegmentWrite(dist);
    PWMChange(&led, dist);

  }
}

void allInit(void)
{
  echoInit();
  PWMInit();
  rgbLedInit();
  sevenSegmentInit();

  sei();
}