#define RIGHT_JOYSTICK_X_PIN 0 
#define RIGHT_JOYSTICK_Y_PIN 1
#define RIGHT_JOYSTICK_SWITCH_PIN 3 

#define LEFT_JOYSTICK_X_PIN 3 
#define LEFT_JOYSTICK_Y_PIN 2 
#define LEFT_JOYSTICK_SWITCH_PIN 2 


int rightX = 0;
int rightY = 0;
int leftX = 0;
int leftY = 0;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

#define COMMON_ANODE

void setup()
{
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}

void loop()
{

	/* 1023 to reverse read */
	rightX = abs(1023 - analogRead(RIGHT_JOYSTICK_X_PIN) - 515);
	delayMicroseconds(100);
	rightY =abs( analogRead(RIGHT_JOYSTICK_Y_PIN) - 515);
	delayMicroseconds(100);

	/* 1023 to reverse read  */
	leftX = abs(1023 - analogRead(LEFT_JOYSTICK_X_PIN) - 515);
	delayMicroseconds(100);
	leftY = analogRead(LEFT_JOYSTICK_Y_PIN);
	delayMicroseconds(100);

	int red = map(rightX, 0, 515, 0, 255);
	int green = map(rightY, 0, 515, 0, 255);
	int blue = map(leftX, 0, 515, 0, 255);

	setColor(red, green, blue);
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
	red = 255 - red;
	green = 255 - green;
	blue = 255 - blue;
#endif
	analogWrite(redPin, red);
	analogWrite(greenPin, green);
	analogWrite(bluePin, blue);
}