#include "pico/stdlib.h"
#include <stdio.h>

#define LED_PIN 11
#define BIN_PIN 5

int main()
{
    // Configuração do LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Configuração do botão com pull-up interno
    gpio_init(BIN_PIN);
    gpio_set_dir(BIN_PIN, GPIO_IN);
    gpio_pull_up(BIN_PIN);

    // Inicializa comunicação serial
    stdio_init_all();

    while (true)
    {
        if (!gpio_get(BIN_PIN))
        {
            gpio_put(LED_PIN, 0);

            printf("Botão pressionado\n");
        }
        else
        {
            gpio_put(LED_PIN, 1);
            printf("Botão solto\n");
        }

        sleep_ms(500);
    }
}
