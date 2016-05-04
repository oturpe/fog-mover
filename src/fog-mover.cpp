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

#include "ValveController.h"

#ifdef DEBUG
#include "Debug.h"
#endif

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

int main() {
    #ifdef DEBUG
        /* TODO: implement debugging
        Debug debug(DEBUG_FREQ);
        */
    #endif

    // Set output pins:
    //    D6 (indicator)
    //    B4, B5, B6, B7 (servo control)
    DDRD |= BV(DDD6);
    DDRB |= BV(DDB4) | BV(DDB5) | BV(DDB6) | BV(DDB7);

    ValveController valves[VALVE_COUNT];
    valves[0] = ValveController(
        PORTB4,
        SERVO_1_TIME_LOW,
        SERVO_1_TIME_HIGH,
        0
    );

    valves[1] = ValveController(
        PORTB5,
        SERVO_2_TIME_LOW,
        SERVO_2_TIME_HIGH,
        SERVO_HALF_PERIOD/4
    );

    valves[2] = ValveController(
        PORTB6,
        SERVO_3_TIME_LOW,
        SERVO_3_TIME_HIGH,
        (SERVO_HALF_PERIOD*2)/4
    );

    valves[3] = ValveController(
        PORTB7,
        SERVO_4_TIME_LOW,
        SERVO_4_TIME_HIGH,
        (SERVO_HALF_PERIOD*3)/4
    );

    bool indicatorLit = false;
    uint64_t counter = 0;

    while(true) {
        counter += 1;
        _delay_us(LOOP_DELAY);

        if(counter % INDICATOR_HALF_PERIOD == 0) {
            indicatorLit = !indicatorLit;
            setIndicator(indicatorLit);
        }

        for(int i = 0; i < VALVE_COUNT; i++) {
            valves[i].run();
        }
    }
}
