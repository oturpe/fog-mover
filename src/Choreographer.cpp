#include <avr/io.h>

#include "Choreographer.h"
#include "FogGeneratorController.h"
#include "PololuStepperController.h"
#include "ValveController.h"

Choreographer::Choreographer(
    FogGeneratorController & fogMachine,
    PololuStepperController & bellow,
    ValveController & exitValve,
    ValveController & topValve,
    ValveController & bottomValve
) :
    fogMachine(fogMachine),
    bellow(bellow),
    exitValve(exitValve),
    topValve(topValve),
    bottomValve(bottomValve),
    counter(0) {
    /*
    for(uint8_t index = 0; index < CHOREOGRAPHY_LENGTH; index++) {
        instants[index] = 0;
        events[index] = NONE;
    }
    */
}

void Choreographer::registerEvent(uint64_t instant, Event event) {
    uint8_t index = 0;
    while (instants[index]) {
        index++;
    }

    instants[index] = instant;
    events[index] = event;
}

void Choreographer::run() {
    counter++;

    uint8_t index = 0;
    uint32_t instant = instants[index];
    while(instant) {
        if (counter == instant) {
            runEvent(events[index]);
        }

        instant = instants[++index];
    }

    fogMachine.run();
    bellow.run();
    exitValve.run();
    topValve.run();
    bottomValve.run();
}

void Choreographer::runEvent(Event event) {
    switch (event) {
    case NONE:
        return;

    case BLOW_FOG:
        fogMachine.blow();
        return;

    case PULL_FOG:
        bellow.setDirection(true);
        bellow.setEnable(true);
        exitValve.setOpen(true, 0);
        topValve.setOpen(true, 2 * SERVO_MOVE_PERIOD);
        bottomValve.setOpen(false, 3 * SERVO_MOVE_PERIOD);
        return;

    case LOWER_BELLOW:
        bellow.setDirection(false);
        bellow.setEnable(false);
        exitValve.setOpen(false,0);
        topValve.setOpen(true, 2 * SERVO_MOVE_PERIOD);
        bottomValve.setOpen(false, 3 * SERVO_MOVE_PERIOD);
        return;

    case END:
        counter = 0;
        return;
    }
}