int luz=32;
int sensorSonido=5;
int sonido=0;
int var=0;

void setup() {
Serial.begin (9600);
pinMode(sensorSonido,INPUT);
pinMode(luz,OUTPUT);
}

void loop (){
var=digitalRead(sensorSonido);
if (var==HIGH){
  Serial.println("encendido");
  digitalWrite(luz,HIGH);
  sonido=sonido+1;
  delay(90);
}
if (sonido==2) {
  Serial.println("apagado");
  digitalWrite(luz, LOW);
  sonido=0;
}
}



