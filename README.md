# IoT_Team2
Measure various environmental factors more preciously and use the Internet of Things (IoT) to transmit data, achieving real-time monitoring of plant growth.  Automatically control the whole greenhouse system to adjust the irrigation levels, light exposure, and temperature and humidity to optimize growth conditions.

# Team Member
- M11351015 Larry
- M11251001 Cindy
- M11351010 Melody
- M11351017 William


# System Architecture
- **Central Controller**: Raspberry Pi 4 connected to a router, serving as the system's hub.
- **Sensors and Actuators**:
  - ESP8266 (Wemos D1 R2 board)
  - SG90 Servo Motor
  - LED Light Strip
  - OLED Display
  - 
  - Soil Condition Sensor
  - DHT Sensor(Temperature and Humidity Sensor)
  - PIR Motion Sensor
  - Water Pump
 


```mermaid
graph TD;
    Arduino Uno-->LoRa(Uno);
    LoRa(Uno)-->LoRa(Nano);
    LoRa(Nano)-->Arduino Nano;
    Arduino Nano-->ESP8266;
    ESP8266-->BLYNK
```


# Function
| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |




# 接線圖
  
