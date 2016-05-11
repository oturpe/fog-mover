/// \class ValveController
///
/// Runs a single valve that is actuated by a hobby servo. Expects regularly
/// spaced calls to run() which acts as the clock of this class. Calling run()
/// blocks if the controller decides that is it the time to send a new signal
/// to servo.
class ValveController {
public:
    /// \brief
    ///    Initializes a new valve controller without setting values. This is
    ///    not very useful constructor, but required by array initialization.
    ValveController();

    /// \brief
    ///    Initializes a new valve controller.
    ///
    /// \param servoPin
    ///    The pin in port B that controls the servo motor actuator.
    ValveController(
        uint8_t servoPin,
        uint16_t openPosition,
        uint16_t closedPosition
    );

public:
    /// \brief
    ///    Instructs the controller to advance one step in sequence, essentially
    ///    stepping the controller's clock.
    void run();

    /// \brief
    ///    Instructs the servo to assume the given position.
    ///
    /// \param newOpen
    ///    If the new position is the open position
    ///
    /// \param newDelay
    ///    How long to wait before starting move
    void setOpen(bool newOpen,uint16_t newDelay);

private:
    /// \brief
    ///    Instructrs a servo motor to rotate its valve to current desired
    ///    position as defined by value of member variable open.
    void signalServo();

private:
    /// Pin in port B this controller controls.
    uint8_t pin;

    /// Signal length to send the servo to open position. Given in
    /// microseconds.
    uint16_t openPosition;

    /// Signal length to send the servo to closed position. Given in
    /// microseconds.
    uint16_t closedPosition;

    /// Timestep counter
    uint32_t counter;

    /// Delay before starting to move
    uint16_t delay;

    /// If valve is right now moving to a new position.
    bool moving;

public: //temp?
    /// If valve should be open right now.
    bool open;
};
