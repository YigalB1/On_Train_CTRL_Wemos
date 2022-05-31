#include <Arduino.h>


int OutLed_Pin = 0 ; // D3 == GPIO0
int IN1A_Pin = 12 ;  // D6 == GPIO12
int IN1B_Pin = 13 ;  // D7 == GPIO13
int IN2A_Pin =  4 ;  // D2 == GPIO4
int IN2B_Pin =  5 ;  // D1 == GPIO5
int EN1_Pin  = 14 ;  // D5 == GPIO14
int EN2_Pin  =  2 ;  // D4 == GPIO2
bool state = true;

class motor_control {

  public:
  int current_cmd;
  int motor_num;
  int motor_EN_pin;
  // each instance of class will have different motor
  // in this case we have one motor

  void go_fwd(int _speed) {
    digitalWrite(IN1A_Pin, LOW); // 
    digitalWrite(IN1B_Pin, HIGH); //
    analogWrite(EN1_Pin,_speed); 
  } // go_fwd()

    void go_back(int _speed) {
    digitalWrite(IN1A_Pin, HIGH); // 
    digitalWrite(IN1B_Pin, LOW); // 
    analogWrite(EN1_Pin,_speed);
  } // go_back()

}; // of class motor_control



// only one motor (Motor1) will be used in this case
motor_control motor1;

void setup() {
  Serial.begin(9600);
  pinMode(OutLed_Pin, OUTPUT);
  pinMode(IN1A_Pin, OUTPUT);
  pinMode(IN2A_Pin, OUTPUT);
  pinMode(IN1B_Pin, OUTPUT);
  pinMode(IN2B_Pin, OUTPUT);
  pinMode(EN1_Pin, OUTPUT);
  pinMode(EN2_Pin, OUTPUT);
  
} // of setup()

int from = 0;
int to = 255;
int inc = 10;


void loop() {

  Serial.println("LED is on");
  digitalWrite(OutLed_Pin, HIGH);  

  for (int spd=from;spd<to;spd+=inc) {
    motor1.go_fwd(spd);
    delay(400);
  } // of for()

  Serial.println("LED is off");
  digitalWrite(OutLed_Pin, LOW);  

  for (int spd=from;spd<to;spd+=inc) {
    motor1.go_back(spd);
    delay(400);
  } // of for()
  
  /*
  if (state==true) {

    //Serial.println("LED is on");
    //digitalWrite(OutLed_Pin, HIGH);
    state = false;
    //delay(400);
  } // of if()
  else {
    Serial.println("LED is OFF");
    digitalWrite(OutLed_Pin, LOW);
    state = true;
    delay(1000);
  } // of else()

  */
} // of loop()

