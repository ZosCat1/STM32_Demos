#include <sys.h>
#include "delay.h"
#include "usart.h"	 
#include "oled.h"
#include "bmp.h"
#include "LED.h"






// 自定义OLED 坐标系如下: 【构建OLED 直角坐标系， x,y轴反置 方便函数运算】
   //   Y取值可能为0-6若发现不对的情况下
//		  ↑y
//		  |
//	  64--------------------------
//			|	                       | 
//			|		                     |
//			|		                     |
//			|		                     | 
//			|		                     |
//			|		                     |
//		(0,0)----------------------→x  
//							128





 int main(void)
 {	 
u8 i,j;
NVIC_Configuration();
delay_init();	 
LED_Init();	  
uart_init(115200);	
OLED_Init()	;
OLED_Clear();
LED_on();
delay_ms(100);//oled 上电复位
wenandisplay();	 
	while(1)
	{

	}
 }