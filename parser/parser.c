#include <stdio.h>
#include "parser.h"
#include "../logger/logger.h"
#include "../led/led.h"
static parser_state_t parser_state = WAIT_START;

void parse_char(uint8_t c)
{
    switch(parser_state)
    {
        case WAIT_START:

            if(c == '#')
            {
                parser_state = RECEIVE_DATA;
            }

            break;

        case RECEIVE_DATA:

            if(c == '0')
            {
                printf("STATE: IDLE\n");
                log_event(EVENT_STATE_IDLE);
                led_set_state(STATE_IDLE);
            }
            else if(c == '1')
            {
                printf("STATE: WARNING\n");
                log_event(EVENT_STATE_WARNING);
                led_set_state(STATE_WARNING);
            }
            else if(c == '2')
            {
                printf("STATE: ERROR\n");
                log_event(EVENT_STATE_ERROR);
                led_set_state(STATE_ERROR);
            }
            else if(c == 'L')
            {
                print_log();
            }

            if(c == ';')
            {
                parser_state = WAIT_START;
            }

            break;
    }
}