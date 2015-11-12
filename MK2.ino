//vending machine program test
//Written by: Cormac McCann 06/11/2015

//libraries to include
#include <Servo.h> //Servo library

Servo servoOne;  // create servo object for servo 1
Servo servoTwo;  // create servo object  for servo 2

int pos = 0; //servo position stored as an int

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  servoOne.attach(9);  // attaches servo 1 on pin 9 to the servoOne object
  servoTwo.attach(10); // attaches servo 1 on pin 9 to the servoOne object
  
  // initialize digital pins 7 & 6 as outputs.
  pinMode(7, OUTPUT); //write 
  pinMode(6, OUTPUT); //write 
}

void loop() {
  digitalWrite(7, HIGH);   
  digitalWrite(6, HIGH);

  int sensorValueOne = analogRead(A0); //read value on analog pin 0
  int sensorValueTwo = analogRead(A1); //read value on analog pin 1
  
  // Convert analog value (0 - 1023) to a voltage (0-5 volts):
  float voltageOne = sensorValueOne * (5.0 / 1023.0);
  float voltageTwo = sensorValueTwo * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltageOne);
  Serial.println(voltageTwo);

  //when button is pressed voltage increases
  if(voltageOne >= 5.00){
     delay(500); //delay loop by 2.5 seconds
    Serial.print("PRESSED");

    //rotate servo  
    for (pos = 0; pos <= 180; pos += 2) { //from 0 to 180 
      servoOne.write(pos);                //rotate servo to value of pos
      delay(15);                          //15ms delay
    }
    for (pos = 180; pos >= 0; pos -= 2) { //from 180 to 0 
      servoOne.write(pos);                //rotate servo to value of pos
      delay(15);                          //15ms delay
    }   
  }

  //when button is pressed voltage increases
  if(voltageTwo >= 5.00){
    delay(500); //delay loop by 2.5 seconds
    Serial.print("PRESSED");

    //rotate servo  
    for (pos = 0; pos <= 180; pos += 2) { //from 0 to 180 
      // in steps of 1 degree
      servoTwo.write(pos);                //rotate servo to value of pos
      delay(15);                          //delay of 15ms
    }
    for (pos = 180; pos >= 0; pos -= 2) { //from 180 to 0
      servoTwo.write(pos);                //rotate servo to value of pos
      delay(15);                          //delay of 15ms
    }
  }
}

