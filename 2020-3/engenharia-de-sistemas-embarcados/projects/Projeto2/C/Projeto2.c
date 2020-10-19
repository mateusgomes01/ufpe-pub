#include <REG51F.H>

sbit C1 = P2^0;
sbit C2 = P2^1;

void delay(int sec)
{
int count=0;
 while(count<=16*sec) // sec = number of seconds of delay
  {
   TMOD=0x01;  // 16-bit timer0 selected
   TH0=0x1F;   // Loading high byte in TH
   TL0=0x00;   // Loaded low byte in TL
   TR0=1;      // Running the timer
    while(!TF0);   //Checking the timer flag register if it is not equal to 1 
   TR0 = 0;      // If TF0=1 stop the timer
   TF0 = 0;      // Clear the Timer Flag bit for next calculation

   count++;
  }
}

void main(){
	
	int C1a = C1; // C1a is the old C1
	int C2a = C2; // C2a is the old C2
	
	while(1){
		if(C1 == 1 && C1 != C1a){ // 
			P1 = (P1 & 0xF0) | (P0 & 0x0F); // P1 high é mantido, or com P0L copia P0L para P1L
		}
		else {
			delay(1);
			P0 = P0 & 0xF0;
		}
		
		if(C2 == 1 && C2 != C2a){ // 
			P1 = (P1 & 0x0F) | (P0 & 0xF0); // o mesmo que o anterior, mas copia P0H para P1H
		}
		else{
			delay(1);
			P0 = P0 & 0x0F;
		}
		
		C1a = C1;
		C2a = C2;
	}
	
}