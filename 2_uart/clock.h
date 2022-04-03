#pragma once
#include <stdint.h>

#define CLOCK_REG ((NRF_CLOCK_REG*)0x40000000) //clock base adress

typedef struct{

    volatile uint32_t TASKS_HFCLKSTART;// 0x000 Start HFXO crystal oscillator
    volatile uint32_t TASKS_HFCLKSTOP; //0x004 Stop HFXO crystal oscillator
    volatile uint32_t TASKS_LFCLKSTART; //0x008 Start LFCLK
    volatile uint32_t TASKS_LFCLKSTOP; //0x00C Stop LFCLK
    volatile uint32_t TASKS_CAL; //0x010 Start calibration of LFRC
    volatile uint32_t TASKS_CTSTART;// 0x014 Start calibration timer
    volatile uint32_t TASKS_CTSTOP; //0x018 Stop calibration timer
    volatile uint32_t RESERVED0[57];
    volatile uint32_t EVENTS_HFCLKSTARTED; //0x100 HFXO crystal oscillator started
    volatile uint32_t EVENTS_LFCLKSTARTED; //0x104 LFCLK started
    volatile uint32_t RESERVED1[1];
    volatile uint32_t EVENTS_DONE; //0x10C Calibration of LFRC completed
    volatile uint32_t EVENTS_CTTO; //0x110 Calibration timer timeout
    volatile uint32_t RESERVED2[5];
    volatile uint32_t EVENTS_CTSTARTED; //0x128 Calibration timer has been started and is ready to process new tasks
    volatile uint32_t EVENTS_CTSTOPPED; //0x12C Calibration timer has been stopped and is ready to process new tasks
    volatile uint32_t RESERVED3[117];
    volatile uint32_t INTENSET; //0x304 Enable interrupt
    volatile uint32_t INTENCLR; //0x308 Disable interrupt
    volatile uint32_t RESERVED4[63];
    volatile uint32_t HFCLKRUN; //0x408 Status indicating that HFCLKSTART task has been triggered
    volatile uint32_t HFCLKSTAT; //0x40C HFCLK status
    volatile uint32_t RESERVED5[1];
    volatile uint32_t LFCLKRUN; //0x414 Status indicating that LFCLKSTART task has been triggered
    volatile uint32_t LFCLKSTAT; //0x418 LFCLK status
    volatile uint32_t LFCLKSRCCOPY; //0x41C Copy of LFCLKSRC register, set when LFCLKSTART task was triggered
    volatile uint32_t RESERVED6[62];
    volatile uint32_t LFCLKSRC; //0x518 Clock source for the LFCLK
    volatile uint32_t RESERVED7[3];
    volatile uint32_t HFXODEBOUNCE; //0x528 HFXO debounce time. The HFXO is started by triggering the TASKS_HFCLKSTART task.
    volatile uint32_t LFXODEBOUNCE; //0x52C LFXO debounce time. The LFXO is started by triggering the TASKS_LFCLKSTART task when the LFCLKSRC register is configured for Xtal.
    volatile uint32_t RESERVED8[2];
    volatile uint32_t CTIV; //0x538 Calibration timer interval Retained
    volatile uint32_t RESERVED9[7];
    volatile uint32_t TRACECONFIG;// 0x55C Clocking options for the trace port debug interface

} NRF_CLOCK_REG;

void clock_init();