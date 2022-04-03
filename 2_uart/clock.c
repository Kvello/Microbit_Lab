#include "clock.h"

void clock_init(){
    CLOCK_REG->TASKS_HFCLKSTART |= (1<<0); //Start HFXO crystal oscillator
    CLOCK_REG->HFCLKSTAT |=(1<<0); //Source HFCKL with HFXO
    while(!CLOCK_REG->EVENTS_HFCLKSTARTED & (1<<0)){// Wait for clock setup time to ellapse
        ;
    }
}