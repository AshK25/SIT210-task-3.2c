// This #include statement was automatically added by the Particle IDE.
#include <BH1750Lib.h>

// Define the analog input pin connected to the light sensor
int lightSensorPin = A0;

int led = D7;

// Define the threshold value for sunlight detection
int sunlightThreshold = 500;

// Define IFTTT event names and keys
String event_name = "detecting_sunlight";
String key = "dQHTOBnSNZeMMFRLC5UMG8";

void setup() 
{
  // Start serial communication for debugging purposes
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // Read the analog value from the light sensor
    int lightValue = analogRead(lightSensorPin);

    // Print the light value for debugging purposes
    Serial.println(lightValue);

    // Check if the light value is above the sunlight threshold
    if (lightValue > sunlightThreshold) 
    {
        digitalWrite(led, HIGH);
        // Sunlight is detected, send a notification
        Particle.publish("detecting_sunlight", "The terrarium is receiving sunlight.");
        // Sunlight is detected, send a notification via IFTTT
        String event_url = "https://maker.ifttt.com/trigger/{detecting_sunlight}/json/with/key/dQHTOBnSNZeMMFRLC5UMG8" ;
        delay(2000);
    } 
    else 
    {
        digitalWrite(led, LOW);
        // Sunlight is not detected, send a notification
        Particle.publish("detecting_sunlight", "The terrarium is not receiving sunlight.");
         // Sunlight is not detected, send a notification via IFTTT
        String event_url = "https://maker.ifttt.com/trigger/https://maker.ifttt.com/trigger/{detecting_sunlight}/json/with/key/dQHTOBnSNZeMMFRLC5UMG8" ;
        Particle.publish("detecting_sunlight", event_url);
        delay(2000);

    }
  
}
