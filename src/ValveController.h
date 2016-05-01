class ValveController {
public:
	/// \brief
	///    Initializes a new valve controller.
	///
	/// \param pin
	///    The pin in port B that controls the servo motor actuator.
	///
	/// \param counterStart
	///    Start position of counter
    void initialize(uint8_t pinn, uint64_t counterStart);

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

    /// Timestep counter
    uint64_t counter;

    /// If valve should be open.
    bool open;
};
