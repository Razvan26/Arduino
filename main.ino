#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);  // TX-Pin11, RX-Pin10

void updateSerial()
{
  delay(2000);
  while (Serial.available()) {
    mySerial.write(Serial.read());
    }
  while(mySerial.available()) {
    Serial.write(mySerial.read());
    }
  
}   

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{ 
  mySerial.println("AT");          // Once the handshake test is successful, it will back to OK

  updateSerial();
  mySerial.println("AT+CMGF=1");   // Configuring mode is TEST, only English texts are available
  updateSerial();
  mySerial.println("AT+CMGS=\"0x0x0x0x\"");//xxxxxxxxxxx is the phone number
  updateSerial();
  mySerial.print("test"); //text content
  updateSerial();
  mySerial.write(26);
     
}
