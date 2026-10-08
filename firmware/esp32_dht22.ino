/*
  ESP32 + DHT22 + Firebase Realtime Database
  Project: ESP32 Environment Monitor

  Hardware:
  - ESP32 DevKit V1
  - DHT22
  - DHT22 DATA -> GPIO 4

  IMPORTANT:
  Replace the placeholder values below with your own credentials
  when compiling locally.

  NEVER publish your Wi-Fi password or Firebase account password.
*/

#include <WiFi.h>
#include <DHT.h>
#include <FirebaseClient.h>

// =====================================================
// Wi-Fi Configuration
// =====================================================

#define WIFI_SSID     "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// =====================================================
// Firebase Configuration
// =====================================================

#define API_KEY       "YOUR_FIREBASE_WEB_API_KEY"
#define USER_EMAIL    "YOUR_FIREBASE_AUTH_EMAIL"
#define USER_PASSWORD "YOUR_FIREBASE_AUTH_PASSWORD"

#define DATABASE_URL \
  "https://temp-sensor-1ed8d-default-rtdb.asia-southeast1.firebasedatabase.app"

// =====================================================
// DHT22 Configuration
// =====================================================

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// =====================================================
// Firebase Objects
// =====================================================

UserAuth user_auth(API_KEY, USER_EMAIL, USER_PASSWORD);

FirebaseApp app;

WiFiClientSecure ssl_client;
AsyncClient aClient(ssl_client);

RealtimeDatabase Database;

// =====================================================
// Timing
// =====================================================

unsigned long lastUpload = 0;

const unsigned long uploadInterval = 5000;

// =====================================================
// Wi-Fi Connection
// =====================================================

void connectWiFi()
{
  Serial.print("Connecting to Wi-Fi");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("Wi-Fi connected");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// =====================================================
// Setup
// =====================================================

void setup()
{
  Serial.begin(9600);

  delay(1000);

  Serial.println();
  Serial.println("=================================");
  Serial.println("ESP32 DHT22 Firebase Monitor");
  Serial.println("=================================");

  // Start DHT22
  dht.begin();

  // Connect ESP32 to Wi-Fi
  connectWiFi();

  // TLS configuration
  // Authentication and database rules are still handled by Firebase.
  ssl_client.setInsecure();

  Serial.println("Initializing Firebase...");

  // Initialize Firebase
  initializeApp(aClient, app, getAuth(user_auth));

  app.getApp<RealtimeDatabase>(Database);

  Database.url(DATABASE_URL);

  Serial.println("Firebase initialization requested.");
}

// =====================================================
// Main Loop
// =====================================================

void loop()
{
  // Allow Firebase background processes to run.
  app.loop();

  // Wait until Firebase is ready.
  if (!app.ready())
  {
    Serial.println("Firebase NOT READY");

    delay(1000);

    return;
  }

  // Upload every 5 seconds.
  if (millis() - lastUpload < uploadInterval)
    return;

  lastUpload = millis();

  // Read DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check sensor readings.
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT22 reading failed.");

    return;
  }

  // Display readings on Serial Monitor.
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // ===================================================
  // Firebase Upload
  // ===================================================

  Database.set<float>(
    aClient,
    "/sensor/temperature",
    temperature
  );

  Database.set<float>(
    aClient,
    "/sensor/humidity",
    humidity
  );

  Database.set<int>(
    aClient,
    "/sensor/timestamp",
    millis()
  );

  Serial.println("Sensor data sent to Firebase.");

  Serial.println("---------------------------------");
}
