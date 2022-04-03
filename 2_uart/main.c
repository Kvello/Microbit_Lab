#include "uart.h"
#include "gpio.h"


int main(){
    gpio_init();
    uart_init();
    
    while(1){
        if(((GPIO0->IN) & (1<<__BUTTON_B_PIN__)) == 0){
            gpio_lights_on();
            uart_send("B");
		}
        else if(((GPIO0->IN) & (1<<__BUTTON_A_PIN__) )== 0){
            gpio_lights_off();
            uart_send("A");
		}
        
    }
    return 0;
}