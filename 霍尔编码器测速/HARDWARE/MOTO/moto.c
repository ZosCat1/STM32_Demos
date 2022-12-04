#include "moto.h"


void moto_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;			
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
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