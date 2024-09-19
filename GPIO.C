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

// Nova função para ler o estado de um pino de entrada
uint32_t gpio_read(uint32_t pin) {
    return (GPIO_ODR & (1 << pin)) ? 1 : 0;
}
