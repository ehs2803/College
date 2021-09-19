char inputchar = "";         
bool charComplete = false;  

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (charComplete) {
    Serial.print("I recevied : ");
    Serial.write(inputchar);
    Serial.print(", whose ASCII code is ");
    Serial.print(inputchar,HEX);
    Serial.print(". - FYI, DEC = ");
    Serial.println(inputchar,DEC);
    inputchar = "";
    charComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputchar = inChar;
    charComplete = true;    
  }
}