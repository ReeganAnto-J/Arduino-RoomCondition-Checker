/*
 * This is a part of:
 * Simple Room Condition Monitor
 * 
 * Built by Reegan Anto.J 
 * Built on: 01/06/2024
 * 
 * This file contains all the functions
 * which stores and updates the necessary conditions
 * 
 * The conditions are namely:
 *    --Light Intensity
 *    --Temperature
 *    --Humidity
 *    
 * Every upcoming functions are explained within
 * comment lines above the function
 */

// To initialize baud and pin values
const int serialBaud = 9600;
const byte photopin = A0;
byte dhtpin = 13;
SimpleDHT11 dht11;
LiquidCrystal_I2C lcd(0x27,16,2);

// To declare output values
float lightValue = 0;
byte temperature = 0;
byte humidity = 0;


// To read the value from the photoresistor
void photoRead(byte photoresistor_pin){
  pinMode(photoresistor_pin, INPUT);
  lightValue = (float)analogRead(photoresistor_pin)/1024*100;
}

// To convert temperature from C to F
float tempInF(){
  return (float)(temperature * (9.0/5.0))+32.0;
}

// All sensor inputs are received here
void updateValues(){
  // To update light value
  // Using Photoresistor
  photoRead(photopin);
  Serial.print("Light Intensity: "); Serial.print(lightValue); Serial.println(" % ");

  // To update temperature and humidity
  // Using DHT11
  byte t, h;
  if (dht11.read(dhtpin, &t, &h, NULL))
    Serial.print("Read DHT11 failed.");
  else{
    temperature = t;
    humidity = h;
    Serial.print("Sample OK: ");
    Serial.print(temperature); Serial.print(" *C, "); 
    Serial.print(tempInF()); Serial.print(" *F, "); 
    Serial.print((int)humidity); Serial.println(" %");
  }
}

// Writes all the values to the LCD Display
void writeToLCD(){
  String line1 = "Light Intensity:";
  String line2 = (String)lightValue + " % ";
  for(char i : line1) lcd.print(i);
  lcd.setCursor(0, 1);
  for(char i : line2) lcd.print(i);
  delay(5000);
  lcd.clear();
  line1 = "Temperature:";
  line2 = (String)temperature + " *C  " + tempInF() + " *F ";
  for(char i : line1) lcd.print(i);
  lcd.setCursor(0, 1);
  for(char i : line2) lcd.print(i);
  delay(5000);
  lcd.clear();
  line1 = "Humidity:";
  line2 = (String)humidity + " % ";
  for(char i : line1) lcd.print(i);
  lcd.setCursor(0, 1);
  for(char i : line2) lcd.print(i);
  delay(5000);
  lcd.clear();
}

// Initializes LCD display and Serial Monitor
void initLcd(){
  Serial.begin(serialBaud);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  String s1 = "LCD Display is";
  String s2 = "Working fine";
  for(byte j = 0; j<3; j++){
    for(char i : s1) lcd.print(i);
    lcd.setCursor(0, 1);
    for(char i : s2) lcd.print(i);
    delay(700);
    lcd.clear();
    delay(300);
  }
  delay(1000);
}

// Function to pass the necessary parameters to ESP
void updateEsp(int tem, int hum, float light);
void callESP(){
  updateEsp((int)temperature, (int)humidity, (float)lightValue);
}
