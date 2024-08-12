int motor1pin1 = 0; //D3
int motor1pin2 = 2; //D4

int motor2pin1 = 14; //D5
int  motor2pin2 = 12; //D6

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:

  //Controlling speed (0  = off and 255 = max speed):     
  //(Optional)
  analogWrite(5, 230); //ENA  pin 5 = D1
  analogWrite(4, 230); //ENB pin 4 = D2
  //(Optional)
  
  digitalWrite(motor1pin1,  HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
//  delay(3000);
//
//  digitalWrite(motor1pin1,  LOW);
//  digitalWrite(motor1pin2, HIGH);
//
//  digitalWrite(motor2pin1, LOW);
//  digitalWrite(motor2pin2, HIGH);
//  delay(3000);
}
