#include "scheduler.h"

extern volatile uint32_t system_tick;

uint8_t task_should_run(Task *t)
{
    if((system_tick - t->last_run) >= t->period)
    {
        t->last_run = system_tick;
        return 1;
    }

    return 0;
}