
#define QUENTELED 13 // ativa resfriamento  
#define MEDETEMP A0 // termometro
#define FRIOLED 12 // ativa aquecimento
#define ALARME 11


float temp, tempc, tempmv;
int tempva;
void setup()
{
  pinMode(MEDETEMP, INPUT);
  pinMode(QUENTELED, OUTPUT);
  pinMode(FRIOLED, OUTPUT);
  pinMode(ALARME, OUTPUT);
  Serial.begin(9600);
}

void loop()

{
  tempe();
  if ( tempva ==1 )  //ativar alarme
  {
    tone (ALARME, 540);
  }
  
  else 
  {
   noTone(ALARME); 
  }
}

void tempe() //calculos e restricoes sobre temperatura
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
