#include "gpio.h"

#define MOTOR_PIN1 5
#define MOTOR_PIN2 6
#define MOTOR_PWM_PIN 7

int main() {
    // Configurar pinos do motor como saída
    gpio_pin_mode(MOTOR_PIN1, GPIO_MODE_OUTPUT);
    gpio_pin_mode(MOTOR_PIN2, GPIO_MODE_OUTPUT);
    gpio_pin_mode(MOTOR_PWM_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        // Definir direção do motor
        motor_set_direction(MOTOR_PIN1, MOTOR_PIN2, 1); // 1 para frente, 0 para trás
        
        // Definir velocidade do motor
        motor_set_speed(MOTOR_PWM_PIN, 500); // Ajuste o valor para controlar a velocidade
        
        for (volatile int i = 0; i < 1000000; i++);  // Esperar um pouco
        
        // Inverter direção do motor
        motor_set_direction(MOTOR_PIN1, MOTOR_PIN2, 0);
        
        // Definir velocidade do motor
        motor_set_speed(MOTOR_PWM_PIN, 500); // Ajuste o valor para controlar a velocidade
        
        for (volatile int i = 0; i < 1000000; i++);  // Esperar um pouco
    }
    
    return 0;
}