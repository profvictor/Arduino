#include <Thermistor.h> //INCLUSÃO DA BIBLIOTECA

Thermistor temp(2); //VARIÁVEL DO TIPO THERMISTOR, INDICANDO O PINO ANALÓGICO (A2) EM QUE O TERMISTOR ESTÁ CONECTADO
void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO
  pinMode(10, OUTPUT); //LED VERDE
  pinMode(11, OUTPUT); //LED AMARELO
  pinMode(12, OUTPUT); //LED VERMELHO
}
void loop() {
  int temperature = temp.getTemp(); //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  //Serial.print("Temperatura: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(temperature); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
  //Serial.println("°C"); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO
  if (temperature<27){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  if (temperature>=27 && temperature<40){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  if (temperature>=40){
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
  }
  
  
  
  
}
