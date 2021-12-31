#define pinldr A0
#define led 10

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorLDR = analogRead(A0);  //Lê o valor do sensor

Serial.println(valorLDR);         // Printa no serial o valor
delay(500);                       // espera 0,5 s

  if(valorLDR > 650){             // o valor 650 você troca de acordo com o ambiente, teste antes vendo o serial.
    digitalWrite(led,LOW);        // apaga o led quando ta claro
  }else{
    digitalWrite(led,HIGH);       // acende o led quando ta escuro
  }
}
