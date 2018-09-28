#include "DEFINICOES.h"
#include "ADC.h"
#include "UART.h"
/************************************************************************/
/* DEFINES LOCAIS                                                       */
/************************************************************************/
#define MAX_LEITURA_SENSOR_0 60
#define MAX_LEITURA_SENSOR_1 50
/************************************************************************/
/* FLAGS                                                                 */
/************************************************************************/
unsigned char multiplexFlag = 0;
unsigned int countFlag = 0;
//unsigned char SERVO_MOTOR_ENABLE_VELOCIDADE_1 = 0;
//unsigned char SERVO_MOTOR_ENABLE_VELOCIDADE_2 = 0;
//unsigned char SERVO_MOTOR_ENABLE_VELOCIDADE_3 = 0;
//unsigned char SERVO_MOTOR_ENABLE_VELOCIDADE_4 = 0;
/************************************************************************/
/* VARIAVEIS                                                            */
/************************************************************************/
unsigned char USART_RECEIVE_CHAR;
unsigned int ADC_READ_NUMBER=0;
unsigned int VALOR_LEITURA_PIN_SENSOR_0 = 0;
unsigned int VALOR_LEITURA_PIN_SENSOR_1 = 0;
unsigned char STATE_MACHINE = 0;
int main (void){		
	board_init();	
	init_ADC();
	init_USART();
	while(1){
		
	}
}
/************************************************************************/
/* INTERRUPÇÕES                                                         */
/************************************************************************/
ISR(TIMER0_OVF_vect){
	//TCNT0 = 0;
	PORTB = DISPLAY_CLR;
	if(multiplexFlag){
		PORTC &= ~(1<<DISPLAY_MULTIPLEX_KEY_LEFT);
		PORTC |= (1<<DISPLAY_MULTIPLEX_KEY_RIGH);
	}else{
		PORTC |= (1<<DISPLAY_MULTIPLEX_KEY_LEFT);
		PORTC &= ~(1<<DISPLAY_MULTIPLEX_KEY_RIGH);
	}
	switch(STATE_MACHINE){
		case 0:
		if(multiplexFlag){
			DISPLAY_FUNCTION_UP_NUMBER(VALOR_LEITURA_PIN_SENSOR_0/10);
		}else{
			DISPLAY_FUNCTION_UP_NUMBER(VALOR_LEITURA_PIN_SENSOR_0%10);
		}
		break;
		case 1:
		if(multiplexFlag){
			PORTB = DISPLAY_UP_graus;
			}else{
			PORTB = DISPLAY_UP_C;
		}
		break;
		case 2:
		if(multiplexFlag){
			DISPLAY_FUNCTION_UP_NUMBER(VALOR_LEITURA_PIN_SENSOR_1/10);
			}else{
			DISPLAY_FUNCTION_UP_NUMBER(VALOR_LEITURA_PIN_SENSOR_1%10);
		}
		break;
		case 3:
		if(multiplexFlag){
			PORTB = DISPLAY_UP_L;
			}else{
			PORTB = DISPLAY_UP_u;
		}
		break;
	}
	
	multiplexFlag ^=1;
}
ISR(TIMER1_OVF_vect){			
		VALOR_LEITURA_PIN_SENSOR_0 = ((MAX_LEITURA_SENSOR_0 * Read_ADC(ADC2))/1023);
		VALOR_LEITURA_PIN_SENSOR_1 = ((MAX_LEITURA_SENSOR_1 * Read_ADC(ADC3))/1023);				
		if (countFlag>0x7){
			STATE_MACHINE++;
			countFlag=0;						
		}
		if(STATE_MACHINE>3){
			STATE_MACHINE=0;
			countFlag=0;
		}	
		countFlag++;	
}
ISR(ADC_vect){
	//ADC_READ_NUMBER = UDR0;
	//VALOR_LEITURA_PIN_SENSOR_0 = ((MAX_LEITURA_SENSOR_0 * ADC_READ_NUMBER)/1023);
}
ISR(USART_RX_vect){
	USART_RECEIVE_CHAR = USART_Receive();
	switch(USART_RECEIVE_CHAR){
		case 'a':			
			PORTC ^= 1<<PORTC4;
		break;
		case 'b':
			PORTD ^= 1<<PORTD2;
		break;
		case 'c':
			PORTD ^= 1<<PORTD4;
		break;
		case 't':
			USART_printf_int(VALOR_LEITURA_PIN_SENSOR_0);
			USART_printfln(" °C");
		break;
		case 'l':
			USART_printf_int(VALOR_LEITURA_PIN_SENSOR_1);
			USART_printfln(" Lu");
		break;
		case '1':
			//SERVO_MOTOR_ENABLE_VELOCIDADE_1 = 1;
			OCR2A = 70;
		break;
		case '2':
			//SERVO_MOTOR_ENABLE_VELOCIDADE_2 = 1;
			OCR2A = 190;
		break;
		case '3':
			//SERVO_MOTOR_ENABLE_VELOCIDADE_3 = 1;
			OCR2A = 250;
		break;
		case '4':
			//SERVO_MOTOR_ENABLE_VELOCIDADE_4 = 1;
			OCR2A = 0;
		break;
		default:
			USART_printfln("Alternativa Invalida");
		break;
	}
}