// codigo ja inclui o codigo de temperatura

#define QUENTELED 13 //ativa resfriamento  
#define MEDETEMP A0 // termometro
#define FRIOLED 12 //ativa aquecimento
#define ALARME 11 // alarme 
#define LEDBOMBA 10 // ativa a bomba e seu led 
#define BOIASIMU A1 // simulador de boia 

float temp, tempc, tempmv;
int tempva, nivelva;
void setup()
{
  pinMode(MEDETEMP, INPUT);
  pinMode(QUENTELED, OUTPUT);
  pinMode(FRIOLED, OUTPUT);
  pinMode(ALARME, OUTPUT);
  pinMode(LEDBOMBA, OUTPUT);
  pinMode(BOIASIMU, INPUT);
  Serial.begin(9600);
}
void loop()
{
  
  
  nivele();
  tempe();
  
  if (nivelva== 1 || tempva ==1 ) //adicao do nivel
  {
    tone (ALARME, 540);
  }
  
  else 
  {
   noTone(ALARME); 
  }
  
}
// configuracao do nivel 
void nivele()
{
  int nivel = analogRead (BOIASIMU);
  Serial.print("O nivel dagua eh: ");
  Serial.println(nivel);
  
  if ((nivel < 900) && (nivel >= 1)) {
    digitalWrite (LEDBOMBA, HIGH);
  }
  else if (nivel >= 900){
    digitalWrite (LEDBOMBA, LOW);
  }
  if (nivel >= 950) {
    nivelva =1;
   
  }
  else if (nivel < 950){
   
    nivelva =0;
  
  }
}
//configuracao da temperatura(ja apresentado)
void tempe()
{
  
  temp = analogRead(MEDETEMP);
  tempmv = temp*5000/1024;
  tempc= (tempmv/10)+(-50);
  Serial.print("A temperatura eh: ");
  Serial.println(tempc);
  
  if (tempc >27)
  {
    digitalWrite(QUENTELED,HIGH);
    
    tempva =1;
    
  }
  else if (tempc<19)
  {
   
    digitalWrite(FRIOLED,HIGH);
    tempva=1;
    
  }
  else if(tempc <21)
  {
    digitalWrite(QUENTELED,LOW);
    digitalWrite(FRIOLED,HIGH);
  }
  else if (tempc >25)
  {
    digitalWrite(QUENTELED,HIGH);
    digitalWrite(FRIOLED,LOW);
  }
  else
  {
    digitalWrite(QUENTELED,LOW);
    digitalWrite(FRIOLED,LOW);
    tempva=0;
    
    Serial.println("Temperatura ideal!");
    delay(1000);
    
  }
}  
