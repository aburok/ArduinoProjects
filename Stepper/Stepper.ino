//#include <Stepper.h>
#include <AccelStepper.h>

#define PIN_BLUE 8
#define PIN_PINK 9
#define PIN_YELLOW 10
#define PIN_ORANGE 11

#define MOTOR_RATIO 64
#define SHAFT_RATIO 32
#define STEPS_PER_REVOLUTION 64 * 32

#define SPEED_PIN 0

#define HALF_STEP 8

AccelStepper stepper(HALF_STEP, PIN_BLUE, PIN_YELLOW, PIN_PINK, PIN_ORANGE);

void setup()
{

	/* add setup code here */
	stepper.setSpeed(200);
	stepper.setMaxSpeed(1000);
	stepper.setAcceleration(100);

	stepper.moveTo(STEPS_PER_REVOLUTION);
}

void loop()
{
	int speedRead = analogRead(SPEED_PIN);

	int speed = map(speedRead, 0, 1024, 0, 1000);
	stepper.setSpeed(speedRead);

	if (stepper.distanceToGo() == 0){
		stepper.moveTo(-STEPS_PER_REVOLUTION);
	}
	/* add main program code here */

	stepper.run();
}
