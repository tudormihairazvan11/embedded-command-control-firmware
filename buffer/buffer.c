#include "buffer.h"

static uint8_t buffer[BUFFER_SIZE];

static uint8_t head = 0;
static uint8_t tail = 0;

void buffer_write(uint8_t data)
{
    uint8_t next = (head + 1) % BUFFER_SIZE;

    if(next != tail)
    {
        buffer[head] = data;
        head = next;
    }
}

uint8_t buffer_available(void)
{
    return (head != tail);
}

uint8_t buffer_read(void)
{
    uint8_t data = buffer[tail];

    tail = (tail + 1) % BUFFER_SIZE;

    return data;
}