#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main(){
    gpio_init();
    init_PPI();
    GPIOTE_init();

    while(1){
        ;
    }

    return 0;
}