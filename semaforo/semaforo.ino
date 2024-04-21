// Definir constantes para los pines y el tiempo de espera
const int TRIGGER_PIN = 7;
const int ECHO_PIN = 6;
const int BOTON_PIN = 3;
const int TIEMPO_ESPERA = 5000; // Tiempo en milisegundos (5 segundos)

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial
  pinMode(TRIGGER_PIN, OUTPUT); // Configurar el pin de trigger como salida
  pinMode(ECHO_PIN, INPUT); // Configurar el pin de echo como entrada
  pinMode(BOTON_PIN, INPUT_PULLUP); // Configurar el botón como entrada con resistencia pull-up interna
}

void loop() {
  // Verificar si el botón está presionado
  if (digitalRead(BOTON_PIN) == LOW) {
    // Botón presionado, medir distancia
    long duration, distance; // Variables para almacenar la duración del pulso y la distancia
    
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;
    
    // Imprimir la distancia medida en el monitor serial
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    delay(100); // Esperar un breve tiempo antes de la próxima lectura
  }
  
  // Esperar un tiempo antes de realizar la próxima medición
  delay(TIEMPO_ESPERA);
}
