#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

#define TEMPERATURA_MAX 30
#define TEMPERATURA_MIN 16

/*PADRONIZAÇÃO DOS CARACTERES
	'a' - Ligar
	'b' - Desligar
	'c' - Aumentar Temperatura
	'd' - Diminuir temperatura
	'e' - Ventilar
	'f' - Parar de ventilar
	'g' - Conectado com BLuetooth
	'h' - Desconctado com Bluetooth
*/
unsigned char caracter              = 0;
unsigned int temperatura            = 20;
unsigned char flag_system_status    = 0;
unsigned char flag_bluetooth_status = 0;
/*
	flag_bluetooth_status = 0 -> DESCONECTADO
	flag_bluetooth_status = 1 -> CONECTADO
*/
unsigned char flag_ar_ventilar      = 0;
int main(void){	
	init_USART();
	SREG = 0b10000000;	
	DDRB = 0b00111111;
	PORTB = 0;
	PORTB |= 1<<PORTB1;
	TCCR0A = 0;
	TCCR0B = 0b00000000;
	TIMSK0 = 0b00000001;	
    while (1){
		
    }
	PORTB &= ~(1<<PORTB1);
}
ISR(USART_RX_vect){
	caracter = USART_Receive();
	//USART_Transmit(caracter);
	switch(caracter){
		case 'a': // LIGAR
		USART_printfln("LIGADO");
			flag_system_status = 1;
			PORTB |= 1<<PORTB1;
		break;
		case 'b': // DESLIGAR
		USART_printfln("DESLIGADO");
			flag_system_status = 0;
			PORTB &= ~(1<<PORTB1);
		break;
		case 'c': // AUMENTAR TEMPERATURA
			if(flag_system_status && temperatura < TEMPERATURA_MAX){
				temperatura++;
				PORTB |= 1<<PORTB3;
				//TCCR0B |= (1<<CS00)|(1<<CS02);
				USART_printf_int(temperatura);
				USART_printfln("");
			}
		break;
		case 'd': // DIMINUIR TEMPERATURA			
			if(flag_system_status && temperatura > TEMPERATURA_MIN){
				temperatura--;
				PORTB |= 1<<PORTB4;
				PORTB &= ~(1<<PORTB4);
				USART_printf_int(temperatura);
				USART_printfln("");
				//TCCR0B |= (1<<CS00)|(1<<CS02);
			}	
		break;		
		case 'e': // ATIVAR VENTILAR
		USART_printfln("LIGA VENTILAR");
			if(flag_system_status){
				flag_ar_ventilar = 1;
				PORTB |= 1<<PORTB5;
				PORTB &= ~(1<<PORTB5);
			}
		break;
		case 'f': // DESATIVAR VENTILAR
		USART_printfln("DESLIGA VENTILAR");
			if(flag_system_status){
				flag_ar_ventilar = 0;
				PORTB &= ~(1<<PORTB5);
			}
		break;
		case 'g': // CONECTADO COM O BLUETOOTH
		USART_printfln("CONECTADO COM O BLUETOOTH");
			if(!flag_bluetooth_status){
				flag_bluetooth_status = 1;
				PORTB |= 1<<PORTB0;
			}
		break;
		case 'h': // DESCONECTADO COM O BLUETOOTH
		USART_printfln("DESCONECTADO COM O BLUETOOTH");
			if(flag_bluetooth_status){
				flag_bluetooth_status=0;
				PORTB &= ~(1<<PORTB0);
			}
		break;
	}	
}