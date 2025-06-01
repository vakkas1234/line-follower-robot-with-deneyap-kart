#define SensorSol A0
#define SensorOrta A1
#define SensorSag A2

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7
void setup() {
  pinMode(SensorSol,INPUT);
  pinMode(SensorSag,INPUT);
  pinMode(SensorOrta,INPUT);
  Serial.begin(115200);
  Serial.println("Cizgi İzleme Test");
  delay(2000);

  pinMode(motorR1,OUTPUT);
  pinMode(motorR2,OUTPUT);
  pinMode(motorRE,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);
  pinMode(motorLE,OUTPUT);
    // setup kodlarını buraya ekleyin
  }
            
void loop() {
    Serial.print(digitalRead(SensorSol));
    Serial.print(",");
    Serial.print(digitalRead(SensorOrta));
    Serial.print(",");
    Serial.print(digitalRead(SensorSag));
delay(400);
  if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta)== 1 && digitalRead(SensorSag)== 0) {

    ileri();
  }
  if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta)== 0 && digitalRead(SensorSag)== 1) {

    sag();
  }
 if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta)== 0 && digitalRead(SensorSag)== 0) {

    dur();
  }
  
  }

void ileri(){
  digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    analogWrite(motorRE,125);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    analogWrite(motorLE,125);
}

void sag(){
  digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    analogWrite(motorRE,125);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    analogWrite(motorLE,150);
}

void sol(){
  digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    analogWrite(motorRE,150);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    analogWrite(motorLE,125);
}
void dur(){
  digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    analogWrite(motorRE,0);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    analogWrite(motorLE,0);
}