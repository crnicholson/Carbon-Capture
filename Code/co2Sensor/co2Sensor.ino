// Basic demo for readings from Adafruit SCD30
#include <Adafruit_SCD30.h> // Thanks Adafruit!

Adafruit_SCD30  scd30;

void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Starting...");

  // Try to initialize!
  if (!scd30.begin()) {
    Serial.println("Failed to find SCD30 chip");
    while (1) { delay(10); }
  }
  
  Serial.println("SCD30 Found!");

  if (!scd30.setMeasurementInterval(2)){ // Setting a measurement interval of 2 seconds. This can be between 2-1000 seconds.
    Serial.println("Failed to set measurement interval");
    while(1){ delay(10);}
  }

  Serial.print("Measurement Interval: "); 
  Serial.print(scd30.getMeasurementInterval()); 
  Serial.println(" seconds");

  Serial.println("CO2 ppm, relative humidity %, temp (C)");
}

void loop() {
  if (scd30.dataReady()) {
    if (!scd30.read()){ Serial.println("Error reading sensor data"); return; }
    Serial.print(scd30.CO2, 3);
    Serial.print(" ");
    Serial.print(scd30.relative_humidity);
    Serial.print(" ");
    Serial.println(scd30.temperature);
  } else {
    Serial.println("No data");
  }
}