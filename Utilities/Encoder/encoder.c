#include "encoder.h"

static int encoder, encoder_sub; 

static void init(){
	ANSELB &= ~(1 << CHN_A);
	ANSELB &= ~(1 << CHN_B);
	TRISB |= (1 << CHN_A);
	TRISB |= (1 << CHN_B);
	
	encoder = 0;
	encoder_sub = 0;
}

static void poll_pm(){
	read();

	if(encoder_sub == 3){
		if(encoder_sub_prev == 2){
			UART.busy_write('+');
		} else if(encoder_sub_prev == 1){
			UART.busy_write('-');
		}
		
	}

	for(i = 0; i < 1000; i++){}
}

static void read(){
	encoder_sub_prev = encoder_sub;
	encoder_sub = (PORTB & (1 << CHN_A)) >> CHN_A;
	encoder_sub |= (PORTB & (1 << CHN_B)) >> CHN_B - 1;
}