#include <REGX52.H>
#include "timer0.h"
#include "delay.h"

sbit buzzer=P2^5;
#define SPEED 50
#define PO  36
#define L1  0
#define L1_ 1
#define L2  2
#define L2_ 3
#define L3  4
#define L4  5
#define L4_ 6
#define L5  7
#define L5_ 8
#define L6  9  
#define L6_ 10
#define L7  11

#define D1  12
#define D1_ 13
#define D2  14
#define D2_ 15
#define D3  16
#define D4  17
#define D4_ 18
#define D5  19
#define D5_ 20
#define D6  21  
#define D6_ 22
#define D7  23

#define H1  24
#define H1_ 25
#define H2  26
#define H2_ 27
#define H3  28
#define H4  29
#define H4_ 30
#define H5  31
#define H5_ 32
#define H6  33  
#define H6_ 34
#define H7  35






unsigned int  code freqtab[]={
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,0};


	unsigned char key,musickey;
	char  code music[]={
//		H6,4,
//		H5,4,
//		H3,4,
//		H2,4+4,	
//		D6,4,
//		D5,8,		
//		
//		PO,4,
//		D2,4,
//		D3,4,
//		D5,4+8+8,
//		
//		
//		H6,4,
//		H5,4,
//		H3,4,
//		H2,4+4,	
//		D6,4,
//		D5,4,
//		D3,4,
//		
//		PO,4,
//		D2,4,
//		D3,4,
//		D5,4,
//		D6,8+8,
//		
//		H6,4,
//		H5,4,
//		H3,4,
//		H2,4+4,	
//		D6,4,
//		D5,4,	
//		D3,4,
//		
//		PO,4,
//		D2,4,
//		D3,4,
//		D5,4+8+8,
//		
//			
//		H6,4,
//		H5,4,
//		H3,4,
//		H2,4+4,	
//		D6,4,
//		D5,4,
//		D3,4,
//		
//		PO,4,
//		D2,4,
//		D3,4,
//		D5,4,
//		D6,8+8,
//		

		PO,8+8+8+8,

		L6,4,
		L7,4,
		L6,4,
		L6,8+4,
		D3,8,
		
		L7,4,
		D1,4,
		L7,4,
		L7,8,
		D1,4,
		D2,4,
		L7,4+2,
		
		
		L6,2,
		L7,4,
		L6,2,
		L7,4,
		L6,2,
		L7,4,
		L6,2,
		L7,2+2,
		L6,2,
		L7,4,
		
		PO,8+8+8+8,
		
		
		
				
		D6,4,
		D5,4,
		D3,4,
		D2,8+4,
		D3,4,
		D1,4+4,
		
		D2,8,
		D3,4+4,
		D5,8+4,
		
		D6,4,
		D5,4,
		D3,4,
		D2,8+4,
		D3,4,
		D2,4+8,
		
		D1,4,
		D2,8,
		D1,4+8,
		
		D6,4,
		D5,4,
		D3,4,
		D2,12,
		D3,4,
		D1,4+4,
		
		D2,8,
		D3,4+4,
		D5,8+4,
		
		D6,4,
		D5,4,
		D3,4,
		D2,12,
		D3,4,
		L6,4+8+8+8,
		
		PO,8,
		
		D6,4,
		D5,4,
		D3,4,
		D2,8+4,
		D3,4,
		D1,4+4,
		
		D2,8,
		D3,4+4,
		D5,8+4,
		
		D6,4,
		D5,4,
		D3,4,
		D2,8+4,
		D3,4,
		D2,4+8,
		
		D1,4,
		D2,8,
		D1,4+8,
		
		D6,4,
		D5,4,
		D3,4,
		D2,12,
		D3,4,
		D1,4+4,
		
		D2,8,
		D3,4+4,
		D5,8+4,
		
		D6,4,
		D5,4,
		D3,4,
		D2,12,
		D3,4,
		L6,4+8+8+8,
		
		PO,8,
		
		D1,4,
		D2,4,
		D3,4,
		D6,8,
		D5,4+8,
		D3,2,
		D2,2,
		
		D1,4,
		D2,4,
		D3,4,
		D5,8,
		D6,4+4,
		H1,2,
		D7,2,
		
		H1,4,
		D6,4,
		D3,4,
		D2,4+4,
		D3,8,
		D6,4+8+8+8+8,
		
		
		PO,8+8+8+8+8+8,
		
		
		
		
		
		
		
		0xFE
	};
	
void main()
{
	
	Timer0Init();
	 
	 while(1)
{
	
	if(music[musickey]!=0xEF)
	{
		key=music[musickey];
	musickey++;
	delay(SPEED *music[musickey]);
	musickey++;
	TR0=0;
	delay(5);
	TR0=1;
	}
	else
	{
		TR0=0;
		while(1);
	}

}
}

	void timer0_routine() interrupt 1//中断器
{   
if(freqtab[key])
{
	TL0 = freqtab[key]%256;
		TH0 = freqtab[key]/256;		

			buzzer=!buzzer;
}
		

}