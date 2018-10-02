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

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

// Number of iterations for testing. You may need to play with this number.
// If it is too short, you may not get a very accurate measure of performance.
// Too long and you will have to wait forever.
#define NUM_ITERATIONS 100000

// This is the number of times you repeat the operation within the loop.
// You want to repeat enough times that the loop overhead is small for
// the simplest operations.
#define NUM_REPS 20

#define NUM_TESTCASES 24

uint8_t buffer[64];

void test_uint8_add(){

    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;

        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_uint8_sub(){

    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;

        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

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

void test_uint8_div(){

    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;

        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

void test_unint16_add(){

    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 12734;
    i2 = 89139;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;

        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_unint16_sub(){

    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 12734;
    i2 = 89139;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;

        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_unint16_mult(){

    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 12734;
    i2 = 89139;
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

void test_unint16_div(){

    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 12734;
    i2 = 89139;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;

        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

void test_unint32_add(){

    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 294967296;
    i2 = 89496789;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;

        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_unint32_sub(){

    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 294967296;
    i2 = 89496789;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;

        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_unint32_mult(){

    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 294967296;
    i2 = 89496789;
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

void test_unint32_div(){

    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 294967296;
    i2 = 89496789;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;

        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

void test_unint64_add(){

    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 1273489139;
    i2 = 8913912734;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;

        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_unint64_sub(){

    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 1273489139;
    i2 = 8913912734;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;

        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_unint64_mult(){

    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 1273489139;
    i2 = 8913912734;
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

void test_unint64_div(){

    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 8913912734;
    i2 = 1273489139;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;

        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

void test_float_add(){

    uint32_t i;
    float i1, i2, i3;
    i1 = 12.734;
    i2 = 8913.9;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;

        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_float_sub(){

    uint32_t i;
    float i1, i2, i3;
    i1 = 12.734;
    i2 = 8913.9;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;

        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_float_mult(){

    uint32_t i;
    float i1, i2, i3;
    i1 = 12.734;
    i2 = 8913.9;
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

void test_float_div(){

    uint32_t i;
    float i1, i2, i3;
    i1 = 12.734;
    i2 = 8913.9;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;

        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

void test_double_add(){

    uint32_t i;
    double i1, i2, i3;
    i1 = 12.73491746298;
    i2 = 999999999978949878913.9;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;

        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_double_sub(){

    uint32_t i;
    double i1, i2, i3;
    i1 = 12.73491746298;
    i2 = 999999999978949878913.9;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;

        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_double_mult(){

    uint32_t i;
    double i1, i2, i3;
    i1 = 12.73491746298;
    i2 = 999999999978949878913.9;
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

void test_double_div(){

    uint32_t i;
    double i1, i2, i3;
    i1 = 12.73491746298;
    i2 = 999999999978949878913.9;
    for (i=0; i<NUM_ITERATIONS; i++){
        // Make sure NUM_REPS is the same as the number
        // of repeated lines here.
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;

        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}


void (*testcases[])() = {
    &test_uint8_add,
    &test_uint8_sub,
    &test_uint8_mult,
    &test_uint8_div,
    &test_unint16_add,
    &test_unint16_sub,
    &test_unint16_mult,
    &test_unint16_div,
    &test_unint32_add,
    &test_unint32_sub,
    &test_unint32_mult,
    &test_unint32_div,
    &test_unint64_add,
    &test_unint64_sub,
    &test_unint64_mult,
    &test_unint64_div,
    &test_float_add,
    &test_float_sub,
    &test_float_mult,
    &test_float_div,
    &test_double_add,
    &test_double_sub,
    &test_double_mult,
    &test_double_div
};

void main(){
    UART.init();
    TIMER.init();
    INTEnableSystemSingleVectoredInt();

    uint32_t t1, t2;
    
    int i;
    for(i = 0; i < NUM_TESTCASES; i++){
        UART.write_string("Performance Summary: Time per operation statistics\r\n");
        // Test multiplying bytes
        t1 = TIMER.read();
        testcases[i]();
        t2 = TIMER.read();

        // Print timing result. Doubles OK here. Not time or space critical code.
        sprintf(buffer, " : %.06f us per operation\r\n",
        (double)(t2-t1)/(double)NUM_ITERATIONS/(double)NUM_REPS*1000.0);
        UART.write_string(buffer);

        if(i % 4 == 3){
            UART.busy_write('\r');
            UART.busy_write('\n');
        }
    }
    while (1); // When done, wait forever.
}

