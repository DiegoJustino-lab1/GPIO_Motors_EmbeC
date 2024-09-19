#include "gpio.h"

int main() {
    // Configura o pino 5 como saída
    gpio_pin_mode(5, GPIO_MODE_OUTPUT);

    // Configura o pino 6 como entrada
    gpio_pin_mode(6, GPIO_MODE_INPUT);

    while (1) {
        // Lê o estado do pino 6
        uint32_t pin_state = gpio_read(6);

        // Se o pino 6 estiver em HIGH, liga o pino 5
        if (pin_state) {
            gpio_write(5, 1);  // Liga o pino 5
        } else {
            gpio_write(5, 0);  // Desliga o pino 5
        }

        // Alterna o estado do pino 5 (piscar)
        gpio_toggle(5);
        for (volatile int i = 0; i < 100000; i++);  // Atraso
    }

    return 0;
}
