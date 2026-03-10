#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <stdint.h>

void watchdog_feed(void);
void watchdog_check(void);

#endif