/*******************************************
*	@file 		lcd1602.c
*	@author 	Panda	
*	@version	V0.0.1
*	@date		2019.12
*	@brief		lcd1602 driver source files
********************************************/

#include "lcd1602.h"


/*******************************************
*	@brief	lcd1602д����/ дָ��
*	@param	w_data:����
*	@param 	data_type
*		@arg	1: д����
*		@arg	0: дָ��
*	@retval	None
********************************************/
void lcd1602_write(uchar w_data,uchar data_type)
{	
	lcd1602_E = 0; 			// ʹ��
	lcd1602_RS = data_type;	// ѡ�� д������/ָ��
	lcd1602_RW = 0;			// ѡ��д��
	
	lcd1602_data = w_data;	 // 
	lcd1602_delay1ms(1);
	
	lcd1602_E = 1;			// д��ʱ��
	lcd1602_delay1ms(5);	// ����ʱ��	
	lcd1602_E = 0;	
}

/*******************************************
*	@brief	lcd1602д����/ дָ��
*	@param	r_data: ��ȡ������
*	@param 	data_type��
*		@arg	1��������
*		@arg	0����״̬
*	@retval	None
********************************************/
//void lcd1602_read(uchar* r_data,uchar data_type)
//{
//	uchar i = 0;
//	
//	lcd1602_E = 0;
//	lcd1602_RS = data_type;
//	lcd1602_RW = 1;
//	
//	lcd1602_E = 1;
//	
//	*r_data = lcd1602_data;
//	lcd1602_delay1ms(1);
//	
//	lcd1602_E = 0;
//}


///*******************************************
//*	@brief	lcd1602 æ״̬���
//*	@param	None
//*	@retval	1: æµ��
//*			0������
//********************************************/
//uchar lcd1602_get_busy(void)
//{
//	uchar status=0;
//	lcd1602_read(&status,LCD1602_CMD);
//	if(status&0x80)
//		return 1;
//	else 
//		return 0;
//}

/*******************************************
*	@brief	lcd1602 set cursor position
*	@param	x: x ����
*			y: y ����
*	@retval	None
********************************************/
void lcd1602_set_pos(uchar x,uchar y)
{
	lcd1602_write(0x80+(0x40*y)+x,LCD1602_CMD); //0xC0
}

/*******************************************
*	@brief	lcd1602 clear 
*	@param	None
*	@retval	None
********************************************/
void lcd1602_clear(void)
{
	lcd1602_write(0x01,LCD1602_CMD);
}

/*******************************************
*	@brief	lcd1602 show num
*	@param	num: ��ʾ������
*	@retval	None
********************************************/
void lcd1602_show_num(uchar x,uchar y,uint num)
{
	uchar i=0;
	uint temp=num;
	while(temp != 0)
	{
		temp /= 10;
		i++;
	}
	while(num != 0)
	{
		lcd1602_set_pos(x+i,y);
		lcd1602_write('0'+num%10,LCD1602_DATA);
		num /= 10;
		i--;
	}
}	


/*******************************************
*	@brief	lcd1602 show string
*	@param	x: x ����
*			y: y ����
*			str: ��ʾ�ַ����ĵ�ַ
*			mode: 
*		@arg  1: ������ʾ
*			  0: 
*	@retval	None
********************************************/
void lcd1602_show_string(uchar x,uchar y,const char* str,uchar mode)
{
	uchar i=0;
	if(mode == 1)
	{
		lcd1602_set_pos((16-strlen(str))/2,y);
	}
	else
	{
		lcd1602_set_pos(x,y);
	}
	for(i=0;i<strlen(str);i++)
	{
		lcd1602_write(*(str+i),LCD1602_DATA);
	}
}	

/*******************************************
*	@brief	lcd1602 ��ʼ��
*	@param	None
*	@retval	None
********************************************/
void lcd1602_init(void)
{
	lcd1602_write(0x38,LCD1602_CMD);	// ��������	 8λ���ݽӿ� 16*2 ������ʾ 5*7�����ַ�
	
	lcd1602_write(0x0C,LCD1602_CMD);	//����ʾ  ��겻��ʾ ����˸
	
//	lcd1602_write(0x0F,LCD1602_CMD);	//����ʾ ��ʾ���  
	
	lcd1602_write(0x06,LCD1602_CMD);	//���ݶ�д���� ���ַָ���Զ���1  ���治��
	
	lcd1602_write(0x01,LCD1602_CMD);	//����
	
	lcd1602_write(0x80,LCD1602_CMD);	//��ʼ�����ݵ�ַָ��
}



/******************************** END OF FILE **********************************/


