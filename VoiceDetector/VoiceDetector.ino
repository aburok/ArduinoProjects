#define VOICE_PIN 0


void setup()
{
	pinMode(VOICE_PIN, INPUT);
	
	Serial.begin(9600);

  /* add setup code here */

}

void loop()
{
	int soundLevel = analogRead(VOICE_PIN);

	Serial.println(soundLevel);

	delay(1000);
  /* add main program code here */

}
