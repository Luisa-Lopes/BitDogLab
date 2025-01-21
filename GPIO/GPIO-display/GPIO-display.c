#include "pico/stdlib.h"

const uint8_t segment_pins[] = {0, 1, 2, 3, 4, 5, 6}; // a,b,c,d,e,f,g

const uint8_t digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
};

void display_digit(uint8_t digit)
{
    for (int i = 0; i < 7; i++)
    {
        gpio_put(segment_pins[i], digits[digit][i]);
    }
}

int main()
{

    for (int i = 0; i < 7; i++)
    {
        gpio_init(segment_pins[i]);
        gpio_set_dir(segment_pins[i], GPIO_OUT);
    }

    uint8_t contador = 0;

    while (true)
    {
        display_digit(contador);
        sleep_ms(1000);
        contador++;
        if (contador > 9)
        {
            contador = 0;
        }
    }
    return 0;
}