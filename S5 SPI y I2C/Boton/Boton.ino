#define PIN_Boton 33
#define l 32
int x;
void setup() {
  
pinMode(PIN_Boton,INPUT);
pinMode(l,OUTPUT);
Serial.begin(9600);
}

void loop() {
  x = digitalRead(PIN_Boton);
  Serial.println(digitalRead(PIN_Boton));

  if(x==1)
  {
    digitalWrite(l,HIGH);
  }
  else
  {
     digitalWrite(l,LOW);
  }

  delay(0);
}
