const int verde = 5;
const int amarillo = 4;
const int rojo = 3;

const int tiemporojo = 2000; 
const int tiempoamarillo = 1000; 
const int tiempoverde = 2000; 


typedef enum {
  VERDE,
  AMARILLO,
  ROJO
}semaforo;

semaforo FSM= VERDE;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop() {
  
  switch (FSM) {
    case VERDE:
      digitalWrite(verde, HIGH);
      digitalWrite(amarillo, LOW);
      digitalWrite(rojo, LOW);
      delay(tiempoverde);
	  FSM=AMARILLO;
      break;
    case AMARILLO:
      digitalWrite(verde, LOW);
      digitalWrite(amarillo, HIGH);
      digitalWrite(rojo, LOW);
      delay(tiempoamarillo);
      FSM=ROJO;
      break;
    case ROJO:
      digitalWrite(verde, LOW);
      digitalWrite(amarillo, LOW);
      digitalWrite(rojo, HIGH);
      delay(tiemporojo);
      FSM=VERDE;
      break;
  }
}
