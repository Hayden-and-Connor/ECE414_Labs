/* 
 * File:   main.c
 * Author: dodgeh
 *
 * For lab 04 section 2.3 Interrupt Timer
 * Template from Lab04 description.
 * 
 */

#include <p32xxxx.h>
//#include <int.h>
#include <inttypes.h>
#include <plib.h>

volatile uint32_t timer_ms_count;

void __ISR( 0, ipl1auto) InterruptHandler (void){
    timer_ms_count++;
    // !!! Put code here to clear the interrupt flag
    mT1ClearIntFlag();
}

main(){
    uint32_t last_count;
    // !!! 0. Put code to set up Timer 1 like you did before.
    // !!! Use a prescaler of 1 or 8 this time. Set PR1 to reset every 1 ms.
    T1CON = 0x8000; // TMR1 on, prescale 1:1
    PR1 = 40000; // 1 ms timer rst, T_delay = Prescaler * DELAY / Clock_Freq 

    // Initialize interrupts
    // !!! 1. Set T1 interrupt source to have a priority of 1
    mT1SetIntPriority(1);
    // !!! 2. Turn on system interrupts
    INTEnableSystemSingleVectoredInt();
    // !!! 3. Enable the T1 interrupt source
    mT1IntEnable(1);

    // Show that the interrupt is working!
    TRISACLR = 0x01; // Set RA0 to be an output
    while (1){
        // Wait 1 second
        last_count = timer_ms_count;
        while (timer_ms_count < (last_count+1000)) { }
        // Turn LED on
        PORTASET = 0x1;
        // Wait 1 second
        last_count = timer_ms_count;
        while (timer_ms_count < (last_count+1000)) { }
        // Turn LED off
        PORTACLR = 0x1;
    }
}
