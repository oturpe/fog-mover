#include "Attiny2313Utils.h"

#include "config.h"

#include <avr/io.h>
#include <util/delay.h>

#include "ValveController.h"

void ValveController::initialize(
    uint8_t pinn,
    uint64_t counterStart
) {
    pin = pinn;
    counter = counterStart;
    open = false;
}

void ValveController::run() {
    counter++;

    if (counter % SERVO_SIGNAL_PERIOD) {
        setPosition(open);
    }

    if (counter % SERVO_HALF_PERIOD == 0) {
        open = !open;
    }
}

void ValveController::setPosition(bool open) {
    PORTB |= BV(pin);

    if(open) {
        _delay_us(SERVO_TIME_HIGH);
    }
    else {
        _delay_us(SERVO_TIME_LOW);
    }

    PORTB &= ~BV(pin);
}
