#include "main.h"
#include "string.h"

/***********************************************************
* 	@breif    	��ʱ��������ʱ1ms
* 	@param    	c
*	@retval		None
* 	@note		�ú�������12MHZ�����£�12��Ƶ��Ƭ������ʱ��
************************************************************/
void delay_ms(uint nms)
{
	uchar i=0,j=0;
	for (; nms>0; nms--)
	{
		 for (i=199;i>0;i--)
		 {
		  	for(j=1;j>0;j--);
		 }      
	}
}


uchar calc_buf[50]={0};

int main(void)
{
	uchar i=0;
	uchar temp = 0;
	uint num = 0;
	uchar* pch = NULL;
	float result=0;
	lcd1602_init();

	while(1)
	{
		pch=key_getvalue();

		if(!strcmp(KEY_SQRT_VALUE,pch))	// ���п�������
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf); 	
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					lcd1602_set_pos(0,1);
					num = num * 10 + (*pch) - '0';
					lcd1602_show_num(4,0,num);
				}
			}
			result = sqrt(num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf);
		}			
		else if(!strcmp(KEY_LOG10_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf);
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					lcd1602_set_pos(0,1);
					num = num * 10 + (*pch) - '0';
					lcd1602_show_num(4,0,num);
				}
			}
			result = log10(num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf);
		}
		else if(!strcmp(KEY_SIN_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf);
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					lcd1602_set_pos(0,1);
					num = num * 10 + (*pch) - '0';
					lcd1602_show_num(4,0,num);
				}
			}
			result = sin((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf);
		}
		else if(!strcmp(KEY_COS_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf);
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					lcd1602_set_pos(0,1);
					num = num * 10 + (*pch) - '0';
					lcd1602_show_num(4,0,num);
				}
			}
			result = cos((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf);
		}
		else if(!strcmp(KEY_TAN_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf);
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					lcd1602_set_pos(0,1);
					num = num * 10 + (*pch) - '0';
					lcd1602_show_num(4,0,num);
				}
			}
			result = tan((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf);
		}		
		else if(!strcmp(KEY_CLEAR_VALUE,pch))
		{
			lcd1602_write(0x01,LCD1602_CMD);
		}	
		num = 0 ;
		
//		lcd1602_show_string(0,0,(const char*)formula_buf);

	}
}