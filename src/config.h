// Cpu frequency for util/delay.h
#define F_CPU 1000000

// Half of delay in main execution loop, given in microseconds.
#define LOOP_DELAY 1000

// Half length of indicator led on-off sequence. In other words, the time
// the indicator is lit and darkened. Given in units of LOOP_DELAY.
#define INDICATOR_HALF_PERIOD 500

// Servo half period. Given in units of servo signals (~SERVO_SIGNAL_PERIOD).
#define SERVO_HALF_PERIOD 250

// Time estimated to be needed for a servo to complete its movement.
// Given in units of LOOP_DELAY. This value is used to select the active
// servo only after the previous one has completed its movement.
#define SERVO_MOVE_PERIOD 1000

// Total length of one servo control period. Given in units of LOOP_DELAY
#define SERVO_SIGNAL_PERIOD 20

// Length of servo control signal.Given in microseconds
// 1700 -middle
// higher -> move counter clockwise
#define SERVO_TIME_LOW 1100
#define SERVO_TIME_HIGH 1900

// Total amount of valves in the system
#define VALVE_COUNT 4

//Enables debug messaging
#define DEBUG
