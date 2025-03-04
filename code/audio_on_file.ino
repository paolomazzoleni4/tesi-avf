#include <SPI.h>
#include <SD.h>

//Parameters
const int micPin  = A0;

//Variables
int micVal  = 0;
int i = 0;
//int j = 0;
File myFile;
int valori [25000];

void setup() {
  //inizializzo, imposto il pin output, attendo la seriale
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  while (!Serial) {
  }

  //controllo comunicazione con SD
  if (!SD.begin(10)) {
    Serial.println("errore di inizializzazione");
    while(1);
  }
}

void loop() {
  //leggo valore e lo salvo in posizione i array
  micVal = analogRead(micPin);
  valori[i] = micVal;
  i++; //contatore parziale
  //j++; //contatore totale

  //quando arrivo a fine lettura 25000 valori, devo scriverli su sd
  if(i >= 25000){
    Serial.println("inizio scrittura dati");
    myFile = SD.open("dati.txt", FILE_WRITE);
    if (myFile) {
      for(i=0;i<25000;i++){
        myFile.println(valori[i]);
      }
      Serial.println("scrittura 25.000 dati avvenuta");
    } else {
      Serial.println("errore nell'apertura del file");
    }
    myFile.close();
    i = 0;
    Serial.println("fine scrittura dati");
    while(1);
    /*
    //scrivo 10 volte 25.000 valori
    //a 250.000 valori finisce il programma
    if(j >= 250000){
      Serial.println("fine TUTTO");
      while(1);
    }
    */
  }
}