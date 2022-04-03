#include "gpiote.h"
#include "gpio.h"

void GPIOTE_init(){
    /*GPIOTE channel 0. Button A*/
    GPIOTE->CONFIG[0] |= (1<<0);//Event mode on GPIOTE channel 0
    GPIOTE->CONFIG[0] &= ~(0x1f<<8);//Clear PSEL field
    GPIOTE->CONFIG[0] |= (__BUTTON_A_PIN__<<8);//Set psel field for channel 0 to button a pin
    GPIOTE->CONFIG[0] &= ~(1<<13);//Set port field for channel 0 to port 0
    /*Generate event on falling edge for channel 0*/
    GPIOTE->CONFIG[0] &= ~(1<<16);
    GPIOTE->CONFIG[0] |= (1<<17);

    /*GPIOTE channel 1. Row 1*/
    GPIOTE->CONFIG[1] |= (0x3<<0); //Task mode
    GPIOTE->CONFIG[1] &= ~(0x1f<<8);//Clear PSEL field
    GPIOTE->CONFIG[1] |= (ROW_1_PIN<<8);//Set psel field for channel 1 to row 1 pin
    GPIOTE->CONFIG[1] &= ~(1<<13);//Set port field for channel 1 to port 0
    GPIOTE->CONFIG[1] |= (0x3<<16);// Set OUT task to toggle pin

    /*GPIOTE channel 2. Row 2*/
    GPIOTE->CONFIG[2] |= (0x3<<0); //Task mode
    GPIOTE->CONFIG[2] &= ~(0x1f<<8);//Clear PSEL field
    GPIOTE->CONFIG[2] |= (ROW_2_PIN<<8);//Set psel field for channel 2 to row 2 pin
    GPIOTE->CONFIG[2] &= ~(1<<13);//Set port field for channel 2 to port 0
    GPIOTE->CONFIG[2] |= (0x3<<16);// Set OUT task to toggle pin

    /*GPIOTE channel 3. Row 3*/
    GPIOTE->CONFIG[3] |= (0x3<<0); //Task mode
    GPIOTE->CONFIG[3] &= ~(0x1f<<8);//Clear PSEL field
    GPIOTE->CONFIG[3] |= (ROW_3_PIN<<8);//Set psel field for channel 3 to row 3 pin
    GPIOTE->CONFIG[3] &= ~(1<<13);//Set port field for channel 3 to port 0
    GPIOTE->CONFIG[3] |= (0x3<<16);// Set OUT task to toggle pin

    /*GPIOTE channel 4. Row 4*/
    GPIOTE->CONFIG[4] |= (0x3<<0); //Task mode
    GPIOTE->CONFIG[4] &= ~(0x1f<<8);//Clear PSEL field
    GPIOTE->CONFIG[4] |= (ROW_4_PIN<<8);//Set psel field for channel 4 to row 4 pin
    GPIOTE->CONFIG[4] &= ~(1<<13);//Set port field for channel 4 to port 0
    GPIOTE->CONFIG[4] |= (0x3<<16);// Set OUT task to toggle pin

    /*GPIOTE channel 5. Row 5*/
    GPIOTE->CONFIG[5] |= (0x3<<0); //Task mode
    GPIOTE->CONFIG[5] &= ~(0x1f<<8);//Clear PSEL field
    GPIOTE->CONFIG[5] |= (ROW_5_PIN<<8);//Set psel field for channel 5 to row 5 pin
    GPIOTE->CONFIG[5] &= ~(1<<13);//Set port field for channel 5 to port 0
    GPIOTE->CONFIG[5] |= (0x3<<16);// Set OUT task to toggle pin


}