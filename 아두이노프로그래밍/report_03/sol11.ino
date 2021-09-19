void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()>0){
    char a=Serial.read();
    if(97<=a&&a<=122){
      Serial.write(a);
      a=a-32;
      Serial.print("  ");
      Serial.println(a);
    }
  }
}
 