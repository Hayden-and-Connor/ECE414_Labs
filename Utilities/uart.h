#include <p32xxxx.h>
#include <inttypes.h>
#include <plib.h>

void test();

typedef struct uart_interface {
	void (*init)();
	void (*write)(char);
} uart_interface;

// uart_interface UART;