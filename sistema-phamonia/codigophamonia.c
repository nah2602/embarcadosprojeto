
#define QUENTELED 13 //ativa resfriamento  
#define MEDETEMP A0 // termometro
#define FRIOLED 12 //ativa aquecimento
#define ALARME 11 // alarme 
#define LEDBOMBA 10 // ativa a bomba e seu led 
#define BOIASIMU A1 // simulador de boia 
#define LEDESVAZIA 9 // ativa esvasiador de agua e seu led
#define PHSIMU A2 // verificador de PH
#define LEDPH 8 // Led alerta de PH 
#define AMONIALED 7// Led alerta Amonia
#define AMONIASIMU A3 // Verifiar Amonia


float temp, tempc, tempmv;
int tempva, nivelva, phva, amoniava;
int phn,amonian; // para acionar o sistema de troca dagua 
float ph;
int nivel;
float amonia;

void setup()
{
  pinMode(MEDETEMP, INPUT);
  pinMode(QUENTELED, OUTPUT);
  pinMode(FRIOLED, OUTPUT);
  pinMode(ALARME, OUTPUT);
  pinMode(LEDBOMBA, OUTPUT);
  pinMode(BOIASIMU, INPUT);
  pinMode(LEDESVAZIA, OUTPUT);
  pinMode(PHSIMU, INPUT);
  pinMode(LEDPH, OUTPUT);
  pinMode(AMONIASIMU, INPUT);
  pinMode(AMONIALED, OUTPUT);
  lcd.begin(16,2);

 
  Serial.begin(9600);
}
void loop()
{
  
  phe();
  tempe();
  amoniae();
  nivele();
  
  if ( tempva ==1 || phva ==1 || amoniava==1||nivelva== 1)
  {
    tone (ALARME, 540);
  }
  
  else 
  {
   noTone(ALARME); 
  }
  
}
void amoniae ()
{
 int sensoramo =  analogRead(AMONIASIMU);
 amonia = sensoramo *(0.5/1023.0);
 Serial.print("Nivel de Amonia eh: ");
 Serial.println(amonia);
  if (amonia<0.02)
  {
    digitalWrite(AMONIALED,LOW);
    amoniava=0;
    Serial.println("Nivel de amonia ideal!");
  }
  else if (amonia>= 0.02 && amonia<0.04)
  {
     digitalWrite(AMONIALED, HIGH);
    amoniava=0;
  }
  else if (amonia >= 0.04 && amonia <0.06)
  {
    amonian=1;
    digitalWrite(AMONIALED, HIGH);
  }
  else 
  {
    amoniava=1;
  }
}

void phe ()
{
  int sensorph = analogRead(PHSIMU);
  ph = sensorph* (14.0/1023.0);
  Serial.print("O PH eh: ");
  Serial.println(ph);
  if (ph<5.5 || ph >9.0)
  {
    digitalWrite(LEDPH,HIGH);
    phva = 1;
    phn=0;
    Serial.println("PH muito alterado!");
  }
  else if ( (ph>8.0 && ph<=9.0)|| (ph<6.0 && ph>=5.5))
  {
     digitalWrite(LEDPH,HIGH);
    phn=1;
     Serial.println("PH alterado!");
  }
     
  else
  {
    digitalWrite(LEDPH,LOW);
    phva = 0;
    phn=0;
  }
  
}
void nivele()
{
  nivel = analogRead (BOIASIMU);
  Serial.print("O nivel dagua eh: ");
  Serial.println(nivel);
  
  if ((nivel < 900) && (nivel >= 1)) {
    digitalWrite (LEDBOMBA, HIGH);
    digitalWrite (LEDESVAZIA, LOW);
  }
  else if (nivel >= 900 && nivel <950){ //momento em que o sistema pode ser ativo
    digitalWrite (LEDBOMBA, LOW);
    digitalWrite (LEDESVAZIA, LOW);
    if (phn ==1 || amonian==1)
    {
      digitalWrite (LEDESVAZIA, HIGH);
      delay(1000);
      digitalWrite (LEDESVAZIA, LOW);
      digitalWrite (LEDBOMBA, HIGH);
      delay(1000);
      digitalWrite (LEDBOMBA, LOW);
    }
  }
  if (nivel >= 950) {
    nivelva =1;
    digitalWrite (LEDESVAZIA, HIGH);
   
  }
  else if (nivel < 950){
   
    nivelva =0;
  
  
  }
}
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

