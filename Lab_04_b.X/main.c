/* 
 * ECE 414
 * File:   main.c
 * Author: dodgeh
 *
 * For lab 04 section 2.3 Interrupt Timer
 * Template from Lab04 description.
 * 
 */

#include <p32xxxx.h>
#include <inttypes.h>
#include <plib.h>
#include "Utilities/timer_ms/timer_ms.h"

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

main(){
    TIMER.init();

    // Turn on system interrupts
    INTEnableSystemSingleVectoredInt();

    // Show that the interrupt is working!
    TRISACLR = 0x01; // Set RA0 to be an output
    while (1){
        TIMER.delay_ms(1000);
        // Turn LED on
        PORTASET = 0x1;
        
        TIMER.delay_ms(1000);
        // Turn LED off
        PORTACLR = 0x1;
    }
}
