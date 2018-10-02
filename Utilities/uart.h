/**	UART
 *	Authors: Hayden Dodge, Connor Winiarczyk
 *
 *	this module provides functions for interacting with the build in 
 *	PIC UART hardware. Methods exist for reading and writing single characters
 *	in both blocking (busy_xxx()) and non-blocking (nb_xxx()) varieties.
 *
 *	The simplest way to interact with this module is by calling UART.write_string()
 * 	With the desired value to be printed
 *
 *	NOTE:	it is important to call UART.init() in your program's main method before
 *			trying to interact with this module 	
 */

#ifndef UART_H
#define UART_H

#include <p32xxxx.h>
#include <inttypes.h>
#include <plib.h>

//Defines an interface for talking with the UART module
typedef struct uart_interface {

	void (*init)(); // void UART.init()

	void (*busy_write)(char); 	// void UART.busy_write(char)
	char (*busy_read)(); 		// char UART.busy_read()

	void (*nb_write)(char); // void UART.nb_write(char)
	char (*nb_read)(); 		// char UART.nb_read()

	int (*write_ready)();	// int UART.write_ready()
	int (*read_ready)();	// int UART.read_ready()

	void (*write_string)(char[]);	// int UART.write_string(char[])
} uart_interface;

// instance of the interface we will be using
uart_interface UART;

#endif