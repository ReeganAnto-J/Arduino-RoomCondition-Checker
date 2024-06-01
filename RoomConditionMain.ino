/*
 * Simple Room Condition Monitor
 * 
 * Built by: Reegan Anto.J
 * Built on: 01/06/2024
 * Artificial Intelligence and Data Science
 * Adhi College of Engineering and Technology
 * 
 * Thingspeak link: https://thingspeak.com/channels/2566898
 * 
 * Components:
 *    --Arduino Uno
 *    --ESP8266EX (Connect RX of ESP on pin 3 of UNO and TX of ESP on pin 2 of UNO)
 *    --DHT11 (Pin 13)
 *    --Photoresistor (Pin A0)
 *    --I2C display
 * 
 * This file is the main file of this project
 * This file includes all necessary header files which 
 * gives it access to use functions offered by other scripts
 * 
 * The setup function is used to initialize the LCD
 * 
 * The loop function periodically updates the the LCD 
 * and updates the thingspeak channel evey 10 minutes
 */

#include "SimpleDHT.h"
#include "LiquidCrystal_I2C.h"
#include "DataHandler.h"

void espSetup();

unsigned long timerValue;
unsigned long timerReset;
unsigned long uploadDelayTime = 60000;

// Sets up serial monitor
void setup() {
  espSetup();
  initLcd();
  updateValues();
  callESP();
  writeToLCD();
  delay(1000);
  timerValue = millis();
  timerReset = timerValue+uploadDelayTime;
}

// Updates all values periodically
void loop() {
  timerValue = millis();
  updateValues();
  writeToLCD();
  delay(1000);
  
  // Uploads values to the server every 10 minutes
  if(timerValue > timerReset){
    callESP();
    timerReset = timerValue+uploadDelayTime;
  }
}
