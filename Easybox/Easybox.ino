#include <Servo.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

void bubbleSort(float arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] < arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


LiquidCrystal_I2C lcd(0x3F,16,2);
Servo servo1;
Servo servo2;
Servo servo3;

int servoPin1 = 9;  
int servoPin2 = 10; 
int servoPin3 = 11; 

const int trigPin1 = 3; 
const int echoPin1 = 2; 
const int trigPin2 = 5; 
const int echoPin2 = 4; 
const int trigPin3 = 7; 
const int echoPin3 = 6;

long duration1, distance1=999;
long duration2, distance2=999;
long duration3, distance3=999;



void setup()
{
lcd.begin(16,2);
lcd.init();
lcd.backlight();
servo1.attach(servoPin1);
servo1.write(90);
servo2.attach(servoPin2);
  servo2.write(90);
servo3.attach(servoPin3);
  servo3.write(90);
Serial.begin(9600);
 lcd.setCursor(0,0);
  lcd.print("Bine ati venit!");
  lcd.setCursor(0,1);
  lcd.print("Puneti obiectul ");

  // Set pin modes
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(8,INPUT);
 
}

void loop()
{

if(digitalRead(8)==HIGH)
{
	digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = 35.0-(duration1 * 0.0344 / 2);

    // Measure distance from sensor 2
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = 16.0-(duration2 * 0.0344 / 2);

    // Measure distance from sensor 3
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    distance3 = 38.0-(duration3 * 0.0344 / 2);

    // Print distances to serial monitor
    Serial.print("Distance from sensor 1: ");
    Serial.print(distance1);
    Serial.println(" cm");
    
    Serial.print("Distance from sensor 2: ");
    Serial.print(distance2);
    Serial.println(" cm");

    Serial.print("Distance from sensor 3: ");
    Serial.print(distance3);
    Serial.println(" cm");
    

  float distante[]={distance1,distance2,distance3};
  bubbleSort(distante,3);
  float cutie3[]={13.0,18.0,13.0};
  bubbleSort(cutie3,3);
  float cutie2[]={13.0,13.0,13.0};
  bubbleSort(cutie2,3);
  float cutie1[]={13.0,5.0,13.0};
  bubbleSort(cutie1,3);

if(distante[0]<cutie1[0]&&distante[1]<cutie1[1]&&distante[2]<cutie1[2])
{
  servo3.write(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Compartiment");
  lcd.setCursor(0,1);
  lcd.print("1 deschis");
  delay(8000);
  servo3.write(90);


  
}
  else if(distante[0]<cutie2[0]&&distante[1]<cutie2[1]&&distante[2]<cutie2[2])
  {
  servo2.write(00);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Compartiment");
  lcd.setCursor(0,1);
  lcd.print("2 deschis");
  delay(8000);
  servo2.write(90);
  }
else if(distante[0]<cutie3[0]&&distante[1]<cutie3[1]&&distante[2]<cutie3[2])
{
  servo1.write(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Compartiment");
  lcd.setCursor(0,1);
  lcd.print("3 deschis");
  delay(8000);
  servo1.write(90);
}
else
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eroare: obiect");
  lcd.setCursor(0,1);
  lcd.print("prea mare");
}}
}