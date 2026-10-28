#include <at89c51RC2.h>

sbit LCD_RS = P2^6; 
sbit LCD_RW = P2^5;
sbit LCD_E = P2^7;

//sfr LCD_DataPort = 0x80;   // 0x80 就是 P0 的地址
#define LCD_DataPort  P0

void LCD_Delay()	//@11.0592MHz  延时1ms
{
	unsigned char data i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);	
}

void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_DataPort = Command;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_DataPort = Data;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

void LCD_Init(void)
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
}

void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
}

void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)
{
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=0;String[i]!='0';i++)
	{
		LCD_WriteData(String[i]);
	}
}

int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result = 1;
	for(i=0; i<Y; i++)
	{
		Result *= X;
	}
	return Result;
}

void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length; i>0; i--)
	{
		LCD_WriteData(0x30+Number/LCD_Pow(10,i-1)%10);//0x30 <=> '0' 因为要显示的是数字呀
	}
}

//Number / LCD_Pow(10, i-1) % 10 → 取出当前位的数值 0~9。
//0x30 + ... → 转成对应 ASCII 字符码。
//LCD_WriteData(...) → 写入 DDRAM，LCD 按字符集显示出来。

void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length)
{
	unsigned char i;                                          // -32768~32767
	unsigned int Number1;
	LCD_SetCursor(Line,Column);
	if(Number>=0)
	{
		LCD_WriteData('+');
		Number1 = Number;
	}
	else
	{
		LCD_WriteData('-');//-32768  
		Number1 = -Number;//32768   会溢出回绕成 -32768
	}
	for(i=Length; i>0; i--)
	{
		LCD_WriteData(0x30+Number1/LCD_Pow(10,i-1)%10);
	}
}

void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	unsigned char SingleNumber;
	LCD_SetCursor(Line,Column);
	for(i=Length; i>0; i--)
	{	
		SingleNumber = Number/LCD_Pow(16,i-1)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData('0'+SingleNumber);
		}
		else
		{
			LCD_WriteData('A'+SingleNumber-10);
		}
	}
}

void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length; i>0; i--)
	{	
		LCD_WriteData('0'+Number/LCD_Pow(2,i-1)%2);
	}
}