int r=5,b=3,buzzer=10;
char *letters[]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.","...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char *numbers[]={"-----", ".----", "..---", "...--", "....-",".....", "-....", "--...", "---..", "----."};
char c;
void setup()
{
  pinMode(r,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter text (alphabets,numbers,space allowed) : ");
}

void loop()
{
  if(Serial.available()>0){
    c=Serial.read();
    if(c>=65 && c<=90){
      morse(letters[c-65]);
    }
    else if(c>=97 && c<=122){
      morse(letters[c-97]);
    }
    else if(c>=48&&c<=57){
      morse(numbers[c-48]);
    }
    else if(c==' '){
      digitalWrite(b,HIGH);
      delay(800);
      digitalWrite(b,LOW);
      delay(10);
    }
    else{
      for (int i = 0; i < 5; i++){
    	tone(buzzer,1500);
    	delay(100);
    	noTone(buzzer);
      }
  	}
  }
  noTone(buzzer);
}

void morse(char *a){
  int i=0;
  while(a[i]!='\0'){
    if(a[i]=='.'){
      dot();
    }
    else{
      dash();
    }
    delay(300);
    i++;
  }
  delay(500);
}
void dot(){
  digitalWrite(r,HIGH);
  tone(buzzer,1000);
  delay(100);
  digitalWrite(r,LOW);
  noTone(buzzer);
}
void dash(){
  digitalWrite(r,HIGH);
  tone(buzzer,1000);
  delay(300);
  digitalWrite(r,LOW);
  noTone(buzzer);
}
