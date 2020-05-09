 /*!
  * @file  GetVersion.ino
  * @brief Get the software version number.
  * @n step: To run the program.
  *
  * @n The experimental phenomenon is to print the software version number to the serial port.
  *
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version     V0.2
  * @date        2019-07-05
  * @get         from https://www.dfrobot.com
  * @url   */
#include "DFRobot_OBLOQ.h"

DFRobot_OBLOQ OBLOQ;

void setup() {

  Serial.begin(9600);
 
  /* Initialize i2c */
  while(!OBLOQ.begin()) {
    Serial.println("I2c Device Number ERROR");
    delay(100);
  }
  Serial.println("I2c Connect SUCCESS");

  Serial.print("The Version is ");
  Serial.println(OBLOQ.getVersion());            // Get the hardware version number.
}

void loop() {
  delay(1000);
}