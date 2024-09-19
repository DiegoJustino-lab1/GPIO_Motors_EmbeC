#include <stdint.h> 

// GPIO stuff
#define GPIO_BASE 0x40020000
#define GPIO_MODE (*(volatile uint32_t *)(GPIO_BASE + 0x00))
#define GPIO_OUT  (*(volatile uint32_t *)(GPIO_BASE + 0x14))

// Modes
#define PIN_INPUT  0x0
#define PIN_OUTPUT 0x1

// Using pin 5
#define MY_PIN 5

// Set pin mode
void set_pin_mode(uint32_t pin, uint32_t mode) {
    GPIO_MODE &= ~(0x3 << (pin * 2));
    GPIO_MODE |= (mode << (pin * 2));
}

// Turn pin on/off
void set_pin(uint32_t pin, uint32_t on_off) {
    if (on_off) {
        GPIO_OUT |= (1 << pin);
    } else {
        GPIO_OUT &= ~(1 << pin);
    }
}

// Flip pin state
void flip_pin(uint32_t pin) {
    GPIO_OUT ^= (1 << pin);
}

int main() {
    // Set pin 5 as output
    set_pin_mode(MY_PIN, PIN_OUTPUT);
    
    while (1) {
        // Turn on
        set_pin(MY_PIN, 1);
        for (volatile int i = 0; i < 100000; i++);  // Wait a bit
        
        // Turn off
        set_pin(MY_PIN, 0);
        for (volatile int i = 0; i < 100000; i++);  // Wait a bit
        
        // Flip
        flip_pin(MY_PIN);
        for (volatile int i = 0; i < 100000; i++);  // Wait a bit
    }
    
    return 0;
}
