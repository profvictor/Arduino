#define pinldr A0

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int valorLDR = analogRead(A0);  //Lê o valor do sensor
  Serial.println(valorLDR);         // Printa no serial o valor
  delay(500);                       // espera 0,5 s

  if(valorLDR < 270){             // o valor 650 você troca de acordo com o ambiente, teste antes vendo o serial.
    digitalWrite(2,LOW);
    digitalWrite(3,LOW); 
    digitalWrite(4,LOW); 
    digitalWrite(5,LOW); 
    digitalWrite(6,LOW);        
  }else{
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH); 
    digitalWrite(4,HIGH); 
    digitalWrite(5,HIGH); 
    digitalWrite(6,HIGH);        
  }
}
