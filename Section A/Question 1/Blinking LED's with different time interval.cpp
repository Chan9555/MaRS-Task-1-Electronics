int r=7,g=6,b=5;
void setup()
{
  pinMode(r, OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  digitalWrite(r,LOW);
  digitalWrite(g,LOW);
  digitalWrite(b,LOW);
}

void loop()
{
  if(millis()%500==0){
  	digitalWrite(r,HIGH);
  }
  else{
    digitalWrite(r,LOW);
  }
  if(millis()%1000==0){
    digitalWrite(g,HIGH);
  }
  else{
    digitalWrite(g,LOW);
  }
  if(millis()%1500==0){
    digitalWrite(b,HIGH);
  }
  else{
    digitalWrite(b,LOW);
  }
   
}
