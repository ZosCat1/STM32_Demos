#include <sys.h>
#include "delay.h"
#include "usart.h"	 
#include "oled.h"
#include "bmp.h"
#include "LED.h"






// �Զ���OLED ����ϵ����: ������OLED ֱ������ϵ�� x,y�ᷴ�� ���㺯�����㡿
   //   Yȡֵ����Ϊ0-6�����ֲ��Ե������
//		  ��y
//		  |
//	  64--------------------------
//			|	                       | 
//			|		                     |
//			|		                     |
//			|		                     | 
//			|		                     |
//			|		                     |
//		(0,0)----------------------��x  
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
delay_ms(100);//oled �ϵ縴λ
wenandisplay();	 
	while(1)
	{

	}
 }