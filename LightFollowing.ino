int RMotor_1 = 2;

int RMotor_2 = 3;

int LMotor_1 = 4;

int LMotor_2 = 5;

int REnable = 10;

int LEnable = 11;

int motor_speed = 60;

void setup() {

  Serial.begin(9600);

  Serial.println("GPIO test!");

  pinMode(RMotor_1, OUTPUT);

  pinMode(RMotor_2, OUTPUT);

  pinMode(LMotor_1, OUTPUT);

  pinMode(LMotor_2, OUTPUT);

  pinMode(REnable, OUTPUT);

  pinMode(LEnable, OUTPUT);

  analogWrite(10, motor_speed);

  analogWrite(11, motor_speed);

} 

void loop() {

  int ldrright = digitalRead(7);

  int ldrleft = digitalRead(8);

  if (ldrright == 0 && ldrleft == 0) {

    Serial.println("F");

    move_forward();

  }

  if (ldrright == 0 && ldrleft == 1) {

    Serial.println("R");

    turn_right();

  }

  if (ldrright == 1 && ldrleft == 0) {

    Serial.println("L");

    turn_left();

  }

  if (ldrright == 1 && ldrleft == 1) {

    Serial.println("S");

    move_stop();

  }

  delay(100);

}

void move_forward() {

  digitalWrite(RMotor_1, HIGH);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, HIGH);

}

//NOT USING BACKWARD

void move_backward() {

  digitalWrite(RMotor_1, HIGH);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, HIGH);

}

void turn_right() {

  digitalWrite(RMotor_1, LOW);

  digitalWrite(RMotor_2, HIGH);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, HIGH);

}

void turn_left() {

  digitalWrite(RMotor_1, HIGH);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, HIGH);

  digitalWrite(LMotor_2, LOW);

}

void move_stop() {

  digitalWrite(RMotor_1, LOW);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, LOW);

}
