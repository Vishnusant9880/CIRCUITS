// C++ code
//
int red = 6;
int green =3;
int blue = 5;
int sensor = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  
  int reading = analogRead(sensor);
  Serial.println(reading);
  if(reading >= 150)
  {
    digitalWrite(red,255);
  	digitalWrite(green,0);
    digitalWrite(blue,0);
  }
  if(reading <= 100)
  {
  	digitalWrite(red,0);
  	digitalWrite(green,255);
    digitalWrite(blue,0);
  }
  if(reading <= 85)
  {
  	digitalWrite(red,0);
  	digitalWrite(green,0);
    digitalWrite(blue,255);
  }
}