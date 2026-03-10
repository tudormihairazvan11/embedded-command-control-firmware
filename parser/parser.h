#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

typedef enum
{
    WAIT_START,
    RECEIVE_DATA
} parser_state_t;

void parse_char(uint8_t c);

#endif