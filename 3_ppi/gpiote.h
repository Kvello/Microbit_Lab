#ifndef GPIOTE_H
#define GPIOTE_H
#include <stdint.h>

#define __GPIOTE_BASE_ADDRESS__ 0x40006000

#define GPIOTE ((NRF_GPIOTE_REG*)__GPIOTE_BASE_ADDRESS__)

#define __RESERVED_GPIOTE_0_SIZE__ 4
#define __RESERVED_GPIOTE_1_SIZE__ 4
#define __RESERVED_GPIOTE_2_SIZE__ 32
#define __RESERVED_GPIOTE_3_SIZE__ 23
#define __RESERVED_GPIOTE_4_SIZE__ 97
#define __RESERVED_GPIOTE_5_SIZE__ 129

typedef struct {
	// Tasks
	volatile uint32_t TASKS_OUT[8];
	volatile uint32_t RESERVED0[__RESERVED_GPIOTE_0_SIZE__];
	volatile uint32_t TASKS_SET[8];
	volatile uint32_t RESERVED1[__RESERVED_GPIOTE_1_SIZE__];
	volatile uint32_t TASKS_CLR[8];
	// Events
	volatile uint32_t RESERVED2[__RESERVED_GPIOTE_2_SIZE__];
	volatile uint32_t EVENTS_IN[8];
	volatile uint32_t RESERVED3[__RESERVED_GPIOTE_3_SIZE__];
	volatile uint32_t EVENTS_PORT;
	// Registers
	volatile uint32_t RESERVED4[__RESERVED_GPIOTE_4_SIZE__];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED5[__RESERVED_GPIOTE_5_SIZE__];
	volatile uint32_t CONFIG[8];
} NRF_GPIOTE_REG;

void GPIOTE_init();

#endif
