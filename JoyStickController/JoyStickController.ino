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
bool leftSw = 0;
bool rightSw = 0;

void setup()
{
	pinMode(RIGHT_JOYSTICK_SWITCH_PIN, INPUT);
	pinMode(LEFT_JOYSTICK_SWITCH_PIN, INPUT);

	Serial.begin(9600);
}

void loop()
{
	/* 1023 to reverse read */
	rightX = 1023 - analogRead(RIGHT_JOYSTICK_X_PIN);
	delayMicroseconds(100);
	rightY = analogRead(RIGHT_JOYSTICK_Y_PIN);
	delayMicroseconds(100);

	/* 1023 to reverse read  */
	leftX = 1023 - analogRead(LEFT_JOYSTICK_X_PIN);
	delayMicroseconds(100);
	leftY = analogRead(LEFT_JOYSTICK_Y_PIN);
	delayMicroseconds(100);

	leftSw = digitalRead(LEFT_JOYSTICK_SWITCH_PIN);
	rightSw = digitalRead(RIGHT_JOYSTICK_SWITCH_PIN);

	formatFrame();

	delay(100);
	/* add main program code here */
}

void formatFrame(){
	String formated = "{";
	formated += "'lx':";
	formated += leftX;
	formated += ",'ly':";
	formated += leftY;
	formated += ",'rx':";
	formated += rightX;
	formated += ",'ry':";
	formated += rightY;
	formated += ",'lsw':";
	formated += leftSw;
	formated += ",'rsw':";
	formated += rightSw;
	formated += "}";

	Serial.println(formated);
}
