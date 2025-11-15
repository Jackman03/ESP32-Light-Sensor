#include <Arduino.h>
#define LIGHT_SENSOR_PIN 15
#define LED_PIN 18
#define MIN_LIGHT_LEVEL 2000
//#define MAX_LIGHT_LEVEL 4095
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  const float MAX_LIGHT_LEVEL = 4095.0;
  int LightLevel = analogRead(LIGHT_SENSOR_PIN);

  //this next step determines how bright the led is compared to the light sensor
  //the value of the photoresistor is between 0 and 4095 with the higher being more light coming in.
  //To power the led we need to take the current level as a % and find the invers %

  float InvLightPercent = 1.0 - (LightLevel / MAX_LIGHT_LEVEL);
  Serial.println(InvLightPercent);

  
  if (LightLevel <= MIN_LIGHT_LEVEL){
    digitalWrite(LED_PIN,HIGH);
  }
  else{
    digitalWrite(LED_PIN,LOW);
  }
    
  delay(500);
}

