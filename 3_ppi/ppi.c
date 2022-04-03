#include "ppi.h"
#include "gpiote.h"

void init_PPI(){

    /*PPI channel 0: button a -> set row 1*/
    PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]);
    /*PPI channel 1: button a -> set row 2*/
    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[2]);
    /*PPI channel 2: button a -> set row 3*/
    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[3]);
    /*PPI channel 3: button a -> set row 4*/
    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[4]);
    /*PPI channel 4: button a -> set row 5*/
    PPI->PPI_CH[4].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[4].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[5]);
    /*Enable channels 0-5*/
    PPI->CHEN |= (0x1f<<0);

}