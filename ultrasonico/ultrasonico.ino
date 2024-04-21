#define TRIG 6
#define ECHO 9
#define BOTON 2
typedef enum{
  ESPERA,
  DISTANCIA,
  MOSTRAR
}ultrasonico;
ultrasonico estado = ESPERA;
  long t;
  long d;
  const int tiempo = 10;
  long tiempo0 = 0;
  long tiempo1=0;
  long tiempo2=0;
  void setup()
{
  pinMode(TRIG, INPUT_PULLUP);
  pinMode(ECHO, OUTPUT);
  pinMode(BOTON, INPUT);
  digitalWrite(TRIG, LOW);
  attachInterrupt(digitalPinToInterrupt(BOTON), distancia, RISING);
  Serial.begin(9600);
}
void loop()
{
  switch (estado)
  {
    case ESPERA:
    Serial.println("EN ESPERA PARA MEDICION");
    delay(2000);
    break;

    case DISTANCIA:
    digitalWrite(TRIG, HIGH);
    delay(10);
    digitalWrite(TRIG, LOW);
    t = pulseIn(ECHO, HIGH);
    d=t/59;
    if (tiempo1==0)
    {
      tiempo1=millis();
    }
    estado=MOSTRAR;
    break;

    case MOSTRAR:
    Serial.print(d);
    Serial.println(" cm.");
    tiempo2=millis();
    if (tiempo2-tiempo1<5000)
    {
      estado= DISTANCIA;
    }
    else
    {
      tiempo1=0;
      estado=ESPERA;
    }
    break;
  }
}
void distancia()
{
  estado=DISTANCIA;
  Serial.println("DISTANCIA");
  tiempo0=millis();
  
}