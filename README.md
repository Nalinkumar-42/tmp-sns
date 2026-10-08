# ESP32 + DHT22 IoT Environment Monitor

An IoT-based temperature and humidity monitoring system using ESP32, DHT22, Firebase Realtime Database, Firebase Authentication, and a responsive web dashboard.

The system collects environmental data from the DHT22 sensor, sends it through the ESP32 over Wi-Fi to Firebase, and displays the data on a password-protected web dashboard.

---

## Live Demo

https://temp-sensor-1ed8d.web.app/

---

## Project Architecture

![System Architecture](images/architecture.png)

### Data Flow

DHT22 Sensor
↓
ESP32
↓ Wi-Fi
Firebase Realtime Database
↓
Web Dashboard

---

## Hardware

- ESP32 DevKit V1
- DHT22 Temperature & Humidity Sensor
- Jumper wires
- USB power supply

### DHT22 Connections

| DHT22 Pin | ESP32 |
|---|---|
| VCC | 3.3V |
| DATA | GPIO 4 |
| GND | GND |

### Hardware Setup

![Hardware Setup](images/hardware.jpg)

---

## Technology Stack

### Embedded / IoT

- ESP32
- DHT22
- Embedded C/C++
- Arduino IDE
- Wi-Fi

### Cloud

- Firebase Realtime Database
- Firebase Authentication
- Firebase Hosting

### Web

- HTML
- CSS
- JavaScript
- Chart.js

---

## Repository Structure

The repository is organized as follows:

- `firmware/` — ESP32 firmware
  - `esp32_dht22.ino` — DHT22 sensor and Firebase code
- `images/` — Project screenshots and architecture diagram
  - `architecture.png`
  - `hardware.jpg`
  - `dashboard.png`
  - `firebase.png`
- `public/` — Web dashboard
  - `index.html`
- `.firebaserc` — Firebase project configuration
- `.gitignore` — Git ignored files
- `firebase.json` — Firebase Hosting configuration
- `README.md` — Project documentation

---

## ESP32 Firmware

The ESP32 firmware is located in:

`firmware/esp32_dht22.ino`

The firmware performs the following operations:

1. Connects the ESP32 to Wi-Fi.
2. Initializes the DHT22 sensor.
3. Connects to Firebase.
4. Reads temperature and humidity.
5. Uploads sensor readings to Firebase Realtime Database.
6. Updates the database periodically.

### Firmware Configuration

Before uploading the firmware, configure the following values locally:

    #define WIFI_SSID "YOUR_WIFI_SSID"
    #define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

    #define API_KEY "YOUR_FIREBASE_WEB_API_KEY"

    #define USER_EMAIL "YOUR_FIREBASE_AUTH_EMAIL"
    #define USER_PASSWORD "YOUR_FIREBASE_AUTH_PASSWORD"

The actual Wi-Fi and Firebase passwords should not be published in the repository.

---

## Firebase Realtime Database

Firebase Realtime Database is used as the cloud backend for storing sensor measurements.

The database structure is:

    sensor/
    ├── temperature
    ├── humidity
    └── timestamp

![Firebase Database](images/firebase.png)

---

## Firebase Authentication

The web dashboard uses Firebase Authentication to restrict access.

Users must provide valid Firebase authentication credentials before accessing the monitoring dashboard.

The actual password is intentionally not published in this repository.

---

## Web Dashboard

The dashboard provides:

- Real-time temperature monitoring
- Real-time humidity monitoring
- Historical data visualization
- Firebase connection status
- Sensor status
- Last updated information
- Responsive web interface
- Password-protected access

![Web Dashboard](images/dashboard.png)

---

## Working Principle

1. The DHT22 measures temperature and relative humidity.
2. The ESP32 reads the sensor values through GPIO 4.
3. The ESP32 connects to the internet through Wi-Fi.
4. Sensor measurements are transmitted to Firebase Realtime Database.
5. Firebase stores the incoming measurements.
6. Firebase Authentication verifies the dashboard user.
7. After successful authentication, the web dashboard retrieves the sensor data.
8. Temperature and humidity are displayed on the dashboard.
9. Historical measurements are visualized using Chart.js.

---

## Project Components

| Component | Purpose |
|---|---|
| DHT22 | Measures temperature and humidity |
| ESP32 | Reads sensor data and provides Wi-Fi connectivity |
| Firebase Realtime Database | Stores sensor measurements |
| Firebase Authentication | Authenticates dashboard users |
| Firebase Hosting | Hosts the web dashboard |
| Web Dashboard | Displays sensor data |
| Chart.js | Visualizes historical measurements |

---

## Testing

The system was tested for:

- DHT22 temperature readings
- DHT22 humidity readings
- ESP32 Wi-Fi connectivity
- Firebase connectivity
- Firebase database updates
- Firebase authentication
- Web dashboard updates
- Historical graph visualization
- Dashboard sign-out functionality

The DHT22 successfully provides temperature and humidity measurements, while the ESP32 transmits the data to Firebase for visualization through the authenticated web dashboard.

---

## Deployment

The web dashboard is deployed using Firebase Hosting.

### Live Deployment

https://temp-sensor-1ed8d.web.app/

---

## Project Outcome

The project demonstrates an end-to-end IoT monitoring pipeline:

    Physical Sensor
          ↓
    Embedded System
          ↓
    Internet
          ↓
    Cloud Database
          ↓
    Web Application

The project combines:

- Embedded systems
- Sensor interfacing
- Wi-Fi communication
- IoT architecture
- Cloud database integration
- Authentication
- Web development
- Data visualization

---

## Future Improvements

- Add multiple environmental sensors
- Add automatic alerts for abnormal temperature and humidity
- Add mobile notifications
- Add data export functionality
- Add advanced data analytics
- Add long-term environmental data storage
- Add OTA firmware updates
- Add additional IoT sensors
- Add improved user and access management

---

## Author

NalinKumar K

---

## License

This project is intended for educational and learning purposes.
