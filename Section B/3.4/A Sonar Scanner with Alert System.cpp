#include <Servo.h>

int r=11,g=10,b=9;
int buzzer=6;
int trig=2,echo=3;
float distance,duration;
Servo servo;
void setup()
{
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  servo.attach(4);
  Serial.begin(9600);
}

void loop()
{
  for(int deg=0;deg<=180;deg++){
    servo.write(deg);
    delay(10);
    digitalWrite(trig,LOW);
    delay(10);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    duration=pulseIn(echo,HIGH);
    distance=duration*0.017;
    if(distance>50){
      digitalWrite(b,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(r,LOW);
      noTone(buzzer);
      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println(" cm - Safe");
    }
    else if(distance>20){
      digitalWrite(b,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(r,LOW);
      tone(buzzer,100);
      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println(" cm - Caution");
    }
    else{
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);
      digitalWrite(r,HIGH);
      tone(buzzer,500);
      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println(" cm - Hazard");
      while(true){
        digitalWrite(trig,LOW);
    	delay(10);
    	digitalWrite(trig,HIGH);
    	delayMicroseconds(10);
    	digitalWrite(trig,LOW);
    	duration=pulseIn(echo,HIGH);
    	distance=duration*0.017;
        if(distance>20){
          break;
        }
      }
    }
  }
  for(int deg=180;deg>=0;deg--){
    servo.write(deg);
    delay(10);
    digitalWrite(trig,LOW);
    delay(10);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    duration=pulseIn(echo,HIGH);
    distance=duration*0.017;
    if(distance>50){
      digitalWrite(b,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(r,LOW);
      noTone(buzzer);
    }
    else if(distance>20){
      digitalWrite(b,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(r,LOW);
      tone(buzzer,100);
    }
    else{
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);
      digitalWrite(r,HIGH);
      tone(buzzer,500);
      while(true){
        digitalWrite(trig,LOW);
    	delay(10);
    	digitalWrite(trig,HIGH);
    	delayMicroseconds(10);
    	digitalWrite(trig,LOW);
    	duration=pulseIn(echo,HIGH);
    	distance=duration*0.017;
        if(distance>20){
          break;
        }
      }
    }
  } 
}
