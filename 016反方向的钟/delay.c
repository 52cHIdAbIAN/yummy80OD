#include <INTRINS.H>

void delay(unsigned int ms)		//@11.0592MHz
{
	while (ms--)
	{

unsigned char i, j;
	i = 2;
	j = 199;
	
	do
	{
		while (--j);
	} while (--i);

}
}

//void Delay1ms()		//@11.0592MHz
//{
//	unsigned char i, j;

//	_nop_();
//	i = 2;
//	j = 199;
//	do
//	{
//		while (--j);
//	} while (--i);
//}
