// Cpu frequency for util/delay.h
#define F_CPU 8000000

// Half of delay in main execution loop, given in milliseconds.
#define LOOP_DELAY 2

// How to long wait at startup before doing anything. Given in milliseconds.
#define STARTUP_DELAY 5000

// Half length of indicator led on-off sequence. In other words, the time
// the indicator is lit and darkened. Given in units of LOOP_DELAY.
#define INDICATOR_HALF_PERIOD 250

// How long the fog machine is on until it switches off. Given in units of
// LOOP_DELAY.
#define FOG_ON_PERIOD 4000

// Servo half period. Given in units of LOOP_DELAY.
#define SERVO_HALF_PERIOD 4000

// Total length of one servo control period. Given in units of LOOP_DELAY
#define SERVO_SIGNAL_PERIOD 20

// Timespan that is long enough for a servo to complete single movement. Given
// in units of LOOP_DELAY.
#define SERVO_MOVE_PERIOD 150

// Length of servo control signal. Given in microseconds
// 1700 -middle
// higher -> move left
// Given individually for each servo, since they seem to react
// differently to the same signal
#define SERVO_1_TIME_OPEN 2000
#define SERVO_1_TIME_CLOSED 1200
#define SERVO_2_TIME_OPEN 1950
#define SERVO_2_TIME_CLOSED 1200
#define SERVO_3_TIME_OPEN 1800
#define SERVO_3_TIME_CLOSED 950

// Total amount of valves in the system
#define VALVE_COUNT 3

// Half the time between two steps of bellow. Given in units of LOOP_DELAY.
#define BELLOW_STEP_HALF_PERIOD 2

// Defines the maximal high and low displacement of bellow. Given in units of
/// bellow steps.
#define BELLOW_HIGH_LIMIT 2400
#define BELLOW_LOW_LIMIT 10

/// How many events can fit in the total choreography
#define CHOREOGRAPHY_LENGTH 8
