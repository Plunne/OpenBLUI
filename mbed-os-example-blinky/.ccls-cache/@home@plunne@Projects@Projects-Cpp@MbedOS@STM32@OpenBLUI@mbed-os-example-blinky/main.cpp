/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500000


int main()
{
// Initialise the digital pin LED1 as an output
#ifdef LED3
    DigitalOut led(LED3);
#else
    bool led;
#endif

    while (true) {
        led = !led;
        wait_us(BLINKING_RATE);
    }
}
