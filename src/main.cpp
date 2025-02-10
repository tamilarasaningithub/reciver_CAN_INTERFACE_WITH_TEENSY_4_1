#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;

void setup()
{
  Serial.begin(115200);
  delay(100);
  can1.begin();
  delay(100);
  can1.setBaudRate(500000);
  delay(1000);
  Serial.println("CAN1 Receiver Initialized");
  delay(100);
}

void loop()
{
  delay(100);
  CAN_message_t msg;
  delay(100);
  if (can1.read(msg))
  { // Check if message is received
    Serial.print("Received Message: ");
    for (int i = 0; i < msg.len; i++)
    {
      Serial.print((char)msg.buf[i]);
    }
    delay(100);
    Serial.println();
  }
}
