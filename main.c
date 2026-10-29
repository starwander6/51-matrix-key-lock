#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int password = 0;//不写=0也可以 因为是全局变量
unsigned char count = 0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowNum(2,1,password,4);
	
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)  
			{
				if(count<4)
				{
					password = password*10 + KeyNum%10;
					count++;
				}
				LCD_ShowNum(2,1,password,4);
			}
			if(KeyNum == 11)
			{
				password = 0;
				count = 0;
				LCD_ShowNum(2,1,password,4);
			}
			if(KeyNum == 12)
			{
				if(count==4)
				{
					if(password==2345)
					{
						LCD_ShowString(1,12,"RIGHT");
					}
					else
					{
						LCD_ShowString(1,12,"ERROR");	
					}	
					Delay(1000);
					password = 0;
					count = 0;
					LCD_ShowNum(2,1,password,4);				
					LCD_ShowString(1,12,"     ");
				}
				else
				{
					LCD_ShowString(2,6,"not enough");
					Delay(1000);
					password = 0;
					count = 0;
					LCD_ShowNum(2,1,password,4);				
					LCD_ShowString(2,6,"          ");
				}
			}		
		}		
	}
}
