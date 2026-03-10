#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 64

void buffer_write(uint8_t data);
uint8_t buffer_read(void);
uint8_t buffer_available(void);

#endif