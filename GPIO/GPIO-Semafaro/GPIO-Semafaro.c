#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE_PIN 11
#define LED_VERMELHO_PIN 13
#define BUTTON_B_PIN 6

bool ciclo_ativo = false;

void iniciar_ciclo()
{

    gpio_put(LED_VERDE_PIN, 1);
    gpio_put(LED_VERMELHO_PIN, 1);
    sleep_ms(5000);
    gpio_put(LED_VERDE_PIN, 0);
    gpio_put(LED_VERMELHO_PIN, 0);

    gpio_put(LED_VERMELHO_PIN, 1);
    sleep_ms(5000);
    gpio_put(LED_VERMELHO_PIN, 0);
}

int main()
{
    stdio_init_all();

    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);

    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);

    while (true)
    {
        gpio_put(LED_VERDE_PIN, 1);
        if (!gpio_get(BUTTON_B_PIN))
        {
            ciclo_ativo = true;
        }

        if (ciclo_ativo)
        {
            gpio_put(LED_VERDE_PIN, 0);
            iniciar_ciclo();
            sleep_ms(5000);
            ciclo_ativo = false;
        }
    }
    return 0;
}
