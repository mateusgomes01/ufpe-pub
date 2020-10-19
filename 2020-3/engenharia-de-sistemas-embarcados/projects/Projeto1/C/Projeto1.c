#include <REGX51.H>
//#include <REG51F.H>

sbit P2_0 = P2^0; // P2_0 se torna o nome para identificar o bit 0 de P2

void main()
{
	// turned on LEDs
	
	P0 = 0;
	
	while(1)
	{
		if (C2 == 1)
		{
			P1H = P0H;
		} else 
		{
			P1H = 0;
		}
		
		if (C1 == 1)
		{
			P1L = P0L;
		} else 
		{
			P1L = 0;
		}
		
	}// endless loop end
	
}// main end