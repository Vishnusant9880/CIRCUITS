# SOLAR POWER MONITERING SYSTEM
To create a IoT based Solar monitoring system


**Objectives : -**
•	**Real-Time Monitoring:**  Objective: Provide real-time visibility into the performance of solar panels and the overall solar power system.  Benefits: Enables immediate detection of issues, optimization of energy production, and timely decision-making.
•	**Fault Detection and Diagnostics:**  Objective: Detect and diagnose faults or anomalies in the solar power system.   Benefits: Reduces downtime by allowing prompt identification and resolution of issues, improving overall system reliability.
•	Dust or Soiling Sensors: Optical sensors that can detect the amount of dust or soiling on the surface of the solar panels.
•	Remote Monitoring and Control:
**Remote Access**: Enable remote monitoring and control of solar energy systems, allowing operators to manage and optimize performance from anywhere.    
•	Alerts and Notifications: Provide automated alerts and notifications for system issues or deviations from expected performance, facilitating timely response.
•	User Interface: Provide a user-friendly interface for system operators and end-users to monitor and understand the performance of the solar energy system.


**FEATURES:-**

•	The ESP32 typically comes with a dual-core processor, allowing for efficient multitasking and performance.

•	Integrated Wi-Fi module enables wireless communication, making it suitable for IoT (Internet of Things) applications.

•	The ESP32 is designed to operate with low power consumption, making it suitable for battery-powered devices and applications where power efficiency is crucial.

•	Supports various Wi-Fi protocols (802.11 b/g/n) for wireless communication and Bluetooth protocols for short-range communication.

•	Specifies the range of voltages that the sensor can accurately measure. It's important to choose a module that suits the voltage levels you expect in your application.

•	Specifies the range of current levels that the sensor can accurately measure. It's important to choose a sensor that suits the current levels expected in your application.

•	Servo motors are known for their precise positional control. They can maintain and control their position accurately.

•	Specifies the range of particle sizes that the sensor can detect. Dust sensors may be optimized for specific particle size ranges, such as PM1, PM2.5, or PM10.

•	Indicates how closely the sensor's measurements correspond to the actual particle concentrations. Accuracy is often given as a percentage.

•	The primary feature of a photoresistor is its ability to change resistance in response to changes in illumination. As light intensity increases, the resistance decreases, and vice versa.

•	The primary feature of an LDR is its ability to change resistance based on the intensity of incident light. As the light intensity increases, the resistance decreases, and vice versa.

•	Relays have different contact configurations, including normally open (NO), normally closed (NC), and changeover (CO) or double-throw contacts. These configurations determine how the relay behaves in its normal state and when activated.

MIND MAP:
![WhatsApp Image 2023-11-17 at 11 19 57 AM](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/8336300a-7651-4449-a286-6b2301419202)

FLOW CHART:

![WhatsApp Image 2023-11-17 at 11 00 43 AM](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/90fe5aa5-2221-45da-bfa2-26e2e938e9c9)

BLOCK DIAGRAM:

![BLOCK](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/2f0eae34-f9e9-4ff3-91c2-2d15abab4947)

ALGORITHM:

![ALGO](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/55b5c170-1d56-4c92-ac05-8305869ab53a)

CODE:

#include "BlynkEdgent.h" 
#include <Deneyap_Servo.h> 
int ldr1 = A0;
int ldr2 = A1;
int pos; 
int voltage1 = 12;
int voltage2 = 11; 
Servo myservo;

void servo_ldr() 
{ 
int ldr1_read = analogRead(ldr1);
int ldr2_read = analogRead(ldr2);
Serial.print("light1 = "); 
Serial.println(ldr1_read);
Serial.print("light2 = ");
Serial.println(ldr2_read);
int map1 = map(ldr1_read,0,8191,52,0);
int map2 = map(ldr2_read,0,8191,53,105);
if(ldr1_read>=ldr2_read)
  { myservo.write(map1); 
    delay(30);
  } 
  else 
  { 
    myservo.write(map2); delay(30); 
  } 
  
void setup()
{ WiFi.begin(ssid,pass);
pinMode(ldr1,INPUT);
pinMode(ldr2,INPUT);
pinMode(voltage1,INPUT);
pinMode(voltage2,INPUT);
Serial.begin(9600);
myservo.attach(9);
delay(100);

BlynkEdgent.begin(); }

void loop() 
{ 
for(i=0;i<50;i++)
  { servo_ldr(); 
  float volt1 = analogRead(voltage1);

  float volt2 = analogRead(voltage2);

  float vout_solar = (volt1/15500)*25;
  float vout_battery = (volt2/15500)*25;

  Serial.print("solar voltage = "); 
  
  Serial.println(vout_solar); Serial.print("battery voltage = "); 
  Serial.println(vout_battery);

  float map_volt1 = map(vout_battery,3.3,4.2,0,100);

  Blynk.virtualWrite(V0, vout_solar); Blynk.virtualWrite(V1,vout_battery); Blynk.virtualWrite(V2, mapping);

  //Blynk.virtualWrite(V4, millis() / 1000); delay(2000);
  
  BlynkEdgent.run(); 
  }
  }
  
VIDEO DEMO:

https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/4e09972a-02fc-4d6c-ab85-37347cafced2

OUTPUTS:

![OUTPUT3](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/dd28238d-0443-436f-9b64-61865a6c6cc5)
![OUTPUT2](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/4a2a876e-8d3d-47a3-b9d0-22af71ad4629)
![OUTPUT1](https://github.com/Vishnusant9880/CIRCUITS/assets/109665724/eed0c81b-256f-4e89-a7d3-982853e0c95c)

