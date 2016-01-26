/* YourDuino.com Example Software Sketch
   Small Stepper Motor and Driver V1.3 11/30/2013
   http://arduino-direct.com/sunshop/index.php?l=product_detail&p=126
   Shows 4-step sequence, Then 1/2 turn and back different speeds
   terry@yourduino.com */

/*-----( Import needed libraries )-----*/
//#include <Stepper.h>
#include <AccelStepper.h>

/*-----( Declare Constants, Pin Numbers )-----*/
//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

/*-----( Declare objects )-----*/
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

//The pin connections need to be 4 pins connected
// to Motor Driver In1, In2, In3, In4  and then the pins entered
// here in the sequence 1-3-2-4 for proper sequencing
//Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

#define FULLSTEP 4
#define HALFSTEP 8
// motor pins
#define motorPin1  8     // Blue   - 28BYJ48 pin 1
#define motorPin2  9     // Pink   - 28BYJ48 pin 2
#define motorPin3  10     // Yellow - 28BYJ48 pin 3
#define motorPin4  11     // Orange - 28BYJ48 pin 4

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

/*-----( Declare Variables )-----*/
int  Steps2Take;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  stepper1.setMaxSpeed(100.0);
  stepper1.setAcceleration(10.0);
  stepper1.setSpeed(50);
  stepper1.moveTo(STEPS_PER_OUTPUT_REVOLUTION * 10);  // 1 revolution 
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
    if (stepper1.distanceToGo() == 0) 
    stepper1.moveTo(-stepper1.currentPosition());
    
//  small_stepper.setSpeed(1);   // SLOWLY Show the 4 step sequence 
//  Steps2Take  =  4;  // Rotate CW
//  small_stepper.step(Steps2Take);
//  delay(2000);
//
//  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION / 2;  // Rotate CW 1/2 turn
//  small_stepper.setSpeed(100);   
//  small_stepper.step(Steps2Take);
//  delay(1000);
  
//  Steps2Take  =  - STEPS_PER_OUTPUT_REVOLUTION / 2;  // Rotate CCW 1/2 turn  
//  small_stepper.setSpeed(700);  // 700 a good max speed??
//  small_stepper.step(Steps2Take);
  stepper1.run();
  


}/* --(end main loop )-- */

/* ( THE END ) */
