#include "defines.h"

extern void start(void);        /* start-up */
extern void intr_softerr(void);
extern void intr_syscall(void);
extern void intr_serintr(void);

/*
 * setting of interruption vector
 * This is allocated at top address by linker script definition.
 */
void (*vectors[])(void) = {
	start, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	intr_syscall, intr_softerr, intr_softerr, intr_softerr, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	intr_serintr, intr_serintr, intr_serintr, intr_serintr, 
	intr_serintr, intr_serintr, intr_serintr, intr_serintr, 
	intr_serintr, intr_serintr, intr_serintr, intr_serintr, 
};
