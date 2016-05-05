// Cpu frequency for util/delay.h
#define F_CPU 1000000

// Half of delay in main execution loop, given in microseconds.
#define LOOP_DELAY 1000

// Half length of indicator led on-off sequence. In other words, the time
// the indicator is lit and darkened. Given in units of LOOP_DELAY.
#define INDICATOR_HALF_PERIOD 500

// How long the fog machine is off until it next switches on. Given in units of
// LOOP_DELAY.
#define FOG_OFF_PERIOD 500

// How long the fog machine is on until it switches off. Given in units of
// LOOP_DELAY.
#define FOG_ON_PERIOD 150

// Servo half period. Given in units of servo signals (~SERVO_SIGNAL_PERIOD).
#define SERVO_HALF_PERIOD 250

// Time estimated to be needed for a servo to complete its movement.
// Given in units of LOOP_DELAY. This value is used to select the active
// servo only after the previous one has completed its movement.
#define SERVO_MOVE_PERIOD 1000

// Total length of one servo control period. Given in units of LOOP_DELAY
#define SERVO_SIGNAL_PERIOD 20

// Length of servo control signal. Given in microseconds
// 1700 -middle
// higher -> move clockwise
// Given individually for each servo, since they seem to react
// differently to the same signal
#define SERVO_1_TIME_LOW 1000
#define SERVO_1_TIME_HIGH 1950
#define SERVO_2_TIME_LOW 1100
#define SERVO_2_TIME_HIGH 1850
#define SERVO_3_TIME_LOW 1150
#define SERVO_3_TIME_HIGH 1950
#define SERVO_4_TIME_LOW 750
#define SERVO_4_TIME_HIGH 1500

// Total amount of valves in the system
#define VALVE_COUNT 4

//Enables debug messaging
#define DEBUG
