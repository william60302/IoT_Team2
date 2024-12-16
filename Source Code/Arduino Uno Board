//1210 UNO+LORA

#include <FastLED.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>
#include <SPI.h>
#include <LoRa.h> // LoRa 庫

// 定義燈條參數
#define LED_PIN 6
#define NUM_LEDS 60
#define BRIGHTNESS 128
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB
#define DHT_TYPE DHT11
CRGB leds[NUM_LEDS];

// 定義感測器與控制腳位
const int LIGHT_SENSOR = A0;
const int PIR_SENSOR = 3;
const int SOIL_SENSOR = A1;
const int RELAY_PIN = 7;
const int LIGHT_THRESHOLD = 500;
const int SOIL_THRESHOLD = 600;
const int DHT_PIN = 4;

DHT dht(DHT_PIN, DHT_TYPE);
BH1750 lightMeter;

void setup() {
  // 初始化序列埠
  Serial.begin(9600);

  // 設置腳位模式
  pinMode(PIR_SENSOR, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // 初始化燈條
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // 初始化 DHT
  dht.begin();
  Serial.println("DHT sensor initialized.");

  // 初始化 GY-302
  Wire.begin();
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("GY-302 sensor initialized.");
  } else {
    Serial.println("Error initializing GY-302 sensor.");
  }

  // 初始化 LoRa
  if (!LoRa.begin(915E6)) { // 設定 LoRa 頻率，依模組和地區規範調整（例如 433E6, 868E6, 或 915E6）
    Serial.println("LoRa initialization failed!");
    while (1);
  }
  Serial.println("LoRa initialized.");
}

void loop() {
  // 1. 讀取光敏電阻數據
  int lightValue = analogRead(LIGHT_SENSOR);
  Serial.print("Analog Light Level: ");
  Serial.println(lightValue);

  // 2. 讀取 PIR 感測器數據
  bool motionDetected = digitalRead(PIR_SENSOR);
  Serial.print("Motion Detected: ");
  Serial.println(motionDetected ? "Yes" : "No");

  // 3. 讀取土壤濕度數據並控制水泵
  int soilValue = analogRead(SOIL_SENSOR);
  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  if (soilValue > SOIL_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH);  // 啟動水泵
    Serial.println("Soil is dry, activating water pump");
  } else {
    digitalWrite(RELAY_PIN, LOW);   // 停止水泵
    Serial.println("Soil is wet, stopping water pump");
  }

  // 4. 讀取 DHT 感測器數據
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return; // 若 DHT 資料無效則跳過此迴圈
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // 5. 讀取 GY-302 光照數據
  float lux = lightMeter.readLightLevel();
  Serial.print("GY-302 Light Level: ");
  Serial.print(lux);
  Serial.println(" lux");

  // 6. 組合數據字串準備發送
  String message = "Light: " + String(lightValue) +
                   ", Motion: " + (motionDetected ? "Yes" : "No") +
                   ", Soil: " + String(soilValue) +
                   ", Temp: " + String(temperature) + "C" +
                   ", Hum: " + String(humidity) + "%" +
                   ", Lux: " + String(lux) + "lx";

  // 7. 使用 LoRa 發送數據
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
  Serial.println("Sent: " + message);

  // 8. 控制燈條顯示邏輯
  if (motionDetected) {
    fill_solid(leds, NUM_LEDS, CRGB::White);
    Serial.println("PIR triggered: Lights ON");
  } else if (lightValue > LIGHT_THRESHOLD ) {
    fill_solid(leds, NUM_LEDS, CRGB(255, 220, 180)); // 暖白光
    Serial.println("Low light: Lights ON");
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::Black); // 關閉燈條
    Serial.println("Lights OFF");
  }

  // 9. 更新燈條顯示
  FastLED.show();
  Serial.println("_________________-");
  // 10. 延遲
  delay(1000);
}

