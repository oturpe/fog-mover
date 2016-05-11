#include "Attiny2313Utils.h"

#include "config.h"

#include <avr/io.h>

#include "FogGeneratorController.h"

FogGeneratorController::FogGeneratorController() {
}

void FogGeneratorController::blow() {
    PORTD |= BV(PORTD4);
    puffing = true;
    counter = 0;
}

void FogGeneratorController::run() {
    if (counter > FOG_ON_PERIOD) {
        return;
    }

    if (counter == FOG_ON_PERIOD) {
        PORTD &= ~BV(PORTD4);
    }

    counter++;
}
