#ifndef UART_H
#define UART_H

#include <p32xxxx.h>
#include <inttypes.h>
#include <plib.h>


void uart_test();

typedef struct uart_interface {
	void (*init)();

	void (*busy_write)(char);
	char (*busy_read)();

	void (*nb_write)(char);
	char (*nb_read)();

	int (*write_ready)();
	int (*read_ready)();
} uart_interface;

uart_interface UART;

#endif