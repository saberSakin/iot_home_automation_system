#define BLYNK_USE_DIRECT_CONNECT
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); // RX, TX

#define BLYNK_PRINT BT
#include <BlynkSimpleSerialBLE.h>

const int IN1 = 6;// Input for channel 1(Light)
const int IN2 = 5;// Input for channel 2(Fan)
int light,fan;

// You should get Auth Token in the Blynk App
char auth[] = "YourAuthToken"; //Place the authentication token you got from the e-mail.

void setup()
{
  BT.begin(38400); //For HC-05 default speed is 38400
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(38400);
  Blynk.begin(Serial, auth);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);    
}

BLYNK_WRITE(V0){
  light = param.asInt();
}
BLYNK_WRITE(V1){
  fan = param.asInt();
}

void loop()
{
  Blynk.run();
  //Control relay channel 1 based on value of variable 'Light'
  if(light == 1){
    digitalWrite(IN1, HIGH);  
  }else{
    digitalWrite(IN1, LOW);  
  }

  //Control relay channel 2 based on value of variable 'Fan'
  if(fan == 1){
    digitalWrite(IN2, HIGH);  
  }else{
    digitalWrite(IN2, LOW);  
  }
}