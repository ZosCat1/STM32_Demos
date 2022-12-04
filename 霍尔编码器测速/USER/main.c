#include <sys.h>
#include "delay.h"
#include "usart.h"	 
#include "oled.h"
#include "bmp.h"
#include "LED.h"
#include "timer.h"
#include "moto.h"
#include "encoder.h"



// �Զ���OLED ����ϵ����: ������OLED ֱ������ϵ�� x,y�ᷴ�� ���㺯�����㡿

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
u8 i,j,speed;
u16 ledpwmval=0;
u8 dir=1;	
NVIC_Configuration();
delay_init();	 
LED_Init();	   
uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
OLED_Init();
moto_Init();
	 Encoder_Init_TIM4();
TIM3_Int_Init(999,7199);//time=(n1+1)*(n2+1)/72= time us
	 
	 
OLED_Clear() ;
delay_ms(100);
//wenandisplay();
LED_on(); 
TIM3_PWM2_Init(899,0);	 //����Ƶ��PWMƵ��=72000000/900=80Khz t=1/f	 
TIM3_PWM1_Init(899,0);	
moto2_foward();
moto1_foward();
	while(1)
	{
		speed=Read_Encoder(4);
		OLED_ShowNumber(0,0,speed,16,12);
		delay_ms(10);	 
		if(dir)ledpwmval++;
		else ledpwmval--;
 		if(ledpwmval>600)dir=0;
		if(ledpwmval==0)dir=1;										 
		TIM_SetCompare2(TIM3,ledpwmval);
		TIM_SetCompare1(TIM3,ledpwmval);

		
	}
 }