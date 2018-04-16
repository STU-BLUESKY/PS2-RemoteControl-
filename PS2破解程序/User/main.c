#include "stm32f10x.h"
#include "Ps2.h"
#include "beep.h" 
#include "led.h"
#include "usart.h"

void Ps2_Test(void);


u8 key;

 int main(void)
 {	
		delay_init();	    	 //��ʱ������ʼ��	  
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	  uart_init(115200);
		PS2_Init();
		BEEP_Init();	
		LED_Init();
		while(1)
		{
			LED0=0;
			Ps2_Test();//ͨ�����ڰѰ���ֵ��ӡ����
		}
 }
 
 
 void Ps2_Test(void)
{
		key = PS2_DataKey();
		if(key!=0)
    	{
				printf("  \r\n   %d  is  pressed  \r\n",key);
   	  }
     printf(" %5d %5d %5d %5d\r\n",PS2_AnologData(PSS_LX),PS2_AnologData(PSS_LY),
		                              PS2_AnologData(PSS_RX),PS2_AnologData(PSS_RY) );
    delay_ms(100);   
}






