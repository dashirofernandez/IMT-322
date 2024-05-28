#include <Wire.h>

// Definir las direcciones de los pines para los pulsadores
const int buttonOpenPin = 2;
const int buttonClosePin = 3;
const int buttonLockPin = 4;

// Variables para almacenar el estado de los pulsadores
volatile bool buttonOpenPressed = false;
volatile bool buttonClosePressed = false;
volatile bool buttonLockPressed = false;

void setup() {
  // Inicializar los pines de los pulsadores como entradas con pull-up
  pinMode(buttonOpenPin, INPUT_PULLUP);
  pinMode(buttonClosePin, INPUT_PULLUP);
  pinMode(buttonLockPin, INPUT_PULLUP);

  // Configurar las interrupciones para los pulsadores
  attachInterrupt(digitalPinToInterrupt(buttonOpenPin), openButtonPressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonClosePin), closeButtonPressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonLockPin), lockButtonPressed, FALLING);

  // Inicializar la comunicación I2C como esclavo con la dirección 8
  Wire.begin(8);
  Wire.onRequest(requestEvent);
}

void loop() {
  // No se necesita código en el loop
}

// Función de interrupción para el pulsador de abrir
void openButtonPressed() {
  buttonOpenPressed = true;
}

// Función de interrupción para el pulsador de cerrar
void closeButtonPressed() {
  buttonClosePressed = true;
}

// Función de interrupción para el pulsador de bloquear
void lockButtonPressed() {
  buttonLockPressed = true;
}

// Evento de solicitud desde el maestro (Raspberry Pi)
void requestEvent() {
  // Enviar el estado de los pulsadores como un byte:
  // Bit 0: Pulsador de abrir
  // Bit 1: Pulsador de cerrar
  // Bit 2: Pulsador de bloquear
  byte buttonState = 0;
  if (buttonOpenPressed) buttonState |= 0x01;
  if (buttonClosePressed) buttonState |= 0x02;
  if (buttonLockPressed) buttonState |= 0x04;

  Wire.write(buttonState);

  // Resetear los estados de los pulsadores
  buttonOpenPressed = false;
  buttonClosePressed = false;
  buttonLockPressed = false;
}