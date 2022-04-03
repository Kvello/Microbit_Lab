#ifndef PPI_H
#define PPI_H
#include <stdint.h>

#define __PPI_BASE_ADDRESS__ 0x4001F000

#define PPI ((NRF_PPI_REG*)__PPI_BASE_ADDRESS__)

#define __RESERVED_PPI_0_SIZE__ 308
#define __RESERVED_PPI_1_SIZE__ 1
#define __RESERVED_PPI_2_SIZE__ 148
#define __RESERVED_PPI_3_SIZE__ 62

typedef struct {
	uint32_t EN;
	uint32_t DIS;
} PPI_TASKS_TYPE;

typedef struct {
	uint32_t EEP;
	uint32_t TEP;
} PPI_CHANNEL_TYPE;

typedef struct {
	// Tasks
	volatile PPI_TASKS_TYPE PPI_TASKS[6];
	// Registers
	volatile uint32_t RESERVED0[__RESERVED_PPI_0_SIZE__];
	volatile uint32_t CHEN;
	volatile uint32_t CHENSET;
	volatile uint32_t CHENCLR;
	volatile uint32_t RESERVED1[__RESERVED_PPI_1_SIZE__];
	volatile PPI_CHANNEL_TYPE PPI_CH[20];
	volatile uint32_t RESERVED2[__RESERVED_PPI_2_SIZE__];
	volatile uint32_t CHG[6];
	volatile uint32_t RESERVED3[__RESERVED_PPI_3_SIZE__];
	volatile uint32_t FORK_TEP[32];
} NRF_PPI_REG;

#endif

void init_PPI();
