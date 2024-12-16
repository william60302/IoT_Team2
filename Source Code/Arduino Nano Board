//OLE LoRa final
#include <SPI.h>
#include <LoRa.h>       // LoRa 通訊
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h> // 更改為您的顯示器驅動

// OLED 設定
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

/*
OLED    | Nano
------------
GND     | GND
5V      | 5V
SCK/SCL | A5
SDA     | A4
*/

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

void setup() {
  // 初始化 OLED
  display.begin(SH1106_SWITCHCAPVCC, 0x3c); // OLED 的 I2C 地址為 0x3c
  display.display();
  display.clearDisplay();

  // 初始化序列埠
  Serial.begin(9600);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("LoRa Receiver"));
  display.display();
  delay(2000);

  // 初始化 LoRa
  if (!LoRa.begin(915E6)) { // 根據模組設置正確的頻率 (如 915 MHz)
    Serial.println(F("LoRa initialization failed!"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("LoRa Init Failed!"));
    display.display();
    while (1);
  }

  Serial.println(F("LoRa receiver initialized."));
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("LoRa Receiver"));
  display.display();
}
void loop() {
  // 清空 OLED 顯示
  display.clearDisplay();

  // 檢查是否收到 LoRa 數據包
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    Serial.print(F("Received packet: "));

    // 讀取 LoRa 訊息
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.println(received);

    // 分析數據內容
    String light = received.substring(received.indexOf("Light:") + 7, received.indexOf(", Motion"));
    String motion = received.substring(received.indexOf("Motion:") + 8, received.indexOf(", Soil"));
    String soil = received.substring(received.indexOf("Soil:") + 6, received.indexOf(", Temp"));
    String temp = received.substring(received.indexOf("Temp:") + 6, received.indexOf("C, Hum"));
    String hum = received.substring(received.indexOf("Hum:") + 5, received.indexOf("%, Lux"));
    String lux = received.substring(received.indexOf("Lux:") + 5, received.indexOf("lx"));

    // 顯示數據到 OLED
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(F("LoRa Data"));
    display.println(F("------------------"));
    display.print(F("Light: "));
    display.println(light);
    display.print(F("Motion: "));
    display.println(motion);
    display.print(F("Soil: "));
    display.println(soil);
    display.print(F("Temp: "));
    display.print(temp);
    display.println(F("C"));
    display.print(F("Hum: "));
    display.print(hum);
    display.println(F("%"));
    display.print(F("Lux: "));
    display.println(lux);
    display.display();

    // 傳送數據給 ESP8266
    String sendData = "Light:" + light + ",Motion:" + motion + ",Soil:" + soil + ",Temp:" + temp + ",Hum:" + hum + ",Lux:" + lux;
    Serial.println(sendData); // 直接用 Serial 發送
    delay(1000); // 延遲一秒，便於觀察
  }
}
