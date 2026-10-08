# ESP32 + DHT22 IoT Environment Monitor

An IoT-based temperature and humidity monitoring system using ESP32, DHT22, Firebase Realtime Database, and a responsive web dashboard.

The system collects environmental data from the DHT22 sensor, sends it through ESP32 over Wi-Fi to Firebase, and displays the data on a web dashboard in real time.

## Live Demo

https://temperature-sensor-e1f27.web.app/

## Project Architecture

![System Architecture](images/architecture.png)

## Hardware

- ESP32 DevKit V1
- DHT22 Temperature & Humidity Sensor
- Jumper wires
- USB power supply

### Hardware Setup

![Hardware Setup](images/hardware.jpg)

## Technology Stack

### Embedded / IoT

- ESP32
- DHT22
- Embedded C/C++
- Arduino IDE
- Wi-Fi

### Cloud

- Firebase Authentication
- Firebase Realtime Database
- Firebase Hosting

### Web

- HTML
- CSS
- JavaScript
- Chart.js

## Data Flow

DHT22 Sensor
↓
ESP32
↓
Wi-Fi
↓
Firebase Realtime Database
↓
Web Dashboard

## Working Principle

1. The DHT22 measures temperature and relative humidity.
2. ESP32 reads the sensor values.
3. ESP32 connects to the internet through Wi-Fi.
4. Sensor data is transmitted to Firebase Realtime Database.
5. Firebase stores the incoming measurements.
6. The web dashboard retrieves the data.
7. Temperature and humidity are displayed in real time.
8. Historical measurements can be visualized using a graph.

## Web Dashboard

The dashboard provides:

- Real-time temperature monitoring
- Real-time humidity monitoring
- Historical data visualization
- Firebase connection status
- Sensor status
- Last updated information
- Responsive interface

![Web Dashboard](images/dashboard.png)

## Firebase Database

Firebase Realtime Database is used as the cloud backend for storing sensor measurements.

![Firebase Database](images/firebase.png)

## Firebase Authentication

Firebase Authentication is used to control access to the monitoring dashboard and database.

The Realtime Database is configured to allow authenticated users to read and write sensor data.

## Project Components

| Component | Purpose |
|---|---|
| DHT22 | Measures temperature and humidity |
| ESP32 | Reads sensor data and provides Wi-Fi connectivity |
| Firebase RTDB | Stores sensor measurements |
| Firebase Authentication | Provides user authentication |
| Web Dashboard | Displays sensor data |
| Chart.js | Visualizes historical measurements |

## Testing

The system was tested for:

- DHT22 sensor readings
- ESP32 Wi-Fi connectivity
- Firebase connectivity
- Database data updates
- Web dashboard updates
- Historical graph visualization
- Authentication

The DHT22 successfully provided temperature and humidity measurements, while the ESP32 transmitted the data to Firebase for visualization through the web dashboard.

## Deployment

The web dashboard is deployed using Firebase Hosting.

Live deployment:

https://temperature-sensor-e1f27.web.app/

## Project Outcome

The project demonstrates an end-to-end IoT monitoring pipeline:

Physical Sensor → Embedded System → Internet → Cloud Database → Web Application

It combines embedded systems, IoT communication, cloud services, authentication, database management, and web development into a single working system.

## Future Improvements

- Add multiple sensors
- Add automatic alerts for abnormal temperature/humidity
- Add mobile-friendly notifications
- Add data export functionality
- Add more advanced analytics
- Add long-term environmental data storage
- Add OTA firmware updates
- Add additional IoT sensors

## Author

Nalinkumar K

## License

This project is intended for educational and learning purposes.
