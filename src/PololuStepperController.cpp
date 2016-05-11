#include "Attiny2313Utils.h"

#include "config.h"

#include <avr/io.h>

#include "PololuStepperController.h"

PololuStepperController::PololuStepperController(uint16_t halfStep)
:
    counter(0),
    position(0),
    halfStep(halfStep),
    stepHigh(false) {
    setEnable(false);
    setDirection(true);
}

void PololuStepperController::setEnable(bool enable) {
    if (enable) {
        PORTA &= ~BV(PORTA1);
    } else {
        PORTA |= BV(PORTA1);
    }
}

void PololuStepperController::setDirection(bool newUpwards) {
    if (newUpwards) {
        // Assumption: start at the bottom
        position = 0;
        PORTD |= BV(PORTD0);
    } else {
        PORTD &= ~BV(PORTD0);
    }

    upwards = newUpwards;
}

void PololuStepperController::run() {
    counter++;

    if (
        (upwards && position >= BELLOW_HIGH_LIMIT) ||
        (!upwards && position <= BELLOW_LOW_LIMIT)
    ) {
        return;
    }

    if((halfStep == 1) || (counter % halfStep == 0)) {
        if(stepHigh) {
            PORTD &= ~BV(PORTD1);
        } else {
            PORTD |= BV(PORTD1);
            position += (upwards ? 1 : -1);
        }

        stepHigh = !stepHigh;
    }
}
