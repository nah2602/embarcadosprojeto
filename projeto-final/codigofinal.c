
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
#include<LiquidCrystal.h>
const int rs =A4,en = A5,d4 =6,d5 =5,d6 =4,d7 =3;
LiquidCrystal lcd(rs,en, d4,d5,d6,d7);

float temp, tempc, tempmv;
int tempva, nivelva, phva, amoniava;
int phn,amonian;
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
  lcde();
  phe();
  tempe();
  amoniae();
  nivele();
 

    if ( (tempva ==1 || phva ==1 || amoniava==1) && nivelva== 0 && phn !=1 && amonian!=1) // restrição do uso do alarme
   {
    tone (ALARME, 540);
   }
  else if ( nivelva ==1){
    tone (ALARME, 540);
  }
    else 
   {
   noTone(ALARME); 
   }
  
  
}

void lcde () // para quando o LCD esta normal
{
  if ((phn !=1 && amonian!=1 && tempva !=1 && phva !=1 && amoniava !=1 && nivelva!=1) || nivelva==2){
    lcd.clear();   
    lcd.setCursor(0,0);
    lcd.print("PH:");
    lcd.setCursor(3,0);
    lcd.print(ph);
    lcd.setCursor(9,0);
    lcd.print("A:");
    lcd.setCursor(11,0);
    lcd.print(amonia);
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.setCursor(2,1);
    lcd.print(tempc);
    lcd.setCursor(7,1);
    lcd.print("C");
    lcd.setCursor(9,1);
    lcd.print("N:");
    lcd.setCursor(11,1);
    lcd.print(nivel);
    lcd.setCursor(14,1);
    lcd.print("L");
    
  }
  
}

void amoniae ()
{
 int sensoramo =  analogRead(AMONIASIMU);
 amonia = sensoramo *(0.5/1023.0);
 Serial.print("Nivel de Amonia eh: ");
 Serial.println(amonia);
  if (amonia<0.02) //amonia boa
  {
    digitalWrite(AMONIALED,LOW);
    amoniava=0;
    amonian=0;
    Serial.println("Nivel de amonia ideal!");
  }
  else if (amonia>= 0.02 && amonia<0.04) //aceitavel
  {
     digitalWrite(AMONIALED, HIGH);
    amoniava=0;
    amonian=0;
  }
  else if (amonia >= 0.04 && amonia <0.06)// faz troca parcial
  {
    amonian=1;
    amoniava=0;
    digitalWrite(AMONIALED, HIGH);
  }
  else 
  {
    lcd.setCursor(0,1);
    lcd.print("Amo Alta:  ");
    lcd.setCursor(11,1);
    lcd.print(amonia);
    amonian=0;
    amoniava=1;
  }
}

void phe ()
{
  int sensorph = analogRead(PHSIMU);
  ph = sensorph* (14.0/1023.0);
  Serial.print("O PH eh: ");
  Serial.println(ph);
  if (ph<5.5  )
  {
    lcd.setCursor(0,0);
    lcd.print("PH Baixo:   ");
    lcd.setCursor(11,0);
    lcd.print(ph);
    digitalWrite(LEDPH,HIGH);
    phva = 1;
    phn=0;
    
    
  }
  else if (ph >9.0)
  { 
    lcd.setCursor(0,0);
    lcd.print("PH Alto:   ");
    lcd.setCursor(11,0);
    lcd.print(ph);
    lcd.setCursor(0,0);
    digitalWrite(LEDPH,HIGH);
    phva = 1;
    phn=0;
    
  }
  else if ( (ph>8.0 && ph<=9.0)|| (ph<6.0 && ph>=5.5)) // faz troca parcial
  {
     digitalWrite(LEDPH,HIGH);
    phn=1;
     Serial.println("PH alterado!");
  }
     
  else // ph normal
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
  
  if ((nivel < 900) && (nivel >= 0)) {
    digitalWrite (LEDBOMBA, HIGH);
    digitalWrite (LEDESVAZIA, LOW);
    nivelva = 2;
  }
  else if (nivel >= 900 && nivel <950){
    
    if (phn ==1 || amonian==1)//parte de troca parcial
    {
      lcd.clear();
      lcd.setCursor(0,0);
  	  lcd.print(" Troca  Parcial ");
      lcd.setCursor(0,1);
   	  lcd.print("PH:");
      lcd.setCursor(3,1);
      lcd.print(ph);
      lcd.setCursor(9,1);
      lcd.print("A:");
      lcd.setCursor(11,1);
      lcd.print(amonia);
      digitalWrite (LEDESVAZIA, HIGH);
      delay(1000);
      digitalWrite (LEDESVAZIA, LOW);
      digitalWrite (LEDBOMBA, HIGH);
      delay(1000);
      digitalWrite (LEDBOMBA, LOW);
      lcd.clear();
    }
    else { // nivel normal
     digitalWrite (LEDBOMBA, LOW);
     digitalWrite (LEDESVAZIA, LOW);
    }
    nivelva =0;
  }
  if (nivel >= 950) {
    lcd.clear();
    lcd.setCursor(0,0);
  	lcd.print(" Aquario  Cheio ");
    lcd.setCursor(2,1);
   	lcd.print("Nivel:");
    lcd.setCursor(9,1);
    lcd.print(nivel);
    lcd.setCursor(13,1);
   	lcd.print("L");
    nivelva =1;
    digitalWrite (LEDESVAZIA, HIGH);
  }
}
void tempe()
{
  
  temp = analogRead(MEDETEMP);
  tempmv = temp*5000/1024;
  tempc= (tempmv/10)+(-50);
  Serial.print("A temperatura eh: ");
  Serial.println(tempc);
 
  if ((tempc >27 ) )
  {
      lcd.clear();
      lcd.setCursor(0,0);
  	  lcd.print(" Temp nao Ideal ");
      lcd.setCursor(3,1);
   	  lcd.print("T:");
      lcd.setCursor(6,1);
      lcd.print(tempc);
      lcd.setCursor(11,1);
      lcd.print("C");
    
    digitalWrite(QUENTELED,HIGH);
    digitalWrite(FRIOLED,LOW);
    tempva =1;
    delay(1000);
    lcd.clear();
  }
  else if(tempc <19   )
    {
      lcd.clear();
      lcd.setCursor(0,0);
  	  lcd.print(" Temp nao Ideal ");
      lcd.setCursor(3,1);
   	  lcd.print("T:");
      lcd.setCursor(6,1);
      lcd.print(tempc);
      lcd.setCursor(11,1);
      lcd.print("C");
    
    digitalWrite(FRIOLED,HIGH);
    digitalWrite(QUENTELED,LOW);
    tempva =1;
    delay(1000);
    lcd.clear();
  }
  else if(tempc <21  && (phn !=1 && amonian!=1))
  {
    digitalWrite(QUENTELED,LOW);
    digitalWrite(FRIOLED,HIGH);
  }
  else if( tempc >25  && (phn !=1 && amonian!=1) )
  {
    digitalWrite(QUENTELED,HIGH);
    digitalWrite(FRIOLED,LOW);
  }
 
  else // temp normal
  {
    digitalWrite(QUENTELED,LOW);
    digitalWrite(FRIOLED,LOW);
    tempva=0;
    
    Serial.println("Temperatura ideal!");
    delay(1000);
    
  }

}  
