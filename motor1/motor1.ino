int motorPin = 3;
int potencjometrPin = 5;
int potencjometrValue = 0;
int oldPotencjometrValue = 0;

void setup()
{
	pinMode(motorPin, OUTPUT);
	Serial.begin(9600);
	while (!Serial);
	Serial.println("Speed 0 to 255");
}


void loop()
{
	potencjometrValue = analogRead(potencjometrPin);
	delay(10);

	if (abs(oldPotencjometrValue - potencjometrValue) > 4){
		int motorSpeed = map(potencjometrValue, 0, 1023, 0, 255);

		Serial.println(motorSpeed);

		analogWrite(motorPin, motorSpeed);

		oldPotencjometrValue = potencjometrValue;

		delay(100);
	}

	if (Serial.available())
	{
		int speedMotor = Serial.parseInt();
		if (speedMotor >= 0 && speedMotor <= 255)
		{
			analogWrite(motorPin, speedMotor);
			Serial.print("Speed setup to");
			Serial.println(speedMotor);
		}
	}
}