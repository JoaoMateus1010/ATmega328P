#include <avr/io.h>
void board_inicializar(void){
  //Habilitar interrupções
  SREG = 0b10000000;
  //  I/Os
  DDRB=0b11111111;
  PORTB=0b00000000;
  DDRC=0b11111111;
  PORTC=0b00000001;
  // Timer
  TCCR0A=0b00000000;
  TCCR0B=0b00000011;
  
  //Interrupção
  EICRA=0b00000011;
  EIMSK |= (1<<INT0);
}
void acendedisplay(unsigned int num){
  switch (num){
    case 0:
    PORTB=0b11111001;
    break;
    case 1:
    PORTB=0b10100100;
    break;
    case 2:
    PORTB=0b10110000;
    break;
    case 3:
    PORTB=0b10011001;
    break;
    case 4:
    PORTB=0b10010010;
    break;
    case 5:
    PORTB=0b10000010;
    break;
    default:
    break;
    
  }
}
int main (void){
  board_inicializar();
  while(1){
    PORTC=0b11111110;
  }
}
ISR(INT0_vect){
  acendedisplay(TCNT0%6);
}