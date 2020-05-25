/*
 * Test Code for Custom Electonics Communication for communication between a Vex V5 and a Teensy LC, 3.2, 3.5, 3.6, 4.0
 * 
 * Pinout:
 * Smart Port RX Pin 0
 * Smart Port TX Pin 1
 */

void setup() {
  // put your setup code here, to run once:
  //Communication to the V5 via Serial1(pin 0 and 1)
  Serial1.begin(115200);
  //Communication to the computer via USB
  Serial.begin(115200);
  Serial.println("Custom Electonics Test Code");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial1.available() > 0){
    //Read Capitol Letter and Send Lower Case Letter and print both to USB Serial
    int inbyte = Serial1.read();
    Serial.print(currentMillis);
    Serial.print(" Serial Read: ");
    Serial.print(inbyte);
    inbyte += 32;
    Serial1.print(inbyte);
    Serial.print(" Serial Write: ");
    Serial.println(inbyte);
  }
}
