# embedded-command-control-firmware
Modular embedded firmware architecture with scheduler, command parser, circular buffer and watchdog
## Overview
This project implements a modular embedded firmware architecture written in C.

The system simulates a command-control firmware typically used in microcontroller based systems.

## Features

- Cooperative task scheduler
- UART command parser using state machine
- Circular buffer for communication
- LED state machine
- Watchdog safety mechanism
- Modular firmware architecture

## Architecture

UART → Buffer → Parser → System State  
Scheduler → Task Execution  
Watchdog → System Safety

## Project Structure

main.c  
scheduler/  
parser/  
buffer/  
logger/  
led/  
watchdog/

## Build

Compile using:
gcc main.c scheduler/scheduler.c parser/parser.c logger/logger.c buffer/buffer.c led/led.c watchdog/watchdog.c -o firmware.exe
Run:
./firmware.exe
## Example Commands
#1; → WARNING state
#2; → ERROR state
#L; → print log

## Concepts Used

- Embedded firmware architecture
- State machines
- Ring buffers
- Cooperative scheduling
- Watchdog safety systems
<img width="746" height="644" alt="image" src="https://github.com/user-attachments/assets/61a0053e-a345-47a6-bdde-8c541e26f90d" />

<img width="718" height="259" alt="image" src="https://github.com/user-attachments/assets/05bf591b-cea6-46ad-9b70-4707e448142e" />

