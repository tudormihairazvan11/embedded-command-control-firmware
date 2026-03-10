#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>

#define LOG_SIZE 10

typedef enum
{
    EVENT_NONE = 0,
    EVENT_STATE_IDLE,
    EVENT_STATE_WARNING,
    EVENT_STATE_ERROR
} event_type_t;

void log_event(event_type_t type);
void print_log(void);

#endif