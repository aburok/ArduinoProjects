#define SWITCH_PIN 9

void setup()
{
	pinMode(SWITCH_PIN, OUTPUT);

  /* add setup code here */

}

void loop()
{

	digitalWrite(SWITCH_PIN, HIGH);
	delay(1000);

	digitalWrite(SWITCH_PIN, LOW);
	delay(1000);
  /* add main program code here */

}
