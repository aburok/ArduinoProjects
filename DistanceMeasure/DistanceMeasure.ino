#define TRIGER_PIN 2
#define ECHO_PIN 3

#define TIME_PER_CENTIMETER 58
#define MIN_DISTANCE 2
#define MAX_DISTANCE 200

int EchoTime;
int Distance;

void setup()
{
	pinMode(TRIGER_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);

	Serial.begin(9600);

	/* add setup code here */

}

void loop()
{
	digitalWrite(TRIGER_PIN, LOW);
	delayMicroseconds(2);

	digitalWrite(TRIGER_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIGER_PIN, LOW);


	EchoTime = pulseIn(ECHO_PIN, HIGH);
	Distance = EchoTime / TIME_PER_CENTIMETER;

	if (MIN_DISTANCE <= Distance && Distance <= MAX_DISTANCE){
		Serial.print("Distance = ");
		Serial.print(Distance);
		Serial.println(" cm");
	}

	delay(100);
}
