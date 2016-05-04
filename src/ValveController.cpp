#include "Attiny2313Utils.h"

#include "config.h"

#include <avr/io.h>
#include <util/delay.h>

#include "ValveController.h"

ValveController::ValveController() {
}

ValveController::ValveController(
    uint8_t servoPin,
    uint16_t lowPos,
    uint16_t highPos,
    uint64_t counterStart
) :
    pin(servoPin),
    lowPosition(lowPos),
    highPosition(highPos),
    counter(counterStart),
    open(false) {
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

// Wraps _delay_us so that is is adjustable.
void delay(uint16_t delayUs) {
    #define UNIT_US 50

    int counter = 0;
    while(counter < delayUs) {
        _delay_us(UNIT_US);
        counter += UNIT_US;
    }
}

void ValveController::setPosition(bool open) {
    PORTB |= BV(pin);

    if(open) {
        delay(lowPosition);
    }
    else {
        delay(highPosition);
    }

    PORTB &= ~BV(pin);
}
