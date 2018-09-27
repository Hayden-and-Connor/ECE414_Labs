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
#include "Utilities/uart.h"

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#define NUM_ITERATIONS 100000
#define NUM_REPS 10

void test_uint8_mult(){
    uint32_t i;
    uint8_t i1, i2, i3;
}

main(){
    TIMER.init();
    UART.init();

    // UART.write_string("test");

    // Turn on system interrupts
    INTEnableSystemSingleVectoredInt();

    while(1) {
        while(1) {
            int isReady = !(U1STA & (1 << 9)); 

            if(isReady) {
                U1TXREG = 'c';
                break;
            }
        }
    }

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
