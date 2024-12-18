//  ESP8266 final
#define BLYNK_TEMPLATE_ID "TMPL6GuPjqfsW"
#define BLYNK_TEMPLATE_NAME "lora"
#define BLYNK_AUTH_TOKEN "RK_QvSWR4n82sLoLtLcR29qplmDN8nHo"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "RK_QvSWR4n82sLoLtLcR29qplmDN8nHo";
char ssid[] = "Factory2_2.4G";
char pass[] = "118factory2";


void setup() {
  Serial.begin(9600);  // 與 Arduino Nano 的通信速率
  Blynk.begin(auth, ssid, pass);

  Serial.println("ESP8266 ready and connected to WiFi");
}
void loop() {
  Blynk.run();

  // 檢查是否收到 Arduino Nano 的數據
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n'); // 接收完整數據行
    Serial.println("Received from Nano: " + data);

    // 檢查數據是否包含關鍵字以確保格式正確
    if (data.indexOf("Light:") != -1 &&
        data.indexOf("Motion:") != -1 &&
        data.indexOf("Soil:") != -1 &&
        data.indexOf("Temp:") != -1 &&
        data.indexOf("Hum:") != -1 &&
        data.indexOf("Lux:") != -1) {
      
      // 提取數據
      String light = data.substring(data.indexOf("Light:") + 7, data.indexOf(", Motion:"));
      String motion = data.substring(data.indexOf("Motion:") + 8, data.indexOf(", Soil:"));
      String soil = data.substring(data.indexOf("Soil:") + 6, data.indexOf(", Temp:"));
      String temp = data.substring(data.indexOf("Temp:") + 6, data.indexOf("C, Hum:"));
      String hum = data.substring(data.indexOf("Hum:") + 5, data.indexOf("%, Lux:"));
      String lux = data.substring(data.indexOf("Lux:") + 5, data.indexOf("lx"));

      // 將解析出的數據發送到 Blynk
      Blynk.virtualWrite(V1, light.toFloat());   // 發送 Light 數值到虛擬引腳 V1
      Blynk.virtualWrite(V2, motion);           // 發送 Motion 狀態到虛擬引腳 V2
      Blynk.virtualWrite(V3, soil.toInt());     // 發送 Soil 數值到虛擬引腳 V3
      Blynk.virtualWrite(V4, temp.toFloat());   // 發送 Temp 數值到虛擬引腳 V4
      Blynk.virtualWrite(V5, hum.toFloat());    // 發送 Hum 數值到虛擬引腳 V5
      Blynk.virtualWrite(V6, lux.toFloat());    // 發送 Lux 數值到虛擬引腳 V6

      // 在 Serial Monitor 中確認數據解析正確
      Serial.println("Parsed Data:");
      Serial.println("Light: " + light);
      Serial.println("Motion: " + motion);
      Serial.println("Soil: " + soil);
      Serial.println("Temp: " + temp);
      Serial.println("Hum: " + hum);
      Serial.println("Lux: " + lux);
    } else {
      Serial.println("Error: Invalid data format received.");
    }
  }
}

