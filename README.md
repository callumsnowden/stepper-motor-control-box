# stepper-motor-control-box
A simple UART-controlled stepper motor driver.


# UART configuration
UART is currently configured for 115200 baud, 8N1.

# Usage
Send one of `start ###`, `speed ###` or `stop` where `###` is the rotational speed of the motor. As the DM556 stepper driver is currently configured for 400 steps/rev the RPM value is effectively halved i.e. 20 set rpm is equivalent to 10 motor rpm.

# Wiring
Two 4-pin GX12 style connectors provide motor and heater connections. The pinouts are as follows:

## Heater connector

| Pin number | Function |
| ---------- | -------- |
| 1          | Heater + |
| 2          | Heater - |
| 3          | PT100    |
| 4          | PT100    |

## Motor connector

| Pin number | Function |
| ---------- | -------- |
| 1          | A+       |
| 2          | A-       |
| 3          | B+       |
| 4          | B-       |

# Firmware compilation
Board type should be `Arduino Uno`

## Necessary libraries
- [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
- [CommandParser](https://github.com/Uberi/Arduino-CommandParser)