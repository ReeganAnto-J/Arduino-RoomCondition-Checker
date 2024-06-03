# Arduino branch
- This branch holds all the necessary files required to work the arduino device.
- All the .h files are the header files which contains the function declaration for all necessary functions.
- The other cpp and ino files will be explained below.


### RoomConditionMain.ino
- This is the main file of this project, this file contains the setup and root function to run the project.
- This function sets up the LCD display and initializes the ESP8266EX module.
- This function periodically updates the display and the ThingSpeak server.


### DataHandler.ino 
- This file is used to read data from all the external peripherals connected to the arduino device.
- The DHT11 is used to read the room's humidity and temperature while the LDR reads the light intensity.
- This is also responsible in calling the esp.ino's updateESP function which uploads data to the ThingSpeak channel using AT calls.


### esp.ino
- This file contains functions which sets up and uploads data from the ESP8266EX Wifi module.
- The setup function connects the module to the nearby wifi device using its SSID and password.
- The data will be transwerred to my ThingSpeak channel using AT calls which writes data by referring to the write API key.


### Other CPP files
- These are libraries provided by quad store from whom I bought all the hardwares used in the project.
- I used the libraries provided by them in order to prevent any compatability issues.
