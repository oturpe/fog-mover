// Fog mover
//
// Moves fog around
// TODO: More detailed description
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
    valves[0].initialize(PORTB4, 0);
    valves[1].initialize(PORTB5, SERVO_HALF_PERIOD/4);
    valves[2].initialize(PORTB6, (SERVO_HALF_PERIOD*2)/4);
    valves[3].initialize(PORTB7, (SERVO_HALF_PERIOD*3)/4);

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
