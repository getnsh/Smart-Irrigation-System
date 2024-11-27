#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME "Smart Irrigation System"
char auth[] = "";

// Enter your WIFI SSID and password
char ssid[] = "";
char password[] = "";

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Define soil moisture sensor pin
#define SOIL_MOISTURE_PIN 34 // Analog pin for soil moisture sensor

// Define DHT sensor pin and type
#define DHT_PIN 21       // Change to the desired GPIO pin
#define DHT_TYPE DHT11   // Specify DHT11 as the sensor type

DHT dht(DHT_PIN, DHT_TYPE); // Initialize the DHT sensor
BlynkTimer timer;

// Function to send soil moisture data
void sendSoilMoistureData() {
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  int soilMoisturePercentage = map(soilMoistureValue, 0, 4095, 100, 0);

  // Print soil moisture data on Serial Monitor
  Serial.print("Soil Moisture Value (Raw): ");
  Serial.println(soilMoistureValue);
  Serial.print("Soil Moisture Percentage: ");
  Serial.println(soilMoisturePercentage);

  // Send data to Blynk app
  Blynk.virtualWrite(V0, soilMoisturePercentage);
}

// Function to send temperature and humidity data
void sendDHTData() {
  float temperature = dht.readTemperature(); // Read temperature (Celsius)
  float humidity = dht.readHumidity();       // Read humidity (%)

  // Check if data is valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity data on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Send data to Blynk app
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
}

void setup() {
  Serial.begin(9600); // Start Serial Monitor

  // Initialize Wi-Fi and Blynk
  Blynk.begin(auth, ssid, password);

  // Initialize DHT sensor
  dht.begin();

  // Set up timers
  timer.setInterval(2000L, sendSoilMoistureData); // Send soil moisture data every 2 seconds
  timer.setInterval(5000L, sendDHTData);         // Send temperature and humidity every 5 seconds
}

void loop() {
  Blynk.run(); // Run Blynk
  timer.run(); // Run timer
}
