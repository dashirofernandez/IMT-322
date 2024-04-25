int led1 = 4;
int led2 = 5;
int led3 = 6;
char letra;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    letra = inChar; 
    switch (letra) {
      case 'a':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
      	Serial.println("En camino al piso 1");
      	for (int i = 0; i <= 100; i++) {
    		Serial.print("\r");
    		Serial.print("Cargando: ");
    		Serial.print(i);
    		Serial.print("%");
    		delay(100); 
  		}
        break;
      case 'b':
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
      	Serial.println("En camino al piso 2");
      	for (int i = 0; i <= 100; i++) {
    		Serial.print("\r");
    		Serial.print("Cargando: ");
    		Serial.print(i);
    		Serial.print("%");
    		delay(100); 
  		}
        break;
      case 'c':
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
      	Serial.println("En camino al piso 3");
      	for (int i = 0; i <= 100; i++) {
    		Serial.print("\r");
    		Serial.print("Cargando: ");
    		Serial.print(i);
    		Serial.print("%");
    		delay(100); 
  		}
        break;
      default:
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        break;
    }
  }
}
