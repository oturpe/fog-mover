#include "Attiny2313Utils.h"

#include "config.h"

#include <avr/io.h>
#include <util/delay.h>

#include "ValveController.h"

ValveController::ValveController() {
}

ValveController::ValveController(
    uint8_t servoPin,
    uint16_t openPosition,
    uint16_t closedPosition
) :
    pin(servoPin),
    openPosition(openPosition),
    closedPosition(closedPosition),
    counter(0),
    delay(0),
    open(false),
    moving(false) {
}

void ValveController::run() {
    if (delay > 0) {
        delay--;
        return;
    }

    if (moving && ((counter % SERVO_SIGNAL_PERIOD) == 0)) {
        signalServo();
    }

    if (counter == SERVO_MOVE_PERIOD) {
        moving = false;
    }

    counter++;
}

void ValveController::setOpen(bool newOpen, uint16_t newDelay) {
    if (newOpen == open) {
        // Nothing to do
        return;
    }

    open = newOpen;
    moving = true;
    counter = 0;
    delay = newDelay;
}

// Wraps _delay_us so that is is adjustable.
void busyLoop(uint16_t delayUs) {
    #define UNIT_US 50

    int delayCounter = 0;
    while(delayCounter < delayUs) {
        _delay_us(UNIT_US);
        delayCounter += UNIT_US;
    }
}

void ValveController::signalServo() {
    PORTB |= BV(pin);

    if(open) {
        busyLoop(openPosition);
    }
    else {
        busyLoop(closedPosition);
    }

    PORTB &= ~BV(pin);
}
