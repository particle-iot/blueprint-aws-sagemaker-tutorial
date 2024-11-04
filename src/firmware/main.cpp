/* 
 * Particle Blueprint - AWS SageMaker
 * https://github.com/particle-iot/blueprint-aws-sagemaker-tutorial
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "Grove_Temperature_And_Humidity_Sensor.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

//An example of DHT11 for BORON
#define DHTPIN 	D2     // set pin

DHT dht(DHTPIN);

// setup() runs once, when the device is first turned on
void setup() {

  // Initialize DHT sensor
  dht.begin();

  Log.info("Setup has finished!");
}

// loop() runs over and over again, as quickly as it can execute.
// This is a very basic programming model (the superloop) - 
// for more advanced threading models, please see the Device OS documentation at docs.particle.io
void loop() {

  //Read Humidity
	float h = dht.getHumidity();

  // Read temperature as Celsius
	float t = dht.getTempCelcius();

  // Check if any reads failed
	if (isnan(h) || isnan(t))
	{
		  Serial.println("Failed to read from DHT11 sensor!");
	}
  else
  {
      // Example: Publish event to cloud every 10 seconds.
      Log.info("Sending the data to the cloud...");
      
      //create a JSON object that contains the temperature and humidity using the JSON helper
      JSONBufferWriter writer(256);
      writer.beginObject();
      writer.name("temperatureInC").value(t);
      writer.name("humidity").value(h);
      writer.endObject();

      //publish the event to the cloud
      Particle.publish("env-data", writer.buffer(), PRIVATE);
  }

  //block for 10 seconds
  delay( 10 * 1000 );
}
