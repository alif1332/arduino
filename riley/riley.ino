void setup(){
  Serial.begin(115200);
  pinMode(16,OUTPUT);
  digitalWrite(16, 1);
}

void loop (){
  digitalWrite(16,0);
  delay (5000);
  digitalWrite(16, 1);
  delay (3000);
}
