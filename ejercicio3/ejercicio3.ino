#define PIN_PULSADOR_1 5
#define PIN_PULSADOR_2 18
#define PIN_BOTONO 19

// Variable para almacenar el contador
volatile int contador = 0;
void incrementarContador() {
  contador++;
}

void reiniciarContador() {
  contador = 0;
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_PULSADOR_1, INPUT_PULLUP);
  pinMode(PIN_PULSADOR_2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIN_PULSADOR_1), incrementarContador, FALLING);
  attachInterrupt(digitalPinToInterrupt(PIN_PULSADOR_2), reiniciarContador, FALLING);
}

void loop() {

  Serial.println(contador);

  delay(2000);
}
