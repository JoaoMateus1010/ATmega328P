#include <asf.h>
volatile unsigned int controle;
unsigned int count =0;
unsigned int state =0;
unsigned int Bflag =0;
volatile unsigned int Tflag =0;
unsigned int valEsq = 0;
unsigned int valDir = 0;
unsigned int toggleFlagAvisoPedestre = 0;
unsigned int flagDisplayToggle = 0;
void DISPLAY_LIGA_NUM(unsigned int num);
void UP_LP(){
	PORTC |= 1<<PORTC2;
}
void clsSEM1(){
	PORTB &= ~(1<<0);
	PORTB &= ~(1<<1);
	PORTB &= ~(1<<2);
}
void clsSEM2(){
	PORTB &= ~(1<<3);
	PORTB &= ~(1<<4);
	PORTB &= ~(1<<5);
}
/*
Descrição da função DISPLAY_AVISO
Parametros:
0 - Escreve P
1 - Escreve A
2 - Escreve r
3 - Escreve E
*/
void DISPLAY_AVISO(unsigned int key){
	switch(key){
		case 0:
		PORTD |= (1<<PORTD0);
		PORTD |= (1<<PORTD1);
		PORTD &= ~(1<<PORTD3);
		PORTD &= ~(1<<PORTD4);
		PORTD |= (1<<PORTD5);
		PORTD |= (1<<PORTD6);
		PORTD |= (1<<PORTD7);
		break;
		case 1:
		PORTD |= (1<<PORTD0);
		PORTD |= (1<<PORTD1);
		PORTD |= (1<<PORTD3);
		PORTD &= ~(1<<PORTD4);
		PORTD |= (1<<PORTD5);
		PORTD |= (1<<PORTD6);
		PORTD |= (1<<PORTD7);
		break;
		case 2:
		PORTD &= ~(1<<PORTD0);
		PORTD &= ~(1<<PORTD1);
		PORTD &= ~(1<<PORTD3);
		PORTD &= ~(1<<PORTD4);
		PORTD |= (1<<PORTD5);
		PORTD &= ~(1<<PORTD6);
		PORTD |= (1<<PORTD7);
		break;
		case 3:
		PORTD |= (1<<PORTD0);
		PORTD &= ~(1<<PORTD1);
		PORTD &= ~(1<<PORTD3);
		PORTD |= (1<<PORTD4);
		PORTD |= (1<<PORTD5);
		PORTD |= (1<<PORTD6);
		PORTD |= (1<<PORTD7);
		break;
	}
}
void DISPLAY_LIGA_NUM(unsigned int num){	
	switch(num){
		case 0:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD4);
			PORTD |= (1<<PORTD5);
			PORTD |= (1<<PORTD6);
			PORTD &= ~(1<<PORTD7);			
		break;	
		case 1:
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD &= ~(1<<PORTD0);
			PORTD &= ~(1<<PORTD4);
			PORTD &= ~(1<<PORTD5);
			PORTD &= ~(1<<PORTD6);
			PORTD &= ~(1<<PORTD7);			
		break;
		case 2:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD7);
			PORTD |= (1<<PORTD5);
			PORTD |= (1<<PORTD4);
			PORTD &= ~(1<<PORTD3);			
			PORTD &= ~(1<<PORTD6);	
		break;
		case 3:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD4);
			PORTD |= (1<<PORTD7);
			PORTD &= ~(1<<PORTD5);
			PORTD &= ~(1<<PORTD6);
		break;
		case 4:
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD6);
			PORTD |= (1<<PORTD7);
			PORTD &= ~(1<<PORTD4);
			PORTD &= ~(1<<PORTD5);
			PORTD &= ~(1<<PORTD0);
		break;
		case 5:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD6);
			PORTD |= (1<<PORTD7);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD4);
			PORTD &= ~(1<<PORTD1);
			PORTD &= ~(1<<PORTD5);
		break;
		case 6:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD6);
			PORTD |= (1<<PORTD5);
			PORTD |= (1<<PORTD4);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD7);
			PORTD &= ~(1<<PORTD1);
		break;
		case 7:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD &= ~(1<<PORTD4);
			PORTD &= ~(1<<PORTD5);
			PORTD &= ~(1<<PORTD6);
			PORTD &= ~(1<<PORTD7);
		break;
		case 8:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD4);
			PORTD |= (1<<PORTD5);
			PORTD |= (1<<PORTD6);
			PORTD |= (1<<PORTD7);
		break;
		case 9:
			PORTD |= (1<<PORTD0);
			PORTD |= (1<<PORTD1);
			PORTD |= (1<<PORTD3);
			PORTD |= (1<<PORTD4);			
			PORTD |= (1<<PORTD6);
			PORTD |= (1<<PORTD7);
			PORTD &= ~(1<<PORTD5);			
		break;
		default:
			PORTD |= (1<<PORTD7);
		break;
	}	
}
int main (void){		
	board_init();		
	controle=3;
	while (1){		
		if(controle==3){
			controle=0;								
			if(count<8){
				state=0;
			}
			if((count>7)&&(count<10)){
				state=1;
			}
			if(count==10){
				state=2;
			}
			if((count>10)&&(count<19)){
				state=3;
			}
			if((count>18)&&(count<21)){
				state=4;
			}
			if(count==21){
				state=5;				
			}
			if(state==2 || state==5){
				if(state==2){
					if(Bflag==0){
						count++;
					}
				}else{
					if(Bflag==0){
						count=0;
					}
				}					
			}else{
				count++;
			}									
			if(flagDisplayToggle==0){
				if(toggleFlagAvisoPedestre==0){
					DISPLAY_AVISO(1);
					PORTC &= ~(1<<PORTC1);
					PORTC |= (1<<PORTC0);
					for(int i=0;i<30000;i++){}
					DISPLAY_AVISO(0);
					PORTC &= ~(1<<PORTC0);
					PORTC |= (1<<PORTC1);
					for(int i=0;i<30000;i++){}
					toggleFlagAvisoPedestre=1;
					}else{
					DISPLAY_AVISO(3);
					PORTC &= ~(1<<PORTC1);
					PORTC |= (1<<PORTC0);
					for(int i=0;i<30000;i++){}
					DISPLAY_AVISO(2);
					PORTC &= ~(1<<PORTC0);
					PORTC |= (1<<PORTC1);
					for(int i=0;i<30000;i++){}
					toggleFlagAvisoPedestre=0;
				}
			}
			switch(state){
				case 0:
					PORTB |= 1<<0;
					PORTB &= ~(1<<1);
					PORTB &= ~(1<<2);
					PORTB &= ~(1<<3);
					PORTB &= ~(1<<4);
					PORTB |= 1<<5;					
					PORTC |= (1<<PORTC2);
				break;
				case 1:
					PORTB |= 1<<0;
					PORTB &= ~(1<<1);
					PORTB &= ~(1<<2);
					PORTB &= ~(1<<3);
					PORTB |= 1<<4;
					PORTB &= ~(1<<5);					
					PORTC |= (1<<PORTC2);					
				break;
				case 2:
				PORTB |= 1<<0;
				PORTB &= ~(1<<1);
				PORTB &= ~(1<<2);
				PORTB &= ~(1<<3);
				PORTB |= 1<<4;
				PORTB &= ~(1<<5);
					if(Bflag==1){
						flagDisplayToggle = 1;
						PORTB |= 1<<0;
						PORTB |= 1<<3;
						PORTB &= ~(1<<1);
						PORTB &= ~(1<<2);
						PORTB &= ~(1<<4);
						PORTB &= ~(1<<5);
						PORTC &= ~(1<<PORTC2);
						for(int i=0;i<1;i++){
							DISPLAY_LIGA_NUM(valEsq);
							PORTC &= ~(1<<PORTC1);
							PORTC |= (1<<PORTC0);
							for(int i=0;i<30000;i++){}
							DISPLAY_LIGA_NUM(valDir);
							PORTC &= ~(1<<PORTC0);
							PORTC |= (1<<PORTC1);
							for(int i=0;i<30000;i++){}
								if(valDir==2){
									PORTC |= (1<<PORTC2);
								}
							if(valDir==3){
								Bflag=0;
								valDir=0;
								valEsq=0;
								PORTD &= ~(1<<PORTD0);
								PORTD &= ~(1<<PORTD1);
								PORTD &= ~(1<<PORTD3);
								PORTD &= ~(1<<PORTD4);
								PORTD &= ~(1<<PORTD5);
								PORTD &= ~(1<<PORTD6);
								PORTD &= ~(1<<PORTD7);
								state=3;
								count=11;
								flagDisplayToggle = 0;
							}else{
								if(valEsq==9){
									valEsq=0;
									valDir+=1;
								}else{
									valEsq++;
								}
							}
						}												
					}
				break;				
				case 3:
					PORTB |= 1<<2;
					PORTB |= 1<<3;
					PORTB &= ~(1<<0);
					PORTB &= ~(1<<1);
					PORTB &= ~(1<<4);
					PORTB &= ~(1<<5);
					PORTC |= (1<<PORTC2);
				break;
				case 4:
					PORTB |= 1<<1;
					PORTB |= 1<<3;
					PORTB &= ~(1<<0);
					PORTB &= ~(1<<2);
					PORTB &= ~(1<<4);
					PORTB &= ~(1<<5);
					PORTC |= (1<<PORTC2);
				break;
				case 5:				
					PORTB |= 1<<1;
					PORTB |= 1<<3;
					PORTB &= ~(1<<0);
					PORTB &= ~(1<<2);
					PORTB &= ~(1<<4);
					PORTB &= ~(1<<5);
					if(Bflag==1){
						flagDisplayToggle = 1;
						PORTB |= 1<<0;
						PORTB |= 1<<3;
						PORTB &= ~(1<<1);
						PORTB &= ~(1<<2);
						PORTB &= ~(1<<4);
						PORTB &= ~(1<<5);
						PORTC &= ~(1<<PORTC2);
						for(int i=0;i<1;i++){
							DISPLAY_LIGA_NUM(valEsq);
							PORTC &= ~(1<<PORTC1);
							PORTC |= (1<<PORTC0);
							for(int i=0;i<30000;i++){}
							DISPLAY_LIGA_NUM(valDir);
							PORTC &= ~(1<<PORTC0);
							PORTC |= (1<<PORTC1);
							for(int i=0;i<30000;i++){}
							if(valDir==2){
								PORTC |= (1<<PORTC2);
							}
							if(valDir==3){
								Bflag=0;
								valDir=0;
								valEsq=0;
								PORTD &= ~(1<<PORTD0);
								PORTD &= ~(1<<PORTD1);
								PORTD &= ~(1<<PORTD3);
								PORTD &= ~(1<<PORTD4);
								PORTD &= ~(1<<PORTD5);
								PORTD &= ~(1<<PORTD6);
								PORTD &= ~(1<<PORTD7);
								state=0;
								count=0;
								flagDisplayToggle = 0;
								}else{									
								if(valEsq==9){
									valEsq=0;
									valDir+=1;
									}else{
									valEsq++;
								}
							}
						}
					}
				break;			
			}			
		}
	}
}
ISR(PCINT2_vect){
	if(Bflag==0){
		Bflag=1;
	}
}
ISR(TIMER0_OVF_vect){	
	controle++;
	Tflag = 1;
}
