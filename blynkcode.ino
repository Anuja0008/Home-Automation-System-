/* New Blynk app with Home Automation */

// Include the necessary library files
#define BLYNK_TEMPLATE_ID "TMPL6LwkN3qE_"
#define BLYNK_TEMPLATE_NAME "new"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define the relay pins
#define relay1 D0
#define relay2 D1
#define relay3 D2
#define relay4 D3
#define relay5 D4

int LED = D8;
int SENSOR_OUTPUT_PIN = D7;

#define BLYNK_AUTH_TOKEN "imNuKjgiHKVe_vYaXESMtkjRPOWcECcA" // Enter your Blynk auth token
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ABC123"; // Enter your WIFI name
char pass[] = "123456789"; // Enter your WIFI password

// Get the button values
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}


// Get the button values
BLYNK_WRITE(V1) {
  bool value2 = param.asInt(); // Use int instead of bool
  // Check these values and turn relay2 ON and OFF
  if (value2 == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

BLYNK_WRITE(V2) {
  bool value3 = param.asInt(); // Use int instead of bool
  // Check these values and turn relay3 ON and OFF
  if (value3 == 1) {
    digitalWrite(relay3, LOW);
  } else {
    digitalWrite(relay3, HIGH);
  }
}

BLYNK_WRITE(V3) {
  bool value4 = param.asInt(); // Use int instead of bool
  // Check these values and turn relay4 ON and OFF
  if (value4 == 1) {
    digitalWrite(relay4, LOW);
  } else {
    digitalWrite(relay4, HIGH);
  }
}

BLYNK_WRITE(V4) {
  bool value5 = param.asInt(); // Use int instead of bool
  // Check these values and turn relay5 ON and OFF
  if (value5 == 1) {
    digitalWrite(relay5, LOW);
  } else {
    digitalWrite(relay5, HIGH);
  }
}

void setup() {
  pinMode(SENSOR_OUTPUT_PIN, INPUT);

  pinMode(LED, OUTPUT);

  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);

  // Turn OFF all relays
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  // Read the sensor value
  int sensorValue = digitalRead(SENSOR_OUTPUT_PIN);

  Serial.println(sensorValue);

  if (sensorValue == HIGH) {
    digitalWrite(LED, HIGH);
    Serial.println("Motion Detected");
    delay(10000); // Adjust the delay based on your requirements
  } else {
    digitalWrite(LED, LOW);
    Serial.println("Motion Not Detected");
  }

  // Run the Blynk library
  Blynk.run();
}