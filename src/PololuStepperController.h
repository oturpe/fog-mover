/// \class PololuStepperController
///
/// Controls a stepper motor through Pololu stepper motor driver.
///
/// This class is hard coded to following pin configuration:
///    A1 - Enable
///    D0 - Direction
///    D1 - Step
///
class PololuStepperController {
public:
    /// \brief
    ///    Initializes a new Festo stepper controller.
    ///
    /// \param halfStep
    ///    Initial half step period
    PololuStepperController(uint16_t halfStep);

public:
    /// \brief
    ///    Sets motors enable state.
    ///
    /// \param enable
    ///    New enable state
    void setEnable(bool enable);

    /// \brief
    ///    Sets motor rotation direction.
    ///
    /// \param newUpwards
    ///    If bellow should move upwards
    void setDirection(bool newUpwards);

    /// \brief
    ///    Flips the step output. In other words, calling this function twice
    ///    makes to motor go exactly one step forward. In case a limit has
    ///    already been reached, does not do anything.
    void run();

    /// Tells if bellow was already up
    ///
    /// \return
    ///    If bellow was up
    bool bellowWasUp();

private:
    /// Internal counter for stepping speed control;
    uint16_t counter;

    /// Current position, given as steps from initial position.
    int16_t position;

    /// Current bellow movement direction: upwards or not
    bool upwards;

    /// Half of interval between two steps of the motor, given in units of calls
    /// to run() method.
    uint16_t halfStep;

    /// If step output is currently high
    bool stepHigh;
};
