# IoT_Team2
Measure various environmental factors more preciously and use the Internet of Things (IoT) to transmit data, achieving real-time monitoring of plant growth.  Automatically control the whole greenhouse system to adjust the irrigation levels, light exposure, and temperature and humidity to optimize growth conditions.

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
 


```mermaid
graph TD;
    Arduino_Uno-- Send Data -->LoRa;
    LoRa-- Send Data -->Arduino_Nano;
    Arduino_Nano-- Send Data -->ESP8266;
    ESP8266-- Send Data -->BLYNK
```
```mermaid
flowchart LR
  subgraph TOP
    direction TB
    subgraph B1
        direction RL
        i1 -->f1
    end
    subgraph B2
        direction BT
        i2 -->f2
    end
  end
  A --> TOP --> B
  B1 --> B2
```


# Function
| Monitoring  | Specification | Finished |
| ------------- | ------------- | ------------- |
| Soil Humidity | Content Cell  |
| Air Temperature & Humidity  | Content Cell  |
| Motion Detection | Content Cell |
| Camera Supervision| Content Cell |
| Brightness | Photoresistor |


通訊
感測
功能
能源
資料收集
Website


#
| Task           | Time required | Assigned to   | Current Status | Finished | 
|----------------|---------------|---------------|----------------|-----------|
| Calendar Cache | > 5 hours  |  | in progress | - [x] ok?
| Object Cache   | > 5 hours  |  | in progress | [x] item1<br/>[ ] item2
| Object Cache   | > 5 hours  |  | in progress | <ul><li>- [x] item1</li><li>- [ ] item2</li></ul>
| Object Cache   | > 5 hours  |  | in progress | <ul><li>[ ] item1</li>


- [x] works
- [x] works too




# 接線圖
## Overall Wiring diagram
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_3.jpg)

## PIR Motion Sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_1.jpg)

## Photoresistor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_2.jpg)

## ESP8266
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_4.jpg)

## Soil Humidity & temperature Sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_6.jpg)

## DHT sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_7.jpg)




  
