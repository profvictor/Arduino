#define pinPIR 7          //colocar no pino 7
void setup() {
pinMode(pinPIR, INPUT);   // pir é um input
Serial.begin(9600);
}

void loop() {
  bool valorPIR = digitalRead(pinPIR);
 
  if (valorPIR) {
    Serial.println("DETECTADO");
  } else{
    Serial.println("----");
  }
}
