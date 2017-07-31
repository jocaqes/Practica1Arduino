int matriz_caracter[8][8];
int i;//fila
int j;//columna
int tierra;//control columna de tierra
int positivo;//control fila de positivo
int contador;//control de tiempo entre movimiento
int contador_letra;//revisa paso de la letra
String mensaje;//mensaje de prueba
int contador_mensaje;//para pasar caracter por ...

void setup() {
  // put your setup code here, to run once:
  setMatriz();
  //caracterA();
  setPines();
  tierra=64;//punto inicial de tierra
  positivo=0;//punto inicial de positivo
  contador=0;//inicia en cero
  contador_letra=0;
  mensaje = "taa";
  contador_mensaje=0;
}

void setPines(){
  for(i=23;i<31;i++){
    pinMode(i,OUTPUT);
  }
  for(j=64;j<72;j++){
    pinMode(j,OUTPUT);
    digitalWrite(j,HIGH);
  }
}


void setMatriz(){
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      matriz_caracter[i][j]=0;
    }
  }
}

void caracterA(){
    matriz_caracter[2][1]=1;
    matriz_caracter[3][1]=1;
    matriz_caracter[4][1]=1;
    matriz_caracter[5][1]=1;
    matriz_caracter[6][1]=1;
    matriz_caracter[7][1]=1;
      matriz_caracter[1][2]=1;
      matriz_caracter[2][2]=1;
      matriz_caracter[4][2]=1;
        matriz_caracter[0][3]=1;
        matriz_caracter[1][3]=1;
        matriz_caracter[4][3]=1;
          matriz_caracter[0][4]=1;
          matriz_caracter[1][4]=1;
          matriz_caracter[4][4]=1;
            matriz_caracter[1][5]=1;
            matriz_caracter[2][5]=1;
            matriz_caracter[4][5]=1;
              matriz_caracter[2][6]=1;
              matriz_caracter[3][6]=1;
              matriz_caracter[4][6]=1;
              matriz_caracter[5][6]=1;
              matriz_caracter[6][6]=1;
              matriz_caracter[7][6]=1;         
}
void caracterT(){
  matriz_caracter[0][1]=1;
  matriz_caracter[0][2]=1;
  matriz_caracter[0][3]=1;
  matriz_caracter[0][4]=1;
  matriz_caracter[0][5]=1;
  matriz_caracter[0][6]=1;
    matriz_caracter[1][1]=1;
    matriz_caracter[1][2]=1;
    matriz_caracter[1][3]=1;
    matriz_caracter[1][4]=1;
    matriz_caracter[1][5]=1;
    matriz_caracter[1][6]=1;
      matriz_caracter[2][3]=1;
      matriz_caracter[3][3]=1;
      matriz_caracter[4][3]=1;
      matriz_caracter[5][3]=1;
      matriz_caracter[6][3]=1;
      matriz_caracter[7][3]=1;
        matriz_caracter[2][4]=1;
        matriz_caracter[3][4]=1;
        matriz_caracter[4][4]=1;
        matriz_caracter[5][4]=1;
        matriz_caracter[6][4]=1;
        matriz_caracter[7][4]=1;
}


void barridoMatriz(){
  int vector_auxiliar[8];
  for(i=0;i<8;i++){
    vector_auxiliar[i]=matriz_caracter[i][7];
  }
  for(j=7;j>=0;j--){
    for(i=0;i<8;i++){
      matriz_caracter[i][j]=matriz_caracter[i][j-1];
    }
  }
  for(i=0;i<8;i++){
    matriz_caracter[i][0]=vector_auxiliar[i];
  }
  
}



void barridoTierra(int columna){//una tierra a la vez
  for(j=64;j<72;j++){
    if(j==columna)
      digitalWrite(j,LOW);//tierra activa
    else
      digitalWrite(j,HIGH);//tierra desactivada
  }
}

void barridoPositivo(int fila){
  int aux=0;
  for(i=30;i>22;i--){
    if(matriz_caracter[aux][fila]==1){
      digitalWrite(i,HIGH);
    }
    else
      digitalWrite(i,LOW);
    aux++;
  }
}

void resetPositivo(){
  for(i=30;i>22;i--)
    digitalWrite(i,LOW);
}

void leeMensaje(char caracter){
  setMatriz();
  switch(caracter){
    case 'a':
      caracterA();
      break;
    case 't':
      caracterT();
      break;
  }
}


void loop() {
  if(tierra>71){
    tierra=64;
    resetPositivo();
  }
  if(positivo>7)
    positivo=0;
    
  barridoTierra(tierra);//muevo la columna de tierra
  barridoPositivo(positivo);//muevo la fila de positivo
  //barridoMatriz();//corro la matriz
  tierra++;//subo la columna de tierra
  positivo++;
  contador++;
  if(contador==80){
    barridoMatriz();
    contador=0;
    contador_letra++;
  }
  if(contador_letra==7){
    leeMensaje(mensaje.charAt(contador_mensaje));
    contador_mensaje++;
    contador_letra=0;
  }
  if(contador_mensaje==mensaje.length())
    contador_mensaje=0;
  
  delayMicroseconds(1500);
  
}
