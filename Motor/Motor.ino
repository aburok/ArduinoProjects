int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
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
