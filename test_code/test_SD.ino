#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  while (!Serial) {
  }

  Serial.println("inizializzazione SD...");
  if (!SD.begin(10)) {
    Serial.println("errore di inizializzazione");
    return;
  }
  Serial.println("SD pronta");

// SCRITTURA FILE
  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile) {
    Serial.print("scrivendo su test.txt...");
    myFile.println("esempio di prova.\nQuesto dovrebbe essere capo!\n");
    myFile.close();
  } else {
    // errore in apertura
    Serial.println("errore in apertura test.txt");
  }
// LETTURA FILE
  /*
  // ri apro per leggere:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("contenuto test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("errore in apertura test.txt");
  }
  */
}

void loop() {
}
