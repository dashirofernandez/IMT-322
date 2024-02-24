//primer led
#define LED1 5 
//segundo led
#define LED2 18 
//tercer led
#define LED3 19
//void setup
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}
//loop led 1
void loop() {
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);

//retarde de 200ms
  delay(200);

//
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);

  
  delay(200);

  
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);

  
  delay(200);
}
