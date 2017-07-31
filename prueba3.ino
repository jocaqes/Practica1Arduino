int matriz_caracter[8][8];
int matriz_auxiliar[8][8];
int i;//fila
int j;//columna
int tierra;//control columna de tierra
int positivo;//control fila de positivo
int contador;//control de tiempo entre movimiento
int contador_letra;//revisa paso de la letra
int contador_columna;//revisa que columna toca ver
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
  contador_columna=7;
  mensaje = "*a noicces-61 opurg-1pt*";
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
      matriz_auxiliar[i][j]=0;
      
    }
  }
}

void setAuxMatriz(){
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      matriz_auxiliar[i][j]=0;
    }
  }
}




void barridoMatriz(int columna){
  int vector_auxiliar[8];
  for(i=0;i<8;i++){
    vector_auxiliar[i]=matriz_auxiliar[i][columna];
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
  //setMatriz();
  switch(caracter){
    case 'a':
      caracterA();
      break;
    case 't':
      caracterT();
      break;
    case 'p':
      caracterP();
      break;
    case 'r':
      caracterR();
      break; 
    case 'o':
      caracterO();
      break;
    case '-':
      caracterGuion();
      break;
    case 'g':
      caracterG();
      break;
    case 'i':
      caracterI();
      break;
    case 'u':
      caracterU();
      break;
    case 's':
      caracterS();
      break;
    case 'e':
      caracterE();
      break;
    case 'c':
      caracterC();
      break;
    case 'n':
      caracterN();
      break;
    case ' ':
      caracterEspacio();
      break;
    case '*':
      caracterAsterisco();
      break;
    case '0':
      digito0();
      break;
    case '1':
      digito1();
      break;
    case '2':
      digito2();
      break;
    case '3':
      digito3();
      break;
    case '4':
      digito4();
      break;
    case '5':
      digito5();
      break;
    case '6':
      digito6();
      break;
    case '7':
      digito7();
      break;
    case '8':
      digito8();
      break;
    case '9':
      digito9();
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
  if(contador==80){//repite la imagen, cambia hasta 80 ciclos
    barridoMatriz(contador_columna);//aqui adelanta la imagen 1 columna
    contador=0;
    contador_letra++;
    contador_columna--;
  }
  if(contador_columna<0)
    contador_columna=7;
  if(contador_letra>7){//cambio el caracter a leer
    leeMensaje(mensaje.charAt(contador_mensaje));
    contador_mensaje++;
    contador_letra=0;
  }
  if(contador_mensaje==mensaje.length())
    contador_mensaje=0;
  
  delayMicroseconds(1500);
  
}

void caracterA(){
  setAuxMatriz();
    matriz_auxiliar[2][1]=1;
    matriz_auxiliar[3][1]=1;
    matriz_auxiliar[4][1]=1;
    matriz_auxiliar[5][1]=1;
    matriz_auxiliar[6][1]=1;
    matriz_auxiliar[7][1]=1;
      matriz_auxiliar[1][2]=1;
      matriz_auxiliar[2][2]=1;
      matriz_auxiliar[4][2]=1;
        matriz_auxiliar[0][3]=1;
        matriz_auxiliar[1][3]=1;
        matriz_auxiliar[4][3]=1;
          matriz_auxiliar[0][4]=1;
          matriz_auxiliar[1][4]=1;
          matriz_auxiliar[4][4]=1;
            matriz_auxiliar[1][5]=1;
            matriz_auxiliar[2][5]=1;
            matriz_auxiliar[4][5]=1;
              matriz_auxiliar[2][6]=1;
              matriz_auxiliar[3][6]=1;
              matriz_auxiliar[4][6]=1;
              matriz_auxiliar[5][6]=1;
              matriz_auxiliar[6][6]=1;
              matriz_auxiliar[7][6]=1;         
}
void caracterT(){
  setAuxMatriz();
  matriz_auxiliar[0][1]=1;
  matriz_auxiliar[0][2]=1;
  matriz_auxiliar[0][3]=1;
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[0][5]=1;
  matriz_auxiliar[0][6]=1;
    matriz_auxiliar[1][1]=1;
    matriz_auxiliar[1][2]=1;
    matriz_auxiliar[1][3]=1;
    matriz_auxiliar[1][4]=1;
    matriz_auxiliar[1][5]=1;
    matriz_auxiliar[1][6]=1;
      matriz_auxiliar[2][3]=1;
      matriz_auxiliar[3][3]=1;
      matriz_auxiliar[4][3]=1;
      matriz_auxiliar[5][3]=1;
      matriz_auxiliar[6][3]=1;
      matriz_auxiliar[7][3]=1;
        matriz_auxiliar[2][4]=1;
        matriz_auxiliar[3][4]=1;
        matriz_auxiliar[4][4]=1;
        matriz_auxiliar[5][4]=1;
        matriz_auxiliar[6][4]=1;
        matriz_auxiliar[7][4]=1;
}
void caracterP(){
  setAuxMatriz();
  matriz_auxiliar[0][1]=1;
  matriz_auxiliar[0][2]=1;
  matriz_auxiliar[0][3]=1;
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[0][5]=1;
    matriz_auxiliar[1][1]=1;
    matriz_auxiliar[1][2]=1;
    matriz_auxiliar[1][3]=1;
    matriz_auxiliar[1][4]=1;
    matriz_auxiliar[1][5]=1;
      matriz_auxiliar[2][1]=1;
      matriz_auxiliar[2][2]=1;
      matriz_auxiliar[2][6]=1;      
        matriz_auxiliar[3][1]=1;
        matriz_auxiliar[3][2]=1;
        matriz_auxiliar[3][6]=1;
          matriz_auxiliar[4][1]=1;
          matriz_auxiliar[4][2]=1;
          matriz_auxiliar[4][3]=1;
          matriz_auxiliar[4][4]=1;
          matriz_auxiliar[4][5]=1;
            matriz_auxiliar[5][1]=1;
            matriz_auxiliar[5][2]=1;
            matriz_auxiliar[5][3]=1;
            matriz_auxiliar[5][4]=1;
            matriz_auxiliar[5][5]=1;
              matriz_auxiliar[6][1]=1;
              matriz_auxiliar[6][2]=1;
                matriz_auxiliar[7][1]=1;
                matriz_auxiliar[7][2]=1;
          
}
void caracterR(){
  setAuxMatriz();
  matriz_auxiliar[0][1]=1;
  matriz_auxiliar[0][2]=1;
  matriz_auxiliar[0][3]=1;
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[0][5]=1;
    matriz_auxiliar[1][1]=1;
    matriz_auxiliar[1][2]=1;
    matriz_auxiliar[1][3]=1;
    matriz_auxiliar[1][4]=1;
    matriz_auxiliar[1][5]=1;
      matriz_auxiliar[2][1]=1;
      matriz_auxiliar[2][2]=1;
      matriz_auxiliar[2][6]=1;      
        matriz_auxiliar[3][1]=1;
        matriz_auxiliar[3][2]=1;
        matriz_auxiliar[3][6]=1;
          matriz_auxiliar[4][1]=1;
          matriz_auxiliar[4][2]=1;
          matriz_auxiliar[4][3]=1;
          matriz_auxiliar[4][4]=1;
          matriz_auxiliar[4][5]=1;
            matriz_auxiliar[5][1]=1;
            matriz_auxiliar[5][2]=1;
            matriz_auxiliar[5][3]=1;
            matriz_auxiliar[5][4]=1;
            matriz_auxiliar[5][5]=1;
              matriz_auxiliar[6][1]=1;
              matriz_auxiliar[6][2]=1;
              matriz_auxiliar[6][6]=1;
                matriz_auxiliar[7][1]=1;
                matriz_auxiliar[7][2]=1;
                matriz_auxiliar[7][6]=1;
          
}
void caracterO(){
  setAuxMatriz();
  matriz_auxiliar[1][1]=1;
  matriz_auxiliar[2][1]=1;
  matriz_auxiliar[3][1]=1;
  matriz_auxiliar[4][1]=1;
  matriz_auxiliar[5][1]=1;
  matriz_auxiliar[6][1]=1;
    matriz_auxiliar[1][2]=1;
    matriz_auxiliar[2][2]=1;
    matriz_auxiliar[3][2]=1;
    matriz_auxiliar[4][2]=1;
    matriz_auxiliar[5][2]=1;
    matriz_auxiliar[6][2]=1;
      matriz_auxiliar[0][3]=1;
      matriz_auxiliar[0][4]=1;
        matriz_auxiliar[7][3]=1;
        matriz_auxiliar[7][4]=1;
          matriz_auxiliar[1][5]=1;
          matriz_auxiliar[2][5]=1;
          matriz_auxiliar[3][5]=1;
          matriz_auxiliar[4][5]=1;
          matriz_auxiliar[5][5]=1;
          matriz_auxiliar[6][5]=1;
            matriz_auxiliar[1][6]=1;
            matriz_auxiliar[2][6]=1;
            matriz_auxiliar[3][6]=1;
            matriz_auxiliar[4][6]=1;
            matriz_auxiliar[5][6]=1;
            matriz_auxiliar[6][6]=1; 
}
void caracterGuion(){
  setAuxMatriz();
  matriz_auxiliar[3][1]=1;
  matriz_auxiliar[3][2]=1;
  matriz_auxiliar[3][3]=1;
  matriz_auxiliar[3][4]=1;
  matriz_auxiliar[3][5]=1;
  matriz_auxiliar[3][6]=1;
    matriz_auxiliar[4][1]=1;
    matriz_auxiliar[4][2]=1;
    matriz_auxiliar[4][3]=1;
    matriz_auxiliar[4][4]=1;
    matriz_auxiliar[4][5]=1;
    matriz_auxiliar[4][6]=1;
}
void caracterG(){
  setAuxMatriz();
  matriz_auxiliar[0][2]=1;
  matriz_auxiliar[0][3]=1;
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[0][5]=1;
  matriz_auxiliar[0][6]=1;  
    matriz_auxiliar[1][1]=1;
    matriz_auxiliar[1][2]=1;
    matriz_auxiliar[1][3]=1;
    matriz_auxiliar[1][4]=1;
    matriz_auxiliar[1][5]=1;
    matriz_auxiliar[1][6]=1;
      matriz_auxiliar[2][1]=1;
      matriz_auxiliar[3][1]=1;
      matriz_auxiliar[4][1]=1;
      matriz_auxiliar[5][1]=1;
      matriz_auxiliar[6][1]=1;
        matriz_auxiliar[2][2]=1;
        matriz_auxiliar[3][2]=1;
        matriz_auxiliar[4][2]=1;
        matriz_auxiliar[5][2]=1;
        matriz_auxiliar[6][2]=1;
          matriz_auxiliar[6][3]=1;
          matriz_auxiliar[6][4]=1;
          matriz_auxiliar[6][5]=1;
          matriz_auxiliar[6][6]=1;
            matriz_auxiliar[7][2]=1;
            matriz_auxiliar[7][3]=1;
            matriz_auxiliar[7][4]=1;
            matriz_auxiliar[7][5]=1;
              matriz_auxiliar[4][4]=1;
              matriz_auxiliar[4][5]=1;
              matriz_auxiliar[4][6]=1;
                matriz_auxiliar[5][5]=1;
                matriz_auxiliar[5][6]=1;
}
void caracterI(){
  setAuxMatriz();
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[1][4]=1;
  matriz_auxiliar[2][4]=1;
  matriz_auxiliar[3][4]=1;
  matriz_auxiliar[4][4]=1;
  matriz_auxiliar[5][4]=1;
  matriz_auxiliar[6][4]=1;
  matriz_auxiliar[7][4]=1;
    matriz_auxiliar[0][5]=1;
    matriz_auxiliar[1][5]=1;
    matriz_auxiliar[2][5]=1;
    matriz_auxiliar[3][5]=1;
    matriz_auxiliar[4][5]=1;
    matriz_auxiliar[5][5]=1;
    matriz_auxiliar[6][5]=1;
    matriz_auxiliar[7][5]=1;
}
void caracterU(){
  setAuxMatriz();
  matriz_auxiliar[0][1]=1;
  matriz_auxiliar[1][1]=1;
  matriz_auxiliar[2][1]=1;
  matriz_auxiliar[3][1]=1;
  matriz_auxiliar[4][1]=1;
  matriz_auxiliar[5][1]=1;
  matriz_auxiliar[6][1]=1;
    matriz_auxiliar[0][2]=1;
  matriz_auxiliar[1][2]=1;
  matriz_auxiliar[2][2]=1;
  matriz_auxiliar[3][2]=1;
  matriz_auxiliar[4][2]=1;
  matriz_auxiliar[5][2]=1;
  matriz_auxiliar[6][2]=1;
    matriz_auxiliar[0][5]=1;
  matriz_auxiliar[1][5]=1;
  matriz_auxiliar[2][5]=1;
  matriz_auxiliar[3][5]=1;
  matriz_auxiliar[4][5]=1;
  matriz_auxiliar[5][5]=1;
  matriz_auxiliar[6][5]=1;
    matriz_auxiliar[0][6]=1;
  matriz_auxiliar[1][6]=1;
  matriz_auxiliar[2][6]=1;
  matriz_auxiliar[3][6]=1;
  matriz_auxiliar[4][6]=1;
  matriz_auxiliar[5][6]=1;
  matriz_auxiliar[6][6]=1;
    matriz_auxiliar[6][3]=1;
  matriz_auxiliar[6][4]=1;
    matriz_auxiliar[7][2]=1;
  matriz_auxiliar[7][3]=1;
  matriz_auxiliar[7][4]=1;
  matriz_auxiliar[7][5]=1;
}
void caracterS(){
  setAuxMatriz();
  matriz_auxiliar[0][2]=1;
  matriz_auxiliar[0][3]=1;
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[0][5]=1;
  matriz_auxiliar[0][6]=1;
    matriz_auxiliar[1][1]=1;
  matriz_auxiliar[1][2]=1;
  matriz_auxiliar[1][3]=1;
  matriz_auxiliar[1][4]=1;
  matriz_auxiliar[1][5]=1;
  matriz_auxiliar[1][6]=1;
    matriz_auxiliar[2][1]=1;
 matriz_auxiliar[2][2]=1;
    matriz_auxiliar[3][1]=1;
  matriz_auxiliar[3][2]=1;
  matriz_auxiliar[3][3]=1;
  matriz_auxiliar[3][4]=1;
  matriz_auxiliar[3][5]=1;
    matriz_auxiliar[4][2]=1;
  matriz_auxiliar[4][3]=1;
  matriz_auxiliar[4][4]=1;
  matriz_auxiliar[4][5]=1;
  matriz_auxiliar[4][6]=1;  
    matriz_auxiliar[5][5]=1;
  matriz_auxiliar[5][6]=1;  
    matriz_auxiliar[6][1]=1;
  matriz_auxiliar[6][2]=1;
  matriz_auxiliar[6][3]=1;
  matriz_auxiliar[6][4]=1;
  matriz_auxiliar[6][5]=1;
  matriz_auxiliar[6][6]=1;    
    matriz_auxiliar[7][1]=1;
  matriz_auxiliar[7][2]=1;
  matriz_auxiliar[7][3]=1;
  matriz_auxiliar[7][4]=1;
  matriz_auxiliar[7][5]=1;  
}
void caracterE(){
  setAuxMatriz();
  matriz_auxiliar[0][1]=1;
  matriz_auxiliar[1][1]=1;
  matriz_auxiliar[2][1]=1;
  matriz_auxiliar[3][1]=1;
  matriz_auxiliar[4][1]=1;
  matriz_auxiliar[5][1]=1;
  matriz_auxiliar[6][1]=1;
  matriz_auxiliar[7][1]=1;
    matriz_auxiliar[0][2]=1;
  matriz_auxiliar[1][2]=1;
  matriz_auxiliar[2][2]=1;
  matriz_auxiliar[3][2]=1;
  matriz_auxiliar[4][2]=1;
  matriz_auxiliar[5][2]=1;
  matriz_auxiliar[6][2]=1;
  matriz_auxiliar[7][2]=1;
    matriz_auxiliar[0][3]=1;
  matriz_auxiliar[0][4]=1;
  matriz_auxiliar[0][5]=1;
  matriz_auxiliar[0][6]=1;
    matriz_auxiliar[1][3]=1;
  matriz_auxiliar[1][4]=1;
  matriz_auxiliar[1][5]=1;
  matriz_auxiliar[1][6]=1;
    matriz_auxiliar[3][3]=1;
  matriz_auxiliar[3][4]=1;
  matriz_auxiliar[3][5]=1;
    matriz_auxiliar[4][3]=1;
  matriz_auxiliar[4][4]=1;
  matriz_auxiliar[4][5]=1;
    matriz_auxiliar[6][3]=1;
  matriz_auxiliar[6][4]=1;
  matriz_auxiliar[6][5]=1;
  matriz_auxiliar[6][6]=1;
    matriz_auxiliar[7][3]=1;
  matriz_auxiliar[7][4]=1;
  matriz_auxiliar[7][5]=1;
  matriz_auxiliar[7][6]=1;
}
void caracterC(){
    setAuxMatriz();
  matriz_auxiliar[1][1]=1;
  matriz_auxiliar[2][1]=1;
  matriz_auxiliar[3][1]=1;
  matriz_auxiliar[4][1]=1;
  matriz_auxiliar[5][1]=1;
  matriz_auxiliar[6][1]=1;
    matriz_auxiliar[0][2]=1;
    matriz_auxiliar[1][2]=1;
    matriz_auxiliar[2][2]=1;
    matriz_auxiliar[3][2]=1;
    matriz_auxiliar[4][2]=1;
    matriz_auxiliar[5][2]=1;
    matriz_auxiliar[6][2]=1;
    matriz_auxiliar[7][2]=1;
      matriz_auxiliar[0][3]=1;
      matriz_auxiliar[0][4]=1;
      matriz_auxiliar[0][5]=1;
      matriz_auxiliar[0][6]=1;
        matriz_auxiliar[1][3]=1;
      matriz_auxiliar[1][4]=1;
      matriz_auxiliar[1][5]=1;
      matriz_auxiliar[1][6]=1;
          matriz_auxiliar[6][3]=1;
        matriz_auxiliar[6][4]=1;
        matriz_auxiliar[6][5]=1;
        matriz_auxiliar[6][6]=1;
          matriz_auxiliar[7][3]=1;
        matriz_auxiliar[7][4]=1;
        matriz_auxiliar[7][5]=1;
        matriz_auxiliar[7][6]=1;
}
void caracterN(){
  setAuxMatriz();
  matriz_auxiliar[0][1]=1;
  matriz_auxiliar[1][1]=1;
  matriz_auxiliar[2][1]=1;
  matriz_auxiliar[3][1]=1;
  matriz_auxiliar[4][1]=1;
  matriz_auxiliar[5][1]=1;
  matriz_auxiliar[6][1]=1;
  matriz_auxiliar[7][1]=1;
    matriz_auxiliar[0][2]=1;
  matriz_auxiliar[1][2]=1;
  matriz_auxiliar[2][2]=1;
  matriz_auxiliar[3][2]=1;
  matriz_auxiliar[4][2]=1;
  matriz_auxiliar[5][2]=1;
  matriz_auxiliar[6][2]=1;
  matriz_auxiliar[7][2]=1;
    matriz_auxiliar[0][5]=1;
  matriz_auxiliar[1][5]=1;
  matriz_auxiliar[2][5]=1;
  matriz_auxiliar[3][5]=1;
  matriz_auxiliar[4][5]=1;
  matriz_auxiliar[5][5]=1;
  matriz_auxiliar[6][5]=1;
  matriz_auxiliar[7][5]=1;
    matriz_auxiliar[0][6]=1;
  matriz_auxiliar[1][6]=1;
  matriz_auxiliar[2][6]=1;
  matriz_auxiliar[3][6]=1;
  matriz_auxiliar[4][6]=1;
  matriz_auxiliar[5][6]=1;
  matriz_auxiliar[6][6]=1;
  matriz_auxiliar[7][6]=1;
    matriz_auxiliar[1][3]=1;
  matriz_auxiliar[2][3]=1;
  matriz_auxiliar[3][3]=1;
    matriz_auxiliar[3][4]=1;
  matriz_auxiliar[4][4]=1;
  matriz_auxiliar[5][4]=1;  
}
void caracterEspacio(){
  setAuxMatriz();
}
void caracterAsterisco(){
  setAuxMatriz();
  matriz_auxiliar[0][2]=1;  
  matriz_auxiliar[0][5]=1;  
    matriz_auxiliar[1][3]=1;  
  matriz_auxiliar[1][4]=1;
      matriz_auxiliar[2][3]=1;  
  matriz_auxiliar[2][4]=1;
      matriz_auxiliar[3][2]=1;  
  matriz_auxiliar[3][5]=1;  
}
void digito1(){
  setAuxMatriz();
        matriz_auxiliar[1][5]=1;  
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1; 
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;  
}
void digito2(){
  setAuxMatriz();
      matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;
          matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1; 
          matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1;
      matriz_auxiliar[5][1]=1;  //e
    matriz_auxiliar[5][2]=1;    
    matriz_auxiliar[6][1]=1;  
    matriz_auxiliar[6][2]=1; 
       matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1; 
}
void digito3(){
  setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1; 
      matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1;    
      matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1;
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;     
          matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1;     
}
void digito4(){
  setAuxMatriz();
      matriz_auxiliar[1][1]=1;  //b
    matriz_auxiliar[1][2]=1;    
    matriz_auxiliar[2][1]=1;  
    matriz_auxiliar[2][2]=1;  
      matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1;    
      matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1;  
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;        
  
}
void digito5(){
  setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;
      matriz_auxiliar[1][1]=1;  //b
    matriz_auxiliar[1][2]=1;    
    matriz_auxiliar[2][1]=1;  
    matriz_auxiliar[2][2]=1;   
      matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1;    
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;     
          matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1;      
}
void digito6(){
  setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;
      matriz_auxiliar[1][1]=1;  //b
    matriz_auxiliar[1][2]=1;    
    matriz_auxiliar[2][1]=1;  
    matriz_auxiliar[2][2]=1;     
      matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1;
      matriz_auxiliar[5][1]=1;  //e
    matriz_auxiliar[5][2]=1;    
    matriz_auxiliar[6][1]=1;  
    matriz_auxiliar[6][2]=1;   
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;      
          matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1;     
}
void digito7(){
  setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;  
      matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1; 
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;   
}
void digito8(){
  setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;
      matriz_auxiliar[1][1]=1;  //b
    matriz_auxiliar[1][2]=1;    
    matriz_auxiliar[2][1]=1;  
    matriz_auxiliar[2][2]=1;  
      matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1;    
      matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1;
      matriz_auxiliar[5][1]=1;  //e
    matriz_auxiliar[5][2]=1;    
    matriz_auxiliar[6][1]=1;  
    matriz_auxiliar[6][2]=1;   
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;      
          matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1;    
}
void digito9(){
  setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;
      matriz_auxiliar[1][1]=1;  //b
    matriz_auxiliar[1][2]=1;    
    matriz_auxiliar[2][1]=1;  
    matriz_auxiliar[2][2]=1;  
      matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1;    
      matriz_auxiliar[3][3]=1;  //d
    matriz_auxiliar[3][4]=1;    
    matriz_auxiliar[4][3]=1;  
    matriz_auxiliar[4][4]=1; 
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;   
          matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1;     
}
void digito0(){
    setAuxMatriz();
    matriz_auxiliar[0][3]=1;  //a
    matriz_auxiliar[0][4]=1;
      matriz_auxiliar[1][1]=1;  //b
    matriz_auxiliar[1][2]=1;    
    matriz_auxiliar[2][1]=1;  
    matriz_auxiliar[2][2]=1;  
      matriz_auxiliar[1][5]=1;  //c
    matriz_auxiliar[1][6]=1;    
    matriz_auxiliar[2][5]=1;  
    matriz_auxiliar[2][6]=1;    
      matriz_auxiliar[5][1]=1;  //e
    matriz_auxiliar[5][2]=1;    
    matriz_auxiliar[6][1]=1;  
    matriz_auxiliar[6][2]=1;   
      matriz_auxiliar[5][5]=1;  //f
    matriz_auxiliar[5][6]=1;    
    matriz_auxiliar[6][5]=1;  
    matriz_auxiliar[6][6]=1;    
          matriz_auxiliar[7][3]=1; //g 
    matriz_auxiliar[7][4]=1;   
}

