// definición de pines
const int LED1 = 5;
const int BOTON = 21;
int contador = 1;
const int LED2= 2;
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(BOTON, PULLUP);
  pinMode(LED2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BOTON), sumar, FALLING );
}
void loop(){
  Serial.println(contador);
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);
}

void sumar()

{
  contador= contador +1;
  if (contador%2==0){
    digitalWrite(LED1, HIGH);
  }
  
  else{
    digitalWrite(LED1, LOW);
  }

}