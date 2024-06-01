#ifndef DATAHANDLER
#define DATAHANDLER

// To initialize the I2C LCD panel
void initLcd();

// To read light intensity from photoresistor
void photoRead(byte photoresistor_pin);

// To convert temperature from C to F
float tempInF();

// To update temperature, humidity and light intensity
void updateValues();

// To write the values to the I2C LCD Panel
void writeToLCD();

// To call the ESP module to write values to the channel
void callESP();

#endif
