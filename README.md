# Room Condition Checker
IoT Project by: Reegan Anto.J

Webdev and Deployment: Dinesh.J


## Introduction:
This is an IoT based electrical circuit using Arduino UNO board which reads data from DHT11 sensor and photoresistor in order to obtain temperature, humidity and photoresistor and I use the ESP8266EX wifi module to update the data to my ThingSpeak channel whose API key is then read and visualized by the frontend deployed on vercel.


## Circuit diagram
![RoomCondition-Circuit](https://github.com/ReeganAnto-J/Arduino-RoomCondition-Checker/assets/140252295/e5d7ceff-80f5-42bd-93dd-a6718f2ae138)

## Deployed site
Deployed Site: https://arduino-room-condition-checker.vercel.app/

ThingSpeak: https://thingspeak.com/channels/2566898

![Room_Condition_Deployed](https://github.com/ReeganAnto-J/Arduino-RoomCondition-Checker/assets/140252295/6dccd1e7-c767-45ec-8a01-92cb47c7db72)


## IoT Details:
The Arduino files can be accessed in the arduino branch.

### Components:
  - Arduino UNO board
  - DHT11 Sensor
  - Light Dependent Resistor
  - ESP8266EX Wifi Module

Youtube Explanation: (https://youtu.be/VlIczb6ad0c "Room Condition Checker")

#### WEB DETAILS:

## FRAMEWORK: 
    --REACT js
    A React application to monitor room conditions including temperature, humidity, and light intensity using data fetched from a ThingSpeak channel.
## Introduction:

This project is a room condition checker that fetches data from the ThingSpeak API and displays it in a web application using REACT js. The application shows real-time data for temperature, humidity, and light intensity.

##  Technology Used:
  --React    - Used for building user interfaces.
  --chart.js  -Used for data visualization.
  --Axios    - Used this  package to fetch the data  in JSON format using API.

## Fetching Data with Axios
    API :   https://thingspeak.com/channels/2566898/feeds.json
    Process: The application fetches data from the ThingSpeak API. This API eturns a JSON object containing the latest data for temperature, humidity, and light intensity.
    
## Displaying Fetched Data

The application fetches temperature, humidity, and light intensity data from the ThingSpeak API using Axios. This data is then displayed on a line chart using the Chart.js library. Each data point is mapped to its corresponding timestamp and visualized on the chart. The chart has multiple Y-axes to represent each parameter clearly. This provides a real-time visualization of room conditions.
## Components in `src`

The `src` directory contains the core components of the application, each serving a specific purpose in rendering the dashboard and fetching data. Here's an overview of the key components:
    
    # `App.js`
    
    The main component that serves as the entry point of the application. It initializes the application and renders the `SensorDashboard` component.
    
    # `SensorDashboard.js`
    
    This component is responsible for fetching data from the ThingSpeak API and displaying it. It uses Axios to make HTTP requests and handles the data retrieval process. The fetched data is passed to the `ChartComponent` for visualization.
    
    # `Chart.js`
    
    This component handles the rendering of the chart using `react-chartjs-2`. It takes the fetched data and displays it in a line chart, showing temperature, humidity, and light intensity over time.
    
    # `index.js`
    
    This file is the main entry point for the React application. It uses `ReactDOM.createRoot` to render the `App` component into the `root` DOM node. It also includes any necessary imports and configurations for the application.
    
    # `index.css`
    
    The main CSS file for the application. It includes global styles and ensures consistent styling across all components.



## Dependencies

The project relies on several npm packages listed in the `package.json` file:

- **axios**: Used to make HTTP requests to fetch data from the ThingSpeak API.
- **react**: A JavaScript library for building user interfaces, providing the foundation for the application.
- **react-dom**: Serves as the entry point to the DOM and server renderers for React, enabling the app to run in the browser.
- **react-scripts**: Includes scripts and configuration used by Create React App, streamlining the setup and development process.
- **chart.js**: A flexible and simple JavaScript charting library used for creating the line charts to display the fetched data.
- **react-chartjs-2**: A React wrapper for Chart.js, allowing seamless integration of Chart.js into React components.

These dependencies are crucial for the functionality of the application, enabling efficient data fetching, UI rendering, and data visualization.

### Deployment
PLatform : Vercel
About:  This project is deployed using Vercel, which provides a seamless way to deploy and manage React applications. Vercel's continuous deployment allows for automatic updates every time changes are pushed to the repository.
Deployment Link :https://arduino-room-condition-checker.vercel.app/




  

Feel free to apply this in any of your own Arduino projects and React Applications.
