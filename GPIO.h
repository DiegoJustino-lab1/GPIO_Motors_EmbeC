// gpio.h
#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// Definição de registradores (endereços fictícios)
#define GPIO_PORT_BASE  0x40020000
#define GPIO_MODER      (*(volatile uint32_t *)(GPIO_PORT_BASE + 0x00))
#define GPIO_ODR        (*(volatile uint32_t *)(GPIO_PORT_BASE + 0x14))

// Modos de operação dos pinos
#define GPIO_MODE_INPUT  0x0
#define GPIO_MODE_OUTPUT 0x1

// Funções do driver
void gpio_pin_mode(uint32_t pin, uint32_t mode);
void gpio_write(uint32_t pin, uint32_t state);
void gpio_toggle(uint32_t pin);
uint32_t gpio_read(uint32_t pin); // Nova função para ler o estado do pino

// Funções de controle de motor
void motor_set_direction(uint32_t pin1, uint32_t pin2, uint32_t direction);
void motor_set_speed(uint32_t pwm_pin, uint32_t speed);

#endif