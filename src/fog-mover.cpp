// Fog mover
//
// Moves fog around pipes and bottles by controlling a set of valves, a fog
// machine and a motor moving a bellow up and down.
//
// Created on: 2016-05-01
// Author: Otto Urpelainen
// Email: oturpe@iki.fi

#include "Attiny2313Utils.h"

#include "config.h"

#include <avr/io.h>
#include <util/delay.h>

#include "PololuStepperController.h"
#include "FogGeneratorController.h"
#include "ValveController.h"
#include "Choreographer.h"

/// \brief
///    Turns th indicator led on of off
///
/// \param lit
///    If led is turned on. Otherwise it is turned off.
inline void setIndicator(bool lit) {
  if (lit)
    PORTD |= BV(PORTD6);
  else
    PORTD &= ~BV(PORTD6);
}

FogGeneratorController generatorController;

PololuStepperController motorController(BELLOW_STEP_HALF_PERIOD);

ValveController exitValve(
    PORTB4,
    SERVO_1_TIME_OPEN,
    SERVO_1_TIME_CLOSED
);

ValveController topValve(
    PORTB5,
    SERVO_2_TIME_OPEN,
    SERVO_2_TIME_CLOSED
);

ValveController bottomValve(
    PORTB6,
    SERVO_3_TIME_OPEN,
    SERVO_3_TIME_CLOSED
);

Choreographer choreographer(
    generatorController,
    motorController,
    exitValve,
    topValve,
    bottomValve
);

int main() {
    // Set output pins:
    //    D0, D1, A1 (motor control)
    //    D4 (fog generator trigger)
    //    D6 (indicator)
    //    B4, B5, B6, B7 (servo control)
    DDRA |= BV(1);
    DDRB |= BV(DDB4) | BV(DDB5) | BV(DDB6) | BV(DDB7);
    DDRD |= BV(DDD0)| BV(DDD1) | BV(DDD2) | BV(DDD3) | BV(DDD4) | BV(DDD6);

    exitValve.setOpen(false, 0);
    topValve.setOpen(false, SERVO_MOVE_PERIOD);
    bottomValve.setOpen(false, 2*SERVO_MOVE_PERIOD);

    choreographer.registerEvent(1, BLOW_FOG);
    choreographer.registerEvent(4500, PULL_FOG);
    choreographer.registerEvent(27000, LOWER_BELLOW);
    choreographer.registerEvent(60000, END);

    bool indicatorLit = true;
    uint32_t counter = 0;

    _delay_ms(STARTUP_DELAY);

    while(true) {
        counter += 1;
        _delay_ms(LOOP_DELAY);

        if(counter % INDICATOR_HALF_PERIOD == 0) {
            indicatorLit = !indicatorLit;
            setIndicator(indicatorLit);
        }

        choreographer.run();
    }
}