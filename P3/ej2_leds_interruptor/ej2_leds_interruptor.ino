// C++ code
//
void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(7, INPUT_PULLUP);
}

void loop(){
  
  if (digitalRead(7) == LOW) {  
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  } else {
    
    digitalWrite(12, HIGH);
    delay(1500); // Wait for 1500 millisecond(s)
    digitalWrite(12, LOW);

    digitalWrite(11, HIGH);
    delay(1500); // Wait for 1500 millisecond(s)
    digitalWrite(11, LOW);
    
    digitalWrite(13, HIGH);
    delay(1500); // Wait for 1500 millisecond(s)
    digitalWrite(13, LOW);
  }
  
}
