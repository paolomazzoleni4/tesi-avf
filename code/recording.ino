#include <SPI.h>
#include <SD.h>

//Parameters
const int micPin  = A0;
const int chipSelect = 10;
const int NDATI  = 10000;

//Variables
int micVal  = 0;
int i = 0;
int j = 0;
File myFile;
int valori [NDATI];

void setup() {
  //inizializzo, imposto il pin output, attendo la seriale
  Serial.begin(9600);
  pinMode(chipSelect, OUTPUT);
  while (!Serial) {
  }

  //controllo comunicazione con SD
  if (!SD.begin(chipSelect)) {
    Serial.println("errore di inizializzazione");
    while(1);
  }
}

void loop() {
  //leggo valore e lo salvo in posizione i array
  micVal = analogRead(micPin);
  valori[i] = micVal;
  i++;

  //quando arrivo a fine lettura NDATI valori, devo scriverli su sd
  if(i >= NDATI){
    //Serial.println("inizio scrittura dati");
    myFile = SD.open("dati.txt", FILE_WRITE);
    if (myFile) {
      for(i=0;i<NDATI;i++){
        myFile.println(valori[i]);
      }
    } else {
      Serial.println("errore nell'apertura del file");
    }
    myFile.close();
    i = 0;
    j++;
    Serial.print("fine scrittura dati ciclo:");
    Serial.println(j);
  }
}