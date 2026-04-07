int ldr=A0,r=5;
int ldrv,c;
void setup()
{
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(r,OUTPUT);
}

void loop()
{
  ldrv=analogRead(ldr);
  c=map(ldrv,0,1023,255,0);
  analogWrite(r,c);
  Serial.println(ldrv);
  delay(500);
}
