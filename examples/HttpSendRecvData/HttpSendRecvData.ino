 /*!
  * @file  HttpSendRecvData.ino
  * @brief HTTP post and get are used for communication.
  * @n step: Set the name and password you want to connect to wifi,to run the program.
  * @n       Then set the HTTP IP address and port number.
  * @n note: Must have the correct HTTP url (or IP address).
  *
  * @n The experimental phenomenon is that the HTTP server receives the data we send.
  *
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version     V0.2
  * @date        2019-07-05
  * @get         from https://www.dfrobot.com
  * @url   */
#include "DFRobot_OBLOQ.h"

uint8_t * WIFI_NAME    = "hitest";
uint8_t * WIFI_PWD     = "12345678";
uint8_t * HTTP_ADDRESS = "192.168.1.102";
uint8_t * HTTP_PORT    = "8080";

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
  
  /* set the port and address for http 
   *     HTTP_ADDRESS is http address
   *     HTTP_PORT    is http port
   */
  while(!OBLOQ.httpBegin(HTTP_ADDRESS, HTTP_PORT)) {
    Serial.println("Parameter is empty!");
    delay(1000);
  }
}

void loop() {

 /* If the wifi is disconnected, reconnect the wifi. 
  *     WIFI_NO_CON       is      wifi is disconnected
  *     WIFI_RUN_CON      is      Wifi is connecting 
  *     WIFI_SUCCESS_CON  is      The wifi connection was successful 
  */
  if(WIFI_NO_CON == OBLOQ.getWifiState())
    OBLOQ.reConnectWifi();                       // Reconnect the wifi 

  OBLOQ.loop();                                  // Cyclic read state 

  /* Http sends data as Get */
  String GetData =OBLOQ.httpGet("input?id=1&val=hello");
  Serial.println(GetData);
  delay(200);
  
  /* Http sends data as Post */
  String PostData = OBLOQ.httpPost("input?id=1&val=22", "{\"data\":\"123456789\"}|\r");
  Serial.println(PostData);
}