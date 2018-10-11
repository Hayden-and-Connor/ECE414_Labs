#ifndef ENCODER_H
#define ENCODER_H

// must use PORTB
#define CHN_A 13
#define CHN_B 14

void init();

// must be called as frequently as possible
void poll();

typedef struct encoder_interface {
	void (*init)();
	void (*poll)();
} encoder_interface;

encoder_interface ENCODER;
#endif