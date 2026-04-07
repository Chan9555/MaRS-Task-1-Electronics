int r=6,y=10,button=3;
unsigned long prev=0,curr,wait,start,stop;
bool waiting=1,on=0;
void setup()
{
  pinMode(button,INPUT_PULLUP);
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  curr=millis();
  if(waiting==1){
    digitalWrite(r,LOW);
    wait=random(500,3000);
    prev=curr;
    waiting=0;
  }
  if(on==0 &&(curr-prev<wait) && digitalRead(button)==LOW){
    Serial.println("False start");
    digitalWrite(y,HIGH);
    delay(1000);
    digitalWrite(y,LOW);
    waiting=1;
    return;
  }
  if(on==0 && (curr-prev>=wait)){
    digitalWrite(r,HIGH);
    start=curr;
    on=1;
  }
  if(on==1 && digitalRead(button)==LOW){
    stop=curr;
    Serial.print("Reaction time : ");
    Serial.print(stop-start);
    Serial.println("ms");
    on=0;
    waiting=1;   
    digitalWrite(r,LOW);
    delay(1000);
  }
  
}
