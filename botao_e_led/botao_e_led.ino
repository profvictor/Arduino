#define pinobotao 4     // número do pino do botão
#define pinoled  10      // número do pino do led
int on=0;
int estadobotao = 0; 

void setup() {
  pinMode(pinoled, OUTPUT);     //LED é um output 
  pinMode(pinobotao, INPUT);    // botão é um input 
}

void loop(){
  estadobotao = digitalRead(pinobotao);
    if (estadobotao == HIGH) {              // botão está pressionado
      if(on==1){
      on=0;                               // troca pro estado desligado
      }  
      else{
      on=1;                               // troca pro estado ligado
    }
  }
 
if (on == 1) {                 //se estiver ligado
  digitalWrite(pinoled, HIGH);  // acender o led
  }
else {                          // se estiver desligado
  digitalWrite(pinoled, LOW);   // desligar o LED
  }

delay(300);                    // espera 0,3 s
  
}
