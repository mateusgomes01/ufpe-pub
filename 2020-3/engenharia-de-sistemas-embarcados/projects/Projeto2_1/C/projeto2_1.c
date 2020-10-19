#include <REG51F.H>

#define RANGE 12000

sbit c1 = P2^0;
sbit c2 = P2^1;

void main(){
	char state = 0;
	char state2 = 0;
	int count = 0;
	int count2 = 0;
	bit flag = 0;
	bit flag2 = 0;
	P1 = P1 & 0x00;
	
	while(1){
		
		switch(state){
			case 0:
				if(!c1){
					flag = 1;
				}
				if(flag && c1){
					flag = 0;
					P1 = (P1 & 0xF0) | (P0 & 0x0F);
					state++;
				}
			break;
			
			case 1:
				if(count++>RANGE){
					P1 = P1 & 0xF0;
					state = 0;
					count = 0;
				}
			break;
			
			default:
				state = 0;
			break;
		}
		
		switch(state2){
			case 0:
				if(!c2){
					flag2 = 1;
				}
				if(flag2 && c2){
					flag2 = 0;
					P1 = (P1 & 0x0F) | (P0 & 0xF0);
					state2++;
				}
			break;
			
			case 1:
				if(count2++>RANGE){
					P1 = P1 & 0x0F;
					state2 = 0;
					count2 = 0;
				}
			break;
			
			default:
				state2 = 0;
			break;
		}
		
	}
	
}