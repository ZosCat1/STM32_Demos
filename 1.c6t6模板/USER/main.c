#include <sys.h>
#include "LED.h"
#include "delay.h"
int main(void)
{
LED_Init();
delay_init(); 
  while(1)
  {
    LED_on();
   delay_ms(50);
    LED_off();
    delay_ms(50);
  }



}

