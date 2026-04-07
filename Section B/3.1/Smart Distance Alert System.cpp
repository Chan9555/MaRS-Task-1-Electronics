int trig=11,echo=10,w=6,r=5,y=3,buzzer=2,ldr=A0;
int dist,dur,light,blink,brightness;
bool caution=0;
unsigned long prev=0;
void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(w,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig,LOW);
  delay(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dist=(dur*0.017);
  light=analogRead(ldr);
  
  Serial.print("Distance : ");
  Serial.print(dist);
  Serial.println(" cm");
  digitalWrite(r,LOW);
  digitalWrite(w,LOW);
  blink=map(dist,30,60,100,500);
  brightness=map(light,0,1023,255,0);
  if(dist<=30){
    digitalWrite(r,HIGH);
    digitalWrite(y,LOW);
    caution=0;
    tone(buzzer,1000);
    delay(70);
    noTone(buzzer);
    delay(70);
  }
  else if(dist>30 && dist<60){
    if(millis()-prev>=blink){
      prev=millis();
      caution=!caution;
      digitalWrite(y,caution);
      if(caution!=0){
        tone(buzzer,600);
      }
      else{
        noTone(buzzer);
      }
    }
  }
  else{
    digitalWrite(y,LOW);
    analogWrite(w,brightness);
    noTone(buzzer);
  }
  delay(200);
}
