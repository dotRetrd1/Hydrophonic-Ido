#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;
uint8_t labDiskAdress[6] = {0x7C, 0x6B, 0x52, 0x96, 0x4E, 0x2D};
const char *pin = "1234";

void setup() {
    Serial.begin(115200);
  BT.begin("ESP32_Client", true);
  BT.setPin(pin);

  Serial.println("Attempting connection to labdisc");
  bool connected = BT.connect(labDiskAdress);
  
  if (connected) { Serial.println("Connected."); }
  else { Serial.println("Failed to connect, make sure is in pairing mode"); }

  Serial.println("startup");
}

void loop() {

}

void readLabDisc() {
  if (Serial.available()) {
    // labdisc to pc
    BT.write(Serial.read());
    // pc to labdisc
    Serial.write(BT.read());
  }
}
