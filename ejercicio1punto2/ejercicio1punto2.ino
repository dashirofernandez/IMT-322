// definición de pines
const int LED1 = 5;
const int LED2 = 18;
const int LED3 = 19;
const int BOTON_PIN = 21;
const int SPEED = 200;
bool b = true;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BOTON_PIN, INPUT_PULLUP);
}
//estado del boton
void loop(){
  if (digitalRead(BOTON_PIN)==0){
    b=!b;
    delay(80);
  }
//primer orden
  if (b==true){
    digitalWrite(LED1, HIGH);
    delay(SPEED);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(SPEED);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    delay(SPEED);
    digitalWrite(LED3, LOW);
//segundo orden
  }
  if (b==false){
    digitalWrite(LED3, HIGH);
    delay(SPEED);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    delay(SPEED);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    delay(SPEED);
    digitalWrite(LED1, LOW);
  }
}