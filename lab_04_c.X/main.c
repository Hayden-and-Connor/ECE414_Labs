/* 
 * File:   main.c
 * Author: dodgeh
 *
 * Created on September 27, 2018, 1:42 AM
 */

#include <p32xxxx.h>
#include <inttypes.h>
#include <stdio.h> // for sprintf

#include "Utilities/timer_ms/timer_ms.h"
#include "Utilities/uart.h"

// Number of iterations for testing. You may need to play with this number.
// If it is too short, you may not get a very accurate measure of performance.
// Too long and you will have to wait forever.
#define NUM_ITERATIONS 100000

// This is the number of times you repeat the operation within the loop.
// You want to repeat enough times that the loop overhead is small for
// the simplest operations.
#define NUM_REPS 10

uint8_t buffer[64];

void test_uint8_mult(){
    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}
void main(){
    uint32_t t1, t2;
    // !!! Add code: Initialize modules and turn on interrupts
    UART.write_string("Performance Summary: Time per operation statistics\r\n");
    // Test multiplying bytes
    t1 = TIMER.read();
    test_uint8_mult();
    t2 = TIMER.read();
    // Print timing result. Doubles OK here. Not time or space critical code.
    sprintf(buffer, "UINT8 MULT: %.06f us per operation\r\n",
    (double)(t2-t1)/(double)NUM_ITERATIONS/(double)NUM_REPS*1000.0);
    uart_write_string(buffer);
    // Add code to test other sizes and operators
    // ...
    while (1); // When done, wait forever.
}

