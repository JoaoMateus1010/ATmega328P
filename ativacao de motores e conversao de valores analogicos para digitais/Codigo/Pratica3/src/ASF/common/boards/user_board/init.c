#include <asf.h>
#include <board.h>
#include <conf_board.h>
void board_init(void){
	SREG = 0b10000000;
}
