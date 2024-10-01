#include "zapper.h"
#include "pico/stdlib.h"
#include <stdio.h>

#ifndef ZAPPER_D3
#define ZAPPER_D3 28
#endif

#ifndef ZAPPER_D4
#define ZAPPER_D4 27
#endif

#define ZAPPER_TRIGGER 0b10000
#define ZAPPER_LIGHTGUN 0b01000
void initzapper(){
    // Initialize the zapper
    gpio_init(ZAPPER_D3);
    gpio_set_dir(ZAPPER_D3, GPIO_IN);
    gpio_pull_up(ZAPPER_D3);

    gpio_init(ZAPPER_D4);
    gpio_set_dir(ZAPPER_D4, GPIO_IN);
    gpio_pull_up(ZAPPER_D4);
}

int readzapper(){
    // Read the zapper
    int zapper = (gpio_get(ZAPPER_D3) == 0) ? ZAPPER_TRIGGER : 0;  // | (gpio_get(ZAPPER_D4) << 1);
    int lightgun = (gpio_get(ZAPPER_D4) == 0) ? ZAPPER_LIGHTGUN : 0;
    //if (zapper || lightgun) printf("Zapper: %d, Lightgun: %d\n", zapper, lightgun);
    
    return zapper | lightgun;
}