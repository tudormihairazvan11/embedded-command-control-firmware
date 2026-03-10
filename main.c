#include <stdio.h>
#include <stdint.h>

#include "scheduler/scheduler.h"
#include "parser/parser.h"
#include "logger/logger.h"
#include "buffer/buffer.h"
#include "led/led.h"
#include "watchdog/watchdog.h"

volatile uint32_t system_tick = 0;

Task led_task = {0, 1000};

int main(void)
{
    printf("Embedded Command-Control Firmware Started\n");

    buffer_write('#');
    buffer_write('1');
    buffer_write(';');

    buffer_write('#');
    buffer_write('L');
    buffer_write(';');

    while(1)
    {
        system_tick++;

        /* citire buffer → parser */
        while(buffer_available())
        {
            uint8_t c = buffer_read();
            parse_char(c);
        }

        /* watchdog */
        watchdog_feed();
        watchdog_check();

        /* task scheduler */
        if(task_should_run(&led_task))
        {
            led_update();
        }

        if(system_tick > 5000)
            break;
    }

    return 0;
}