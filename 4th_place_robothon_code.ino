#define m1 2
#define m2 3
#define m3 4 
#define m4 5
#define e1 9
#define e2 10

#define ir1 A0
#define ir2 A1
#define ir3 A2

#define rled A3
#define gled A4
#define bled A5

#define buzzer 13
#define trig 0
#define echo 1

int s1;
int s2;
int s3;

int r = 0;
int g = 0;
int blue = 0;
int count = 0;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
 
  forward_align();
  stop();
  delay(500);
  right();
  delay(400);
  
  forward_align();
  stop();
  delay(100);
  forward();
  delay(100);
  left();
  delay(300);
  
  forward_align();
  stop();
  checkcolor();
  delay(500);
  forward();
  delay(300);
  
  forward_align();
  stop();
  checkcolor();
  delay(500);
  forward();
  delay(300);
  
  forward_align();
  stop();
  checkcolor();
  delay(500);
  forward();
  delay(300);
  
  forward_align();
  stop();
  checkcolor();
  delay(500);
  forward();
  delay(300);
  stop();

  forward_align();
  stop();
  delay(100);
  forward();
  delay(300);
  left();
  delay(300);
  
  forward_align();
  stop();
  checkcolor();
  delay(500);
  forward();
  delay(300);
  stop();

  forward_align();
  stop();
   checkcolor();
  delay(500);
  forward();
  delay(300);
  stop();

  forward_align();
  stop();
   checkcolor();
  delay(500);
  forward();
  delay(300);
  stop();

  forward_align();
  stop();
  delay(100);
  forward();
  delay(100);
  left();
  delay(300);

   forward_align();
  stop();
   checkcolor();
  delay(500);
  forward();
  delay(300);
  stop();

   forward_align();
  stop();
   checkcolor();
  delay(500);
  forward();
  delay(300);
  stop();

   forward_align();
  stop();
   checkcolor();
  delay(500);
  forward();
  delay(300);
  stop(); 

   forward_align();
  stop();
  delay(100);
  forward();
  delay(250);
  left();
  delay(300);

   forward_align();
  stop();
  delay(100);
  forward();
  delay(250);
  left();
  delay(300);

  forward_align();
  stop();
  delay(500);
  right();
  delay(400);
  
  forward_align();
  stop();
  delay(100);
  forward();
  delay(100);
  left();
  delay(300);
  
  forward_align();
  stop();
  delay(500);
  forward();
  delay(300);

  forward_align();
  stop();
  delay(100);
  forward();
  delay(100);
  left();
  delay(300);

   forward_align();
  stop();
  delay(500);
  forward();
  delay(300);

  forward_align();
  stop();
  delay(100);
  forward();
  delay(100);
  left();
  delay(300);

   forward_align();
  stop();
  delay(500);
  forward();
  delay(300);

  forward_align();
  stop();
  delay(500);
  right();
  delay(400);

   forward_align();
  stop();
  delay(500);
  forward();
  delay(300);

   forward_align();
  stop();
  delay(500);
  forward();
  delay(300);
  stop();
}

void loop() {
  // Main loop can be expanded for other tasks
}

void readIR() {
  s1 = digitalRead(ir1); 
  s2 = digitalRead(ir2);  
  s3 = digitalRead(ir3);  
  
}

void forward_align() {
  while (true) {
    readIR();
    Serial.print("IR values: ");
    Serial.print(s1);
    Serial.print(", ");
    Serial.print(s2);
    Serial.print(", ");
    Serial.println(s3);
    
    if (s1 == 1 && s2 == 1 && s3 == 1) {
    
      break;
    } if (s1 == 0 && s2 == 1 && s3 == 0) {
      forward();
    }  if (s1 == 0 && s2 == 0 && s3 == 1) {
      sright();
    }  if (s1 == 0 && s2 == 1 && s3 == 1) {
      sright();
    }  if (s1 == 1 && s2 == 0 && s3 == 0) {
      sleft();
    }  if (s1 == 1 && s2 == 1 && s3 == 0) {
      sleft();
    }
      //else if (s1 == 0 && s2 == 0 && s3 == 0) {
      //right();
   // }
  }
}

void forward() {
  analogWrite(e1, 50); 
  analogWrite(e2, 50); 
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void stop() {
  analogWrite(e1, 0); 
  analogWrite(e2, 0); 
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void right() {
  analogWrite(e1, 50); 
  analogWrite(e2, 50); 
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void left() {
  analogWrite(e1, 50); 
  analogWrite(e2, 50); 
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
void sleft() {
  analogWrite(e1, 35); 
  analogWrite(e2, 35); 
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
void sright() {
  analogWrite(e1, 35); 
  analogWrite(e2, 35); 
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void checkcolor() {
  long duration;
  float distance;

  // Send a 10 microsecond pulse to the trigger pin
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the duration of the pulse on the echo pin
  duration = pulseIn(echo, HIGH);

  // Calculate the distance in cm
  distance = (duration / 2.0) / 29.1;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for 250 milliseconds before taking another measurement
  delay(250);
  
  if (distance > 0 ) {
    blue = blue + 1;
    digitalWrite(g,LOW);
    digitalWrite(blue,HIGH);
    digitalWrite(r,HIGH);
    delay(500);
    digitalWrite(g,HIGH);
    digitalWrite(blue,LOW);
    digitalWrite(r,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
 // } else if (distance > 13 && distance < 16) {
   // g = g + 1;
  //} else if (distance > 16 && distance < 20) {
    //r = r + 1;
  } 
}
