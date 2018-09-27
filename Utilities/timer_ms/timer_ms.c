#include timer_ms.h

static volatile uint32_t timer_ms_count;

void __ISR( 0, ipl1auto) InterruptHandler (void){
    timer_ms_count++;
    // !!! Put code here to clear the interrupt flag
    mT1ClearIntFlag();
}

static void init(){
	// !!! 0. Put code to set up Timer 1 like you did before.
    // !!! Use a prescaler of 1 or 8 this time. Set PR1 to reset every 1 ms.
    T1CON = 0x8000; // TMR1 on, prescale 1:1
    PR1 = 40000; // 1 ms timer rst, T_delay = Prescaler * DELAY / Clock_Freq 

    // Initialize interrupts
    // !!! 1. Set T1 interrupt source to have a priority of 1
    mT1SetIntPriority(1);
    
    // !!! 3. Enable the T1 interrupt source
    mT1IntEnable(1);
}

static int read(){
	return timer_ms_count;
}

static void delay_ms(int time){
	uint32_t last_count;
	while(timer_ms_count < last_count + time){

	}
}

timer_interface TIMER = {
	&init,
	&read,
	&delay_ms
};
