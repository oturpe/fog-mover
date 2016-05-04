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
	///
	/// \param counterStart
	///    Start position of counter
    ValveController(
        uint8_t servoPin,
        uint16_t lowPos,
        uint16_t highPos,
        uint64_t counterStart
    );

public:

    /// \brief
    ///    Instructs the controller to advance one step in sequence, essentially
    ///    stepping the controller's clock.
    void run();

    /// \brief
    ///    Instructrs a servo motor to rotate its valve to desired position.
    ///
    /// \param open
    ///    If the valve should be open
    void setPosition(bool open);

private:
    /// Pin in port B this controller controls.
    uint8_t pin;

    /// Signal length to send the servo to low position. Given in
    /// microseconds.
    uint16_t lowPosition;

    /// Signal length to send the servo to high position. Given in
    /// microseconds.
    uint16_t highPosition;

    /// Timestep counter
    uint64_t counter;

    /// If valve should be open right now.
    bool open;
};
