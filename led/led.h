#ifndef LED_H
#define LED_H

typedef enum
{
    STATE_IDLE = 0,
    STATE_WARNING,
    STATE_ERROR
} system_state_t;

void led_set_state(system_state_t state);
void led_update(void);

#endif