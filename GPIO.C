// gpio.c
#include "gpio.h"

void gpio_pin_mode(uint32_t pin, uint32_t mode) {
    GPIO_MODER &= ~(0x3 << (pin * 2));
    GPIO_MODER |= (mode << (pin * 2));
}

void gpio_write(uint32_t pin, uint32_t state) {
    if (state) {
        GPIO_ODR |= (1 << pin);
    } else {
        GPIO_ODR &= ~(1 << pin);
    }
}

void gpio_toggle(uint32_t pin) {
    GPIO_ODR ^= (1 << pin);
}

uint32_t gpio_read(uint32_t pin) {
    return (GPIO_ODR & (1 << pin)) ? 1 : 0;
}

// Função para definir a direção do motor
void motor_set_direction(uint32_t pin1, uint32_t pin2, uint32_t direction) {
    if (direction) {
        gpio_write(pin1, 1);
        gpio_write(pin2, 0);
    } else {
        gpio_write(pin1, 0);
        gpio_write(pin2, 1);
    }
}

// Função para definir a velocidade do motor (simulação de PWM)
void motor_set_speed(uint32_t pwm_pin, uint32_t speed) {
    // Simulação de PWM: liga e desliga o pino rapidamente
    for (uint32_t i = 0; i < speed; i++) {
        gpio_write(pwm_pin, 1);
        for (volatile int j = 0; j < 1000; j++); // Ajuste o valor para controlar a frequência
        gpio_write(pwm_pin, 0);
        for (volatile int j = 0; j < 1000; j++); // Ajuste o valor para controlar a frequência
    }
}