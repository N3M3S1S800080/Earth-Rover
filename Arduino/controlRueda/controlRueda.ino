/*
 * controlRueda.ino
 * 
 * BilbaoDynamics - Earth-Rover
 * 
 */

#define ledAdelante 9
#define ledAtras 10
#define ledIzquierda 11
#define ledDerecha 12
#define ledEstable 13



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledAdelante, OUTPUT);
  pinMode(ledAtras, OUTPUT);
  pinMode(ledIzquierda, OUTPUT);
  pinMode(ledDerecha, OUTPUT);
  pinMode(ledEstable, OUTPUT);
  Serial.println("Inicializado");
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (Serial.read()){
    case "11":
      moverAdelante();
    case "10":
      rotarDerecha();
    case "01":
      rotarIzquierda();
    case "00";
      moverAtras();
    default:
      estabilizar();
  }
}

void moverAdelante() {
  /*
   * Códgio para mover la rueda hacia delante
   */
  digitalWrite(ledAdelante,HIGH);
  //... 
  digitalWrite(ledAdelante,LOW);
}

void moverAtras(){
  /*
   * Código para mover la rueda hacia atrás
   */
  digitalWrite(ledAtras,HIGH);
  //... 
  digitalWrite(ledAtras,LOW);
}

void rotarIzquierda(){
  /*
   * Código para rotar la rueda hacia la izquierda
   */
  digitalWrite(ledIzquierda,HIGH);
  //... 
  digitalWrite(ledIzquierda,LOW);
}

void rotarDerecha() {
  /*
   * Código para rotar la rueda hacía la derecha
   */
  digitalWrite(ledDerecha,HIGH);
  //... 
  digitalWrite(ledDerecha,LOW);
}

void estabilizar(){
 /*
  * Código para estabilizar la rueda
  */
  digitalWrite(ledEstable,HIGH);
  //... 
  digitalWrite(ledEstable,LOW);
}
