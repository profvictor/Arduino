#define ledverde 10
#define ledamarelo 11
#define ledvermelho 12
#define botao 4
#define ledvermelhoped 6
#define ledverdeped 5
int on=1;
int estadobotao = 0;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void pedestre(){
  digitalWrite(12, HIGH);// Led vermelho carro aceso
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  digitalWrite(5, HIGH); // Led verde pedestre aceso
  digitalWrite(6, LOW);
  delay(8000); // Wait for 1000 millisecond(s)
  on=1;
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
}

void semaforo()
{
  digitalWrite(10, HIGH); //verde aceso
  digitalWrite(5, LOW); //verde pedestre aceso
  digitalWrite(6, HIGH); //vermelho pedestre aceso
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  
  digitalWrite(11, HIGH); //amarelo aceso
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  
  digitalWrite(12, HIGH); // vermelho aceso
  digitalWrite(6, LOW); //vermelho pedestre apagado
  digitalWrite(5, HIGH); //verde pedestre aceso
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}

void loop(){
  estadobotao = digitalRead(botao);
  if (estadobotao == HIGH) {
      if(on==1){
        on=0;
      }else{
        on=1;
      }
  }
  if (on==1){
    semaforo();
  }
  if (on==0){
    pedestre();
  }
}
