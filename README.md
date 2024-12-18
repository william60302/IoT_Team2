# 2024 IIoT_Smart Micro-Greenhouse
"Make our life better, Make our city greener."                                                     
"Planting a little green is planting a little peace—let the leaves breathe life into your busy soul."

## Team Member (Job Allocation)
- M11351015 Larry 李國楨 (Software,Website)
- M11251001 Cindy 張芊凡 (Software,PPT,Onenote)
- M11351010 Melody 陳玫寧 (Hardware,Onenote,Demo Video)
- M11351017 William 陳彥齊 (Hardware,GitHub)
  
## Project Description
Measure various environmental data more preciously and use the Internet of Things (IoT) to transmit data, achieving real-time monitoring of plant growth. Automatically control the whole greenhouse system to adjust the irrigation levels, light exposure, and temperature and humidity to optimize growth conditions.

Our Website URL: https://m11351015.wixsite.com/my-site-2/projects     



## System Architecture
### Main Components:

- **Central Controller**:
  - Arduino UNO Board
  - Arduino Nano Board
    
- **Sensors and Actuators**:
  - LED Light Strip
  - OLED Display
  - Photoresistor
  - Soil Humidity Sensor
  - DHT Sensor(Air Temperature and Humidity)
  - PIR Motion Sensor
  - Water Pump

- **Communication**
  - ESP8266 (Wemos D1 R2 board)
  - Mini LoRa * 2 (With Antenna) 
 

### Functions
The following charts shows the functions we aimed to put into our project at the beginning. 
(The components with a checkmark in the "Finished" column are the ones we have completed in this product.)

**Monitor**
| Components | Functions | Finished |
| ------------- | ------------- | ------------- |
| Soil Humidity Sensor | Collecting Soil Humidity Data |<ul><li>- [x] </li>
| DHT Sensor | Collecting Air Temperature & Humidity Data |<ul><li>- [x] </li>
| PIR Sensor | Motion Detection |<ul><li>- [x] </li>
| Photoresistor | Measuring Brightness Change |<ul><li>- [x] </li>
| Camera | Real-time Monitoring |<ul><li>- [ ] </li>

**Actuation**
| Components | Functions | Finished |
| ------------- | ------------- | ------------- |
| Water Pump | Self Watering System |<ul><li>- [x] </li>
| LED Light Strip | Sensor Light & Sunlight Compensation |<ul><li>- [x] </li>
| OLED Display | Show Real-Time Data From Sensors |<ul><li>- [x] </li>
| Fan | Control Air Temperature & Humidity |<ul><li>- [ ] </li>
| Sunshade | Control Sunshine Duriation |<ul><li>- [ ] </li>

**Communication**
| Components | Functions | Finished |
| ------------- | ------------- | ------------- |
| LoRa | Transfer Data Between Device |<ul><li>- [x] </li>
| WiFi | Transfer Data From Device To Blynk  |<ul><li>- [x] </li>

**Power**
| Components | Functions | Finished |
| ------------- | ------------- | ------------- |
| Rechargeable Batteries | Power Storage |<ul><li>- [ ] </li>
| Small Solar Panel | Power Supply |<ul><li>- [ ] </li>

**Data Platform**
| Platform | Functions | Finished |
| ------------- | ------------- | ------------- |
| Blynk | Data Collection & Presention & Visualization  |<ul><li>- [x] </li>

### Data Transmit
The following diagram is the flow process of data transmit:
```mermaid
flowchart TB
  subgraph Flow Process
    direction TB
    subgraph Plant_Area
        direction LR
        Sensor_1 -- data --> Arduino_Uno
        Sensor_2 -- data --> Arduino_Uno
        Sensor_3 -- data --> Arduino_Uno
        Arduino_Uno -- Transmit --> Mini_LoRa_Uno
    end
    subgraph Home
        direction LR
        Mini_LoRa_Nano -- Receive --> Arduino_Nano -- Forward --> ESP8266
    end
    subgraph Cloud
        direction LR
        Blynk
    end
    subgraph Company
        direction LR
        Your_PC
    end
  end
  Plant_Area -- Through Mini_LoRa --> Home
  Home -- Through WiFi --> Cloud
  Cloud -- Through Internet --> Company
```

## Wiring Diagram
### Overall Diagram
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_3.jpg)

### PIR Motion Sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_1.jpg)

### Photoresistor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_2.jpg)

### Soil Humidity & temperature Sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_6.jpg)

### DHT sensor
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_7.jpg)

### ESP8266
![image](Arduino_WIRE_pic/LINE_ALBUM_接線圖_241216_4.jpg)

## Software
The following software are needed for this product, download first!
- Arduino IDE : https://www.arduino.cc/en/software (Sign In & Download)
- BLYNK : https://blynk.io/
- CH340 : https://sparks.gogo.co.nz/ch340.html?srsltid=AfmBOoo-oroGvox_G-0aVYyVQEFKZspoib5eJGVV9Epufqb9xcQvNUEe (If necessary)

## Arduino Library
These are the libraries you have to download first before yourun the code.
| Library | Used for | Library | Used for |
| ------------- | ------------- | ------------- | ------------- |
| FastLED.h | Control LED strip | DHT.h | Control DHT temperature and humidity sensor |
| BlynkSimpleEsp8266.h | Support for Blynk remote control functionality | Adafruit_Sensor.h | Adafruit sensor library |
| Adafruit_GFX.h | Support for OLED display graphics | Adafruit_SH1106.h | Control SH1106 OLED display |
| LoRa.h | LoRa communication functionality | SPI.h | SPI interface required for LoRa communication |
| Wire.h | Support for I2C communication | ESP8266WiFi.h | Control ESP8266 Wi-Fi functionality |
                            
## Future Work 
- Add other different kind of sensors.
- Analyze plant requirements with machine learning models.
- Improve and combine our product into other industries. (Example: Animal Husbandry...)
- Expand our device to extend more space to plant.







  
