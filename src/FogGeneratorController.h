/// \class FogGeneratorController
///
/// Controls a fog machine by triggering a transistor that has been placed
/// parallel to the original mechanical button.
///
/// The output pin is hard coded as PD4.
class FogGeneratorController {
public:
    /// \brief
    ///    Initializes a new fog generator controller
    ///
    /// \param offPeriod
    ///    How long the trigger remains off when switched off
    ///
    /// \param onPeriod
    ///    How long the trigger remains off when switched on
    FogGeneratorController(uint16_t offPeriod, uint16_t onPeriod);

public:
    /// \brief
    ///    Instructs the controller to advance one step in sequence, essentially
    ///    stepping the controller's clock.
    void run();

private:
    /// How long fog generation remains off
    const uint16_t offPeriod;

    /// How long fog generation remains on
    const uint16_t onPeriod;

    uint64_t counter;
    /// If the trigger is on right now
    bool on;
};