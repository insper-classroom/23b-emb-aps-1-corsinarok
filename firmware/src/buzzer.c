#include "buzzer.h"
#include "pio.h"

void set_buzzer() {
    pio_set(BUZ_PIN_PIO, BUZ_PIN_MASK);
}

void clear_buzzer() {
    pio_clear(BUZ_PIN_PIO, BUZ_PIN_MASK);
}