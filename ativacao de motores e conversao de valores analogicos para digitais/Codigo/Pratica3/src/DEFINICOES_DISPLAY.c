#include "DEFINES_DISPLAY.h"
void DISPLAY_FUNCTION_UP_NUMBER(unsigned char NUMBER){
	PORTB = DISPLAY_CLR;
	switch(NUMBER){
		case 0:
			PORTB = DISPLAY_UP_0;
		break;
		case 1:
			PORTB = DISPLAY_UP_1;
		break;
		case 2:
			PORTB = DISPLAY_UP_2;
		break;
		case 3:
			PORTB = DISPLAY_UP_3;
		break;
		case 4:
			PORTB = DISPLAY_UP_4;
		break;
		case 5:
			PORTB = DISPLAY_UP_5;
		break;
		case 6:
			PORTB = DISPLAY_UP_6;
		break;
		case 7:
			PORTB = DISPLAY_UP_7;
		break;
		case 8:
			PORTB = DISPLAY_UP_8;
		break;
		case 9:
			PORTB = DISPLAY_UP_9;
		break;		
	}
}
void DISPLAY_FUNCTION_UP_NUMBER_0_99(unsigned int NUMBER){
	DISPLAY_FUNCTION_UP_NUMBER(NUMBER/10);
}