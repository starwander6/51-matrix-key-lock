#include <at89c51RC2.h>
#include "Delay.h"

unsigned char MatrixKey()
{
	unsigned char MatrixKeyNum;
	P1 = 0xFF;
	P1_7 = 0;
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);MatrixKeyNum = 1;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);MatrixKeyNum = 2;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);MatrixKeyNum = 3;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);MatrixKeyNum = 4;}
	
	P1 = 0xFF;
	P1_6 = 0;
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);MatrixKeyNum = 5;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);MatrixKeyNum = 6;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);MatrixKeyNum = 7;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);MatrixKeyNum = 8;}
	
	P1 = 0xFF;
	P1_5 = 0;
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);MatrixKeyNum = 9;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);MatrixKeyNum = 10;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);MatrixKeyNum = 11;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);MatrixKeyNum = 12;}
	
	P1 = 0xFF;
	P1_4 = 0;
	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);MatrixKeyNum = 13;}
	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);MatrixKeyNum = 14;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);MatrixKeyNum = 15;}
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);MatrixKeyNum = 16;}	
	
	return MatrixKeyNum;
}
