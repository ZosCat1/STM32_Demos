#include <sys.h>
#include "delay.h"
#include "usart.h"	 
#include "oled.h"
#include "bmp.h"
#include "LED.h"
#include "adc.h"





// 自定义OLED 坐标系如下: 【构建OLED 直角坐标系， x,y轴反置 方便函数运算】
//		 
//		                               128   
//	 (0,0)--------------------------→x
//			|	                      
//			|		                     
//			|		                     
//			|		                      
//			|		                     
//			|		              
//		 64
//			 y				




 int main(void)
 {	 
  u16 adcx;
	float temp;	 
u8 i,j;
NVIC_Configuration();
delay_init();	 
LED_Init();	  
uart_init(115200);	
OLED_Init()	;
Adc_Init();	 
OLED_Set_Pos(0,0);
OLED_Clear();
LED_on();
delay_ms(100);//oled 上电复位
//wenandisplay();
	OLED_ShowString(0,0,"ADC_0_VAL:",10);	
	 OLED_ShowString(0,4,"ADC_0_VOL:",10);	 
	while(1)
	{	 

adcx=Get_Adc_Average(ADC_Channel_1,10);
		OLED_Float(1,0,adcx,3);//显示ADC的值
		temp=(float)adcx*(3.3/4096);
OLED_Float(5,0,temp,3);
		delay_ms(250);	
	}
 }