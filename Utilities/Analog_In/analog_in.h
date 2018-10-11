/*============================================================================
 * analog_in.h
 *      Header file for analog input pin module.
 *==========================================================================*/

#ifndef ANALOG_IN_H
#define ANALOG_IN_H


typedef struct _analog_in_interface {
	void (*init)();
	int32_t (*read)(uint8_t);
} analog_in_interface;

// void analog_in_init();
// int32_t analog_in_read(uint8_t analogPIN);

analog_in_interface ANALOG;

#endif
