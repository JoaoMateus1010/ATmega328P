#include "ADC.h"
void init_ADC(){
	ADMUX  = 0b00000000;
	ADCSRA = 0b11000111;
	ADCSRB = 0b00000110;
}
unsigned int Read_ADC(unsigned int PIN_ADC_ANALOG){
	int Valor_da_leitura = 0;	
	ADMUX  = PIN_ADC_ANALOG;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC)){/*CONVERTENDO*/}
	Valor_da_leitura = ADC;
	return Valor_da_leitura;
}
void Enable_Read_ADC(unsigned int PIN_ADC_ANALOG){
	ADMUX  = PIN_ADC_ANALOG;
	ADCSRA |= (1<<ADSC);
}