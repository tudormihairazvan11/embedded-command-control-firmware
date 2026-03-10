#include <stdio.h>
#include "logger.h"

typedef struct
{
    event_type_t type;
    uint32_t timestamp;
} log_event_t;

static log_event_t log_buffer[LOG_SIZE];
static uint8_t log_head = 0;

extern volatile uint32_t system_tick;

void log_event(event_type_t type)
{
    log_buffer[log_head].type = type;
    log_buffer[log_head].timestamp = system_tick;

    log_head = (log_head + 1) % LOG_SIZE;
}

void print_log(void)
{
    printf("---- LOG START ----\n");

    for(int i = 0; i < LOG_SIZE; i++)
    {
        if(log_buffer[i].type != EVENT_NONE)
        {
            printf("Event %d at tick %lu\n",
                   log_buffer[i].type,
                   log_buffer[i].timestamp);
        }
    }

    printf("---- LOG END ----\n");
}