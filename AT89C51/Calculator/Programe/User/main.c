#include "main.h"
#include "string.h"

/***********************************************************
* 	@breif    	��ʱ����
* 	@param    	nms: ��ʱ nms ����
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
	uint num = 0;
	uchar* pch = NULL;
	float result=0;
	
	lcd1602_init();

	while(1)
	{
		pch=key_getvalue();  // ��ȡ��������
		if(!strcmp(KEY_SQRT_VALUE,pch))	// ���п�������
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf,1); 	
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					num = num * 10 + (*pch) - '0';
					sprintf(calc_buf,"%s %d",KEY_SQRT_VALUE,num);				
					lcd1602_show_string(0,0,calc_buf,1); 
					//lcd1602_show_num(4,0,num);
				}
			}
			result = sqrt((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf,1);
		}			
		else if(!strcmp(KEY_LOG10_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf,1); 	
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					num = num * 10 + (*pch) - '0';
					sprintf(calc_buf,"%s %d",KEY_LOG10_VALUE,num);
					
					lcd1602_show_string(0,0,calc_buf,1); 
					//lcd1602_show_num(4,0,num);
				}
			}
			result = log10((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf,1);
		}
		else if(!strcmp(KEY_SIN_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf,1); 	
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					num = num * 10 + (*pch) - '0';
					sprintf(calc_buf,"%s %d",KEY_SIN_VALUE,num);
					
					lcd1602_show_string(0,0,calc_buf,1); 
					//lcd1602_show_num(4,0,num);
				}
			}
			result = sin((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf,1);
		}
		else if(!strcmp(KEY_COS_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf,1); 	
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					num = num * 10 + (*pch) - '0';
					sprintf(calc_buf,"%s %d",KEY_COS_VALUE,num);
					
					lcd1602_show_string(0,0,calc_buf,1); 
					//lcd1602_show_num(4,0,num);
				}
			}
			result = cos((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf,1);
		}
		else if(!strcmp(KEY_TAN_VALUE,pch))
		{
			strcpy(calc_buf,pch);
			lcd1602_show_string(0,0,calc_buf,1); 	
			while(strcmp(KEY_CALC_VALUE,pch))
			{
				pch=key_getvalue();
				if(*pch >= '0' && *pch <= '9')
				{
					num = num * 10 + (*pch) - '0';
					sprintf(calc_buf,"%s %d",KEY_TAN_VALUE,num);
					
					lcd1602_show_string(0,0,calc_buf,1); 
					//lcd1602_show_num(4,0,num);
				}
			}
			result = tan((float)num);
			sprintf(calc_buf,"%f",result);
			lcd1602_show_string(0,1,calc_buf,1);
		}		
		else if(!strcmp(KEY_CLEAR_VALUE,pch))
		{
			lcd1602_write(0x01,LCD1602_CMD);
		}	
		num = 0 ;
		memset(calc_buf,0x00,sizeof(calc_buf));
	}
}