#include <REG51F.H>

sbit C1 = P2^0;
sbit C2 = P2^1;

int main(){
	
	while(1){
		if(C1 == 1){
			P1 = (P1 & 0xF0) | (P0 & 0x0F); // P1 high é mantido, or com P0L copia P0L para P1L
		}
		else {
			P0 = P0 & 0xF0;
		}
		
		if(C2 == 1){
			P1 = (P1 & 0x0F) | (P0 & 0xF0); // o mesmo que o anterior, mas copia P0H para P1H
		}
		else{
			P0 = P0 & 0x0F;
		}
	}
	
}