#include <stdio.h>
#include "watchdog.h"

static uint32_t last_feed = 0;

extern volatile uint32_t system_tick;

#define WATCHDOG_TIMEOUT 2000

void watchdog_feed(void)
{
    last_feed = system_tick;
}

void watchdog_check(void)
{
    if((system_tick - last_feed) > WATCHDOG_TIMEOUT)
    {
        printf("WATCHDOG RESET!\n");
        last_feed = system_tick;
    }
}