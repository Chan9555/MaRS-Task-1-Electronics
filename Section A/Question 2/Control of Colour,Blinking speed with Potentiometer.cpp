int pot=A0;
int r=9,b=6,g=5,o=3; //Pin number for each color
int rv,bv,gv;        //Values of the colors
int potv,colorv,time;
void setup()
{
  pinMode(pot,INPUT);
  pinMode(r,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(o,OUTPUT);
}

void loop()
{
  potv=analogRead(pot);
  colorv=map(potv,0,1023,0,765);
  if(colorv<=255){
    rv=255-colorv;
    gv=colorv;
    bv=0;
  }
  else if(colorv<=510){
    rv=0;
    gv=510-colorv;
    bv=colorv-255;
  }
  else{
    rv=colorv-510;
    gv=0;
    bv=765-colorv;
  }
  analogWrite(r,rv); 
  analogWrite(b,bv);
  analogWrite(g,gv);
  time=map(potv,0,1023,100,1500);
  digitalWrite(o,HIGH);
  delay(time);
  digitalWrite(o,LOW);
  delay(time);
}
