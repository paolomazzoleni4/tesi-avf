#include <SPI.h>
#include <SD.h>

//Parameters
const int micPin  = A0;

//Variables
int micVal  = 0;
int i = 0;
File myFile;
int valori [5000];

void setup() {
  //inizializzo, imposto il pin output, attendo la seriale
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  while (!Serial) {
  }

  //controllo comunicazione con SD
  if (!SD.begin(10)) {
    // se non a buon fine, errore e rimango in loop
    Serial.println("errore di inizializzazione");
    while(1);
  }
}

void loop() {
  //leggo valore e lo salvo in posizione i array
  micVal = analogRead(micPin);
  valori[i] = micVal;
  i++;

  //quando arrivo a fine lettura 5000 valori, devo scriverli su sd
  if(i >= 5000){
    myFile = SD.open("test.txt", FILE_WRITE);
    if (myFile) {
      for(i=0;i<5000;i++){
        myFile.println(valori[i]);
      }
      Serial.print("scrittura 5.000 dati avvenuta");
    } else {
      Serial.print("errore nell'apertura del file");
    }
    myFile.close();
    while(1);
  }
}