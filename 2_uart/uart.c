#include "uart.h"
#include "gpio.h"

void uart_init(){
    GPIO0 -> DIRCLR = (1 << UART_INTRX_PIN);
    GPIO1 -> DIRSET = (1 << UART_INTTX_PIN);
    GPIO1 -> OUTSET = (1 << UART_INTTX_PIN);
    
    UART_REG->PSEL_RXD = (UART_INTRX_PIN);
    UART_REG->PSEL_RXD &= ~((1 << 5) | (1<< 31));

    UART_REG -> PSEL_TXD = (UART_INTTX_PIN);
    UART_REG -> PSEL_TXD |= (1<<5); 
    UART_REG->PSEL_TXD &= ~(1<< 31);

    UART_REG -> BAUDRATE = 0x00275000; // Setter baudrate til 9600

    UART_REG -> PSEL_RTS |= (1<<31);
    UART_REG -> PSEL_CTS |= (1<<31);

    UART_REG->ENABLE |= (1<<2);
    UART_REG->TASKS_STARTRX |= (1<<0);

    UART_REG->CONFIG &= ~(1<<0);
    UART_REG->CONFIG &= ~((1<<1) | (1<<2) | (1<<3));
    UART_REG->CONFIG |= (1<<4);
}

void uart_send(char letter){

    //UART_REG->TASKS_STARTTX |= (1<<0);
    while(!UART_REG->EVENTS_TXDRDY & (1<<0)){
        ;
    }
    UART_REG->TXD = letter;

    //UART_REG->TASKS_STOPTX
}

char uart_read(){
    if(UART_REG->EVENTS_RXDRDY & (1<<0)){
        UART_REG->EVENTS_RXDRDY &=~(1<<0);
        return UART_REG->RXD;
    }
    else{
        return '\0';
    }
}