#include "Attiny2313Utils.h"

#include <avr/io.h>

#include "FogGeneratorController.h"

FogGeneratorController::FogGeneratorController(
    uint16_t offPeriod,
    uint16_t onPeriod
) :
    offPeriod(offPeriod),
    onPeriod(onPeriod),
    counter(0),
    on(false) {
}

void FogGeneratorController::run() {
    counter++;

    if (!on && counter == offPeriod) {
        PORTD |= BV(PORTD4);
        counter = 0;
        on = true;

        return;
    }

    if (on && counter == onPeriod) {
        PORTD &= ~BV(PORTD4);
        counter = 0;
        on = false;

        return;
    }
}
