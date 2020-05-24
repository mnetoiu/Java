#include <SoftwareSerial.h>
#include <SimpleDHT.h>

SoftwareSerial MyBlue(2, 3); // RX | TX 
int pinDHT11 = 7;
SimpleDHT11 dht11;
int sensorPin = 2; //define analog pin 2 for light sensor
int sensorCO = 0; // define analog pin 0 for CO sensor
int light = 0; 
int valueCO;
void setup() {
  Serial.begin(9600);
  MyBlue.begin(9600);  //Baud Rate for AT-command Mode.  
}

void loop() {
  // read light sensor and DHT
  light = (1023 - analogRead(sensorPin)) / 10.2;
  valueCO = analogRead(sensorCO);
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
 
  Serial.print("Temperature: ");
  Serial.print((int)temperature); Serial.println(" °C"); 
  MyBlue.print((int)temperature); MyBlue.print(" °C"); 
  MyBlue.print("|");
  Serial.print("Humidity: ");
  Serial.print((int)humidity); Serial.println(" %");
  MyBlue.print((int)humidity); MyBlue.print(" %");
  MyBlue.print("|");
  Serial.print("Luminosity: ");
  Serial.println(light, DEC); // light intensity  
  MyBlue.print(light, DEC); MyBlue.print(" %"); // light intensity   
  MyBlue.print("|");
  Serial.print("CO value: ");
  Serial.println(valueCO, DEC); // light intensity  
  MyBlue.print(valueCO, DEC); // light intensity   

  // DHT11 sampling rate is 1HZ.
  delay(10000);
}
