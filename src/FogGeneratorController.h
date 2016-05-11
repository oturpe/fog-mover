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
    FogGeneratorController();

public:
    /// \brief
    ///    Tells the generator to start blowing. Blowing continues for period
    ///    defined by onPeriod member variable.
    void blow();

    /// \brief
    ///    Instructs the controller to advance one step in sequence, essentially
    ///    stepping the controller's clock.
    void run();

private:
    /// Counts how long fog has been blown
    uint16_t counter;

    /// Remaining repeats
    uint8_t repeats;

    /// If fog is running right now
    bool puffing;
};