 /*!
  * @file  GetWifiIp.ino
  * @brief Gets the IP address to connect to wifi.
  * @n step: Set the name and password you want to connect to wifi,to run the program.
  * @n       Then observe the color of the RGB light, changing from red to green to blue.
  * @n note: The red is that the WiFi is not connected, the green is that the WiFi is connecting, and the blue is that the WiFi is connected successfully.
  *
  * @n The experimental phenomenon is to print the IP address connected to wifi to the serial port.
  *
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version     V0.2
  * @date        2019-07-05
  * @get         from https://www.dfrobot.com
  * @url   */
#include "DFRobot_OBLOQ.h"

uint8_t * WIFI_NAME = "hitest";
uint8_t * WIFI_PWD  = "12345678";

DFRobot_OBLOQ OBLOQ;

void setup() {
  Serial.begin(9600);
  /* Initialize i2c */
  while(!OBLOQ.begin()) {
    Serial.println("I2c Device Number ERROR");
    delay(1000);
  }
  Serial.println("I2c Connect SUCCESS");
  
  /* WiFi initialization ,Set the wifi password and connect to the wifi 
   *      WIFI_NAME is wifi name
   *      WIFI_PWD  is wifi password
   */
  while(OBLOQ.wifiBegin(WIFI_NAME, WIFI_PWD) != 0) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("Wifi Connect SUCCESS");
  
/*
  while(!OBLOQ.disConnectWifi()) {                // disconnect Wifi
    Serial.print(".");
  }
  Serial.println("Wifi disconnected successfully! ");
*/
}

void loop() {
 /* If the wifi is disconnected, reconnect the wifi. 
  *     WIFI_NO_CON       is      wifi is disconnected
  *     WIFI_RUN_CON      is      Wifi is connecting 
  *     WIFI_SUCCESS_CON  is      The wifi connection was successful 
  */
  if(WIFI_NO_CON == OBLOQ.getWifiState()){
    OBLOQ.reConnectWifi();                       // Reconnect the wifi 
    Serial.println("Reconnect wifi successfully");
    delay(100);
  }
  OBLOQ.loop();                                  // Cyclic read state 
  Serial.print("The Wifi Ip is ");
  Serial.println(OBLOQ.getWifiIp());             // Get the wifi ip address

  delay(2000);
}