int i;
int columna;//tierra

void setup() {
  // put your setup code here, to run once:
  for(i=23;i<31;i++){
    pinMode(i,OUTPUT);
  }
  for(i=64;i<72;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
  }
  columna = 64;
}

void barrido(){
  for(i=30;i>22;i--){
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
  }
}

void tierra(int columna){
  for(i=64;i<72;i++){
    if(i==columna)
      digitalWrite(i,LOW);//tierra activa
    else
      digitalWrite(i,HIGH);//tierra desactivada
  }
}



void loop() {
  // put your main code here, to run repeatedly: 
  if(columna>71){
    columna = 64;
  }
  tierra(columna);
  barrido();
  columna++;
  delay(500);
}
