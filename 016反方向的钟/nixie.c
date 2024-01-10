#include <REGX52.H>
#include "delay.h"
#define A P2_4
#define B P2_3
#define C P2_2


unsigned char nixietable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void nixie(unsigned char loc,num)
{
 	switch (loc)
{
	    case 0 :
	
		    A = 0;
		    B = 0;
		    C = 0;
		break;
		case 1 :
	    	A = 0;
	    	B = 0;
	    	C = 1;
		break;	
		case 2 :
			A = 0;
	    	B = 1;
	    	C = 0;
		break;
		case 3 :
			A = 0;
	    	B = 1;
	    	C = 1;
		break;
		case 4 :
			A = 1;
	    	B = 0;
	    	C = 0;
		break;
		case 5 :
			A = 1;
	    	B = 0;
	    	C = 1;
		break;
		case 6 :
			A = 1;
	    	B = 1;
	    	C = 0;
		break;
		case 7 :
            A = 1;
	    	B = 1;
	    	C = 1;
		break;
	
   }
	P0=nixietable[num];	
//	delay(1);
//	P0=0x00;

}

