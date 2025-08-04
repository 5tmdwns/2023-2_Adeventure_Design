#include <Adafruit_NeoPixel.h>

#define PIN 52
#define NUM_PIXELS 8

const int redPin = 22;     
const int yellowPin = 24;  
const int greenPin = 26;   

const int cdsPin1 = A0;   
const int cdsPin2 = A1;   
const int cdsPin3 = A2;   
const int cdsPin4 = A3;

const int sensorPin1 = 49;
const int sensorPin2 = 51;
const int sensorPin3 = 53;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() 
{
  pixels.begin();
  pixels.setBrightness(150);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  for(int i = 0; i < NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255, 255));
  }
  pixels.show();

  int cdsValue1 = analogRead(cdsPin1);  
  int cdsValue2 = analogRead(cdsPin2);   
  int cdsValue3 = analogRead(cdsPin3);  
  int cdsValue4 = analogRead(cdsPin4);

  int sensorValue1 = digitalRead(sensorPin1);
  int sensorValue2 = digitalRead(sensorPin2);
  int sensorValue3 = digitalRead(sensorPin3);


  int totalCdsValue = cdsValue1 + cdsValue2 + cdsValue3 + cdsValue4;
  int totalSensorValue = sensorValue1 + sensorValue2 + sensorValue3;

  Serial.print("Totalcdsvalue: ");
  Serial.println(totalCdsValue);
  Serial.print("Totalsensorvalue: ");
  Serial.println(totalSensorValue);


  if (totalCdsValue > 2000) 
  {
    if(totalSensorValue == 3)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    else
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
    }
  } 

  else if (totalCdsValue > 1350) 
  {
    if(totalSensorValue == 3)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    else if(totalSensorValue == 2)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    else if(totalSensorValue == 1)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    else
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
    }
  } 

  else if(totalCdsValue > 1000)
  {
    if(totalSensorValue == 3)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    else if(totalSensorValue == 2)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    else if(totalSensorValue == 1)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    else
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
  }

  else 
  {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  delay(100);  
}