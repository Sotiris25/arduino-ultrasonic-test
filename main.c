// =================================================================
// 5/11/2022 - ultrasonic program
// =================================================================
#define echoPin 13 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 2 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

int i;
int j;
int k;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  // ============================================
  
  }
  // =============================================


void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  //==============================
  // print duration
  //==============================
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print("\t");
  //==============================

  // Calculating the distance
  

  for (i = 1; i < 500; i++) {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);

      distance = duration * 0.034 / 2;
      if (distance <= k + 20) {
          distance = ((duration * 0.034 / 2) + k) / 2;
      }

      k = distance;
  }

  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  j = map(distance, 1, 50, 0, 10) + 2;
  for (i = 0; i <= 12; i++) {
      pinMode(i, OUTPUT);

      if (i <= j) {
         digitalWrite(i, HIGH);
      }
      else {
        digitalWrite(i, LOW);
      }
  }
}
