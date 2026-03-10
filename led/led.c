#include <stdio.h>
#include "led.h"

static system_state_t current_state = STATE_IDLE;
static int led_on = 0;

void led_set_state(system_state_t state)
{
    current_state = state;
}

void led_update(void)
{
    switch(current_state)
    {
        case STATE_IDLE:
            if(led_on)
            {
                printf("LED OFF\n");
                led_on = 0;
            }
            break;

        case STATE_WARNING:
            led_on = !led_on;
            printf("LED WARNING BLINK\n");
            break;

        case STATE_ERROR:
            led_on = !led_on;
            printf("LED ERROR BLINK\n");
            break;
    }
}