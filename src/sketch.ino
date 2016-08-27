//This imports the motor controller library to make it easier to control the motors
#include <RedBot.h>

//Define pins here (or don't, i'm a sign not a cop)
#define LINE_SENSOR_PIN A2
#define IR_SENSOR_PIN A1 //This is an analog pin (meaning it can have more than a 1 or 0 value)

const int WHITE_LINE_THRESHOLD = 500;
const int MAX_DISTANCE_THRESHOLD = 800;

//Insantiate the motors
RedBotMotors motors; 

//The arduino lifecycle is pretty simple
//Basically it calls setup and then loop over and over 

void setup(){
  //Set the pin mode so the board knows your using inputs
  pinMode(LINE_SENSOR_PIN, INPUT);
  pinMode(IR_SENSOR_PIN, INPUT);
}

int readLineSensor(){
  return analogRead(LINE_SENSOR_PIN);
}

int readIRSensor(){
  return analogRead(LINE_SENSOR_PIN);
}

boolean isLineThere(){
  int reading = readLineSensor(); //Take a reading of what the line sensor sees
  if(reading > WHITE_LINE_THRESHOLD){ //If the reflected amount of light is greater than an arbitrary threshold, then you see white
    return true;
  }
  else{
    return false;
  }
}

boolean isRobotInFrontOfUs(){
  int reading = readIRSensor(); //Take a reading of what the line sensor sees
  if(reading < MAX_DISTANCE_THRESHOLD){ //If the robot is less than a certain distance away, consider it in front of us (too much and it could just be noise or a person standing next to the ring)
    return true;
  }
  else{
    return false;
  }
}

void loop(){
  if(isLineThere()){
    motors.pivot(255,random(255));
  }
  else if(isRobotInFrontOfUs()){
    motors.drive(255);
  }
  else {
    motors.drive(100);
  }
}

