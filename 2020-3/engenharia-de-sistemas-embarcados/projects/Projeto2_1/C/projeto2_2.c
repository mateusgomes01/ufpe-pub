#include <REG51F.H>



unsigned int cont1Sec = 30000;

int main(){

	static unsigned char state = 2;
	static unsigned int contador = 2;

	while(1){

		switch(state_b0)
		{
			case 0:
			if(P2 & 0x01){
				P1 = // ...
				contador = 0;
				state = 1;
			}

			case 1:
			if( contador++ == cont1Sec){
				P1 = // ...
				state = 2;
			}

			case 2:
			if( (P2 & 0x01) == 0){
				state = 0;
			}

			default:
		}
	}

}