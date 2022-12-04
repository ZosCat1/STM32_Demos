#include "moto.h"


void moto_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;			
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);						

}
 

void moto1_foward()
{
GPIO_SetBits(GPIOA,GPIO_Pin_0);
GPIO_ResetBits(GPIOA,GPIO_Pin_1);

}

void moto1_back()
{
GPIO_SetBits(GPIOA,GPIO_Pin_1);
GPIO_ResetBits(GPIOA,GPIO_Pin_0);

}
void moto2_foward()
{
GPIO_SetBits(GPIOA,GPIO_Pin_2);
GPIO_ResetBits(GPIOA,GPIO_Pin_3);

}

void moto2_back()
{
GPIO_SetBits(GPIOA,GPIO_Pin_3);
GPIO_ResetBits(GPIOA,GPIO_Pin_2);

}