#include "UART.h"
void init_USART(){
	UBRR0H = (unsigned char)(USART_BAUDRATE>>8);
	UBRR0L = (unsigned char)USART_BAUDRATE;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
void USART_Transmit(unsigned char data){
	while (!(UCSR0A&(1<<UDRE0)));
	UDR0 = data;
}
unsigned char USART_Receive(){
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}
void USART_printf(unsigned char *String){
	int i=0;
	for(i=0;String[i]!=0;i++){
		USART_Transmit(String[i]);
	}
}
void USART_printfln(unsigned char *String){
	int i=0;
	for(i=0;String[i]!=0;i++){
		USART_Transmit(String[i]);
	}
	USART_Transmit(0x0D);
}
void USART_printf_int(unsigned int Valor){
		switch(Valor){
			case 0 ... 9:
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)%10)+'0');
			break;
			case 10 ... 99:
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)/10)+'0');
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)%10)+'0');
			break;
			
			case 100 ... 999:
			USART_Transmit((Valor - (Valor/1000)*1000)/100 + '0');
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)/10)+'0');
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)%10)+'0');
			break;
			
			case 1000 ... 9999:
			USART_Transmit(Valor/1000 + '0');
			USART_Transmit((Valor - (Valor/1000)*1000)/100 + '0');
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)/10)+'0');
			USART_Transmit((((Valor -(1000*(Valor/1000)))%100)%10)+'0');
			break;
		}
}