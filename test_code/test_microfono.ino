//Parameters
const int micPin  = A0;

//Variables
int micVal  = 0;
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
}

void loop() {
  micVal = analogRead(micPin);
  Serial.print(F("mic val ")); Serial.println(micVal);

  /*i++;
  if(i>=50000){
    while(1);
  }*/
} 