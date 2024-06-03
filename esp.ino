/*
 * Script taken from Makers Group Youtube Channel
 * https://www.youtube.com/watch?v=764bRMvGZR4
 * 
 * This script is used to write data to my thingspeak
 * page using the write API key
 */

#include <SoftwareSerial.h>
#define RX 2 // TX of esp8266 in connected with Arduino pin 2
#define TX 3 // RX of esp8266 in connected with Arduino pin 3

String WIFI_SSID = "";// WIFI NAME
String WIFI_PASS = ""; // WIFI PASSWORD
String API = "";// Write API KEY
String HOST = "api.thingspeak.com";
String PORT = "80";
int countTrueCommand;
int countTimeCommand; 
boolean found = false;   

SoftwareSerial esp8266(RX,TX); 

void espSetup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ WIFI_SSID +"\",\""+ WIFI_PASS +"\"",20,"OK");
}

void updateEsp(int tem, int hum, float light) {
 //int tem=random(20,30); // int tem= analogRead(A0)
 //int hum=random(70,80); //int tem= digitalRead(11)
 //int light=random(0,100); //int tem= AnalogRead(A0)
 String getData="GET /update?api_key="+ API+"&field1="+tem+"&field2="+hum +"&field3="+light;
 sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);
 //delay(10000);
 countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
}

void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
    countTimeCommand++;
  } 
  if(found == true)
  {
    Serial.println("OK");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  } 
  found = false;
 }