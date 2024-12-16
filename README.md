# IoT_Team2
Measure various environmental factors more preciously and use the Internet of Things (IoT) to transmit data, achieving real-time monitoring of plant growth.  Automatically control the whole greenhouse system to adjust the irrigation levels, light exposure, and temperature and humidity to optimize growth conditions.

Our Website URL: https://m11351015.wixsite.com/my-site-2/projects

# Team Member
- M11351015 Larry 李國楨
- M11251001 Cindy 張芊凡
- M11351010 Melody 陳玫寧
- M11351017 William 陳彥齊


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
 

### Data Transmit
```mermaid
flowchart TB
  subgraph Flow Process
    direction TB
    subgraph Arduino_Board1
        direction LR
        Arduino_Uno --> Mini_LoRa_Uno
    end
    subgraph Arduino_Board2
        direction LR
        Mini_LoRa_Nano --> Arduino_Nano --> ESP8266
    end
    subgraph Website
        direction LR
        Blynk
    end
  end
  Arduino_Board1-- Through Mini_LoRa --> Arduino_Board2
  Arduino_Board2-- Through WiFi --> Website 

```


# Functions
The following charts shows the functions we aimed to put into our project at the beginning.

## Monitor
| Monitoring  | Specification | Finished |
| ------------- | ------------- | ------------- |
| Soil Humidity | Content Cell  |<ul><li>- [x] </li>
| Air Temperature & Humidity  | Content Cell  |<ul><li>- [x] </li>
| Motion Detection | Content Cell |<ul><li>- [x] </li>
| Camera Supervision| Content Cell |<ul><li>- [x] </li>
| Brightness | Photoresistor |<ul><li>- [x] </li>

## Actuation
| Actuation | Specification | Finished |
| ------------- | ------------- | ------------- |
| Soil Humidity | Content Cell  |<ul><li>- [x] </li>
| Air Temperature & Humidity  | Content Cell  |<ul><li>- [x] </li>
| Motion Detection | Content Cell |<ul><li>- [x] </li>

## Communication
| Monitoring  | Specification | Finished |
| ------------- | ------------- | ------------- |
| LoRa | Content Cell  |<ul><li>- [x] </li>
| WiFi | Content Cell  |<ul><li>- [x] </li>

## Power
| Monitoring  | Specification | Finished |
| ------------- | ------------- | ------------- |
| Soil Humidity | Content Cell  |<ul><li>- [x] </li>
| Air Temperature & Humidity  | Content Cell  |<ul><li>- [x] </li>

## Data 
| Monitoring  | Specification | Finished |
| ------------- | ------------- | ------------- |
| Blynk | Data collect &  |<ul><li>- [x] </li>


# 接線圖
## Overall Wiring diagram
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_3.jpg)

## PIR Motion Sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_1.jpg)

## Photoresistor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_2.jpg)

## Soil Humidity & temperature Sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_6.jpg)

## DHT sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_7.jpg)

## ESP8266
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_4.jpg)




  
