#include "uart.h"
#include "gpio.h"
#include "clock.h"


int main(){
    uart_init();
    clock_init();
    gpio_init();
	
	int sleep = 0;
	while(1){

		if(((GPIO0->IN) & (1<<__BUTTON_B_PIN__)) == 0){
            gpio_lights_on();
            uart_send('A');
		}

		else if(((GPIO0->IN) & (1<<__BUTTON_A_PIN__) )== 0){
            gpio_lights_off();
		}

		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */

		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
