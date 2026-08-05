# Lab 1
## Exercises
### 1
Done in code.
### 2
- GPIOD_MODER: port mode register, configure I/O mode.
- GPIOD_OTYPER: port output type register, configure output type.
- GPIOD_OSPEEDR: port output speed register, configure output slew-rate speed.
- GPIOD_PUPDR: port pull-up/pull-down register, configure internal pull resistor.
- GPIOD_ODR: port output data register, hold the value written to each pin when configured as output.

GPIOD_MODER and GPIOD_ODR remains zero forever because code uses GPIOA.

At start GPIOA_ODR is 0xa8000000 and GPIOA_MODER is 0xa80004a0. GPIOA_ODR will by 0x20 (bit 5 is high) when light is lid and 0x00 when light is off. GPIOA_MODER remains constant.
### 3
register|before|after
---|---|---
PLLP|/2|/2
PLLN|x50|x100
PLLM|/8|/8
### 4
Done in code.
