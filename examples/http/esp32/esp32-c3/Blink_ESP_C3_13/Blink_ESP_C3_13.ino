/*
  Date: 02.09.2023
  Device: ESP-C3-13
  Device Doc.: https://docs.ai-thinker.com/_media/esp32/docs/esp-c3-12f_specification.pdf
  Arduino IDE Board Select: ESP32C3 Dev Module
  Arduino IDE CPU Frequency: 160MHZ
  Arduino IDE Flash Size: 2MB
  Arduino IDE Partition Schema: 2MB

  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKRwait0 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

const int red = 3;
const int green = 4;
const int blue = 5;
const int white = 18;
const int white2 = 19;

int wait = 50;

void setup() {
  Serial.begin(115200);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(white2, OUTPUT);
}

void loop() {
  Serial.println("loop start");

  digitalWrite(red, HIGH);  
  delay(wait);                    
  digitalWrite(red, LOW);  
  delay(wait);                   

  digitalWrite(green, HIGH);  
  delay(wait);                      
  digitalWrite(green, LOW);   
  delay(wait);                      

  digitalWrite(blue, HIGH);  
  delay(wait);                      
  digitalWrite(blue, LOW);   
  delay(wait);                      

  digitalWrite(white, HIGH);  
  delay(wait);                      
  digitalWrite(white, LOW);   
  delay(wait);                      

  digitalWrite(white2, HIGH);  
  delay(wait);                      
  digitalWrite(white2, LOW);   
  delay(wait);                      
}
