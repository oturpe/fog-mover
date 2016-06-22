#include "config.h"

class FogGeneratorController;
class PololuStepperController;
class ValveController;

enum Event {
    // Nothing happens.
    NONE,
    // Fog machine starts to blow fog.
    BLOW_FOG,
    // Bellow raises and stays up, path from above tree to exit opens.
    PULL_FOG,
    // Bellow goes down.
    LOWER_BELLOW,
    // Signals the end of choreography. Starts from the beginning again.
    END
};

/// \class Choreographer
///
/// Allows defining and executing a fog moving choreography. Events from Event
/// enumeration are registered to specified instants using registerEvent()
/// function. Each time run() is called, internal counter is incremented and
/// events corresponding to counter value are run.
class Choreographer {
public:
    /// \brief
    ///    Initializes a choreographer with references to all components.
    ///
    /// \param fogMachine
    ///    Controls fog release
    ///
    /// \param bellow
    ///    Controls bellow movements
    ///
    /// \param exitValve
    ///    Controls valve that leads from bellow to open air
    ///
    /// \param topValve
    ///    Controls valve that leads from above tree to bellow
    ///
    /// \param bottomValve
    ///    Controls valve that leads from below tree to bellow
    Choreographer(
        FogGeneratorController & fogMachine,
        PololuStepperController & bellow,
        ValveController & exitValve,
        ValveController & topValve,
        ValveController & bottomValve
    );

public:
    /// \brief
    ///    Registers a new event in choreography.
    ///
    /// The event is ran when run() function is called and the counter is in
    /// given position.
    void registerEvent(uint64_t instant, Event event);

    /// \brief
    ///    Increases the counter and runs the corresponding event if found from
    ///    the events list.
    void run();

private:
    /// \brief
    ///    Runs the given event
    void runEvent(Event event);

private:
    /// Controls fog release
    FogGeneratorController & fogMachine;

    /// Controls bellow movements
    PololuStepperController & bellow;

    /// Controls valve that leads from bellow to open air
    ValveController & exitValve;

    /// Controls valve that leads from above tree to bellow
    ValveController & topValve;

    /// Controls valve that leads from below tree to bellow
    ValveController & bottomValve;

    /// Counter for choreography progress
    uint32_t counter;

    /// Instants when corresponding events from events variable occur
    uint32_t instants[CHOREOGRAPHY_LENGTH];

    /// Events that are in the choreography
    Event events[CHOREOGRAPHY_LENGTH];
};
