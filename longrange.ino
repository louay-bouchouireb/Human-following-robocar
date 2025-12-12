// Pin definitions
int in1 = 5;
int in2 = 18;
int enA = 17; 
int in3 = 19;
int in4 = 21;
int enB = 22;  // PWM for speed
int speed;
int TRIG = 15;
int ECHOc = 2;
int ECHOd = 4;
int TRIG2 = 23;
int TRIG3 = 26;
int ECHOr = 25 ;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHOc, INPUT);
  pinMode(ECHOd, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(TRIG3,OUTPUT);
  pinMode(ECHOr,INPUT);
}

void loop() {



  centrald();
  leftd();
  rightd();
  //float distancer = rightd();
  //float distance1 = leftd();
  //float distancec = centrald();

 

  float distanceC = centrald();
  float distanceL = leftd();
  float distanceR = rightd();

  // central sensor
  if(distanceC > 25 && distanceC < 80){
    forward(170);
  }
 // else if(distanceC < 5){
   // back(70);


  //}
  




  // left sensor
  else if(distanceL > 25 && distanceL < 80){
    right(100);
  }

  //right sensor
  else if(distanceR > 25 && distanceR < 80){
    left(100);
  }

  // no sensor
  else{
    stop();
  }

  delay(20);
}

void forward(int speed){
// Run motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);  // Speed (0–255)
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speed);
}

void back(int speed){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speed);
  
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void stopb(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}

void left(int speed){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speed);
}


void right(int speed){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speed);
}
//void right(){
  //backb();
//  forwarda(100);
//}


float centrald(){

  // Send a 10µs pulse on TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read how long the Echo pin stays HIGH
  long duration = pulseIn(ECHOc, HIGH,20000);

  // Convert time to distance (cm)
  float distancec = duration / 58.0;

  //Serial.print("Distanceright: ");
 // Serial.print(distancec);
  //Serial.println(" cm");

  delay(20);

  return distancec;
}

float leftd(){

  // Send a 10µs pulse on TRIG
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);

  // Read how long the Echo pin stays HIGH
  long duration2 = pulseIn(ECHOd, HIGH,20000);

  // Convert time to distance (cm)
  float distance1 = duration2 / 58.0;

  Serial.print("Distanceleft: ");
  Serial.print(distance1);
  Serial.println(" cm");

   delay(20);

  return distance1;
}

float rightd(){

  // Send a 10µs pulse on TRIG
  digitalWrite(TRIG3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG3, LOW);

  // Read how long the Echo pin stays HIGH
  long duration3 = pulseIn(ECHOr, HIGH,20000);

  // Convert time to distance (cm)
  float distancer = duration3 / 58.0;

  Serial.print("Distanceleft: ");
  Serial.print(distancer);
  Serial.println(" cm");

   delay(20);

  return distancer;
}