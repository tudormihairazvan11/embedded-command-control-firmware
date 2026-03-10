#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef struct
{
    uint32_t last_run;
    uint32_t period;
} Task;

uint8_t task_should_run(Task *t);

#endif