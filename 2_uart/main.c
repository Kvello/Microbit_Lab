#include "uart.h"
#include "gpio.h"
#include "clock.h"
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
return count;
}

int charToInt(char num){
	if(num<='9'&&num>='0'){
		return (int) num-48;
	}
	else{
		return -1;
	}
}

ssize_t _read(int fd, void *buf, size_t count){
	char *str = (char *)(buf);
	char letter;
	do {
		letter = uart_read();
	} while(letter == '\0');
	*str = letter;
	return 1;
}

bool light_on = false;

int main(){
    
    clock_init();
    gpio_init();
    uart_init();
	iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
	int sleep = 0;
	
	/*
	bool a_entered = false;
	int b = 0;
	bool b_entered = false;
	*/
	char a = 0;
	iprintf("This program takes two integers, multiplies them, and returns the result\n\r");
	while(a == 0){
		a = uart_read();
	}
	
	
	uart_send(a);

	
	/*
	while(!a_entered){
		iprintf("Please enter an integer ");
		int res = scanf("%d",&a);
		if(res == EOF){
			iprintf("%d is not an integer.\n", a);
		}
		else{
			iprintf("%d\n", a);
			a_entered = true;
		}
	}
	while(!b_entered){
		iprintf("Please enter an integer: ");
		int res = scanf("%d",&b);
		if(res == EOF){
			iprintf("%d is not an integer.\n", b);
		}else{
			iprintf("%d\n", b);
			b_entered = true;
		}
	}
	*/
	//int result = a*b;
	//iprintf("%d*%d = %d",a,b,result);

	while(1){

		if(((GPIO0->IN) & (1<<__BUTTON_B_PIN__)) == 0){
            //gpio_lights_on();
            uart_send('B');
		}

		else if(((GPIO0->IN) & (1<<__BUTTON_A_PIN__) )== 0){
            //gpio_lights_off();
			uart_send('A');
		}

		char response = uart_read();

		if(response != '\0'){
			//uart_send(response);
			if(light_on){
				gpio_lights_off();
				light_on = false;
			}
			else{
				gpio_lights_on();
				light_on = true;
			}
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
