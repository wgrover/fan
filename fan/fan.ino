// 
//   FILE:  dht11_test1.pde
// PURPOSE: DHT11 library test sketch for Arduino
//


#include <dht11.h>

dht11 inside;
dht11 outside;

int relay=3;

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  pinMode(relay, OUTPUT);
}

void loop()
{
  Serial.println("\n");

  int check_inside = inside.read(2);  //inside = pin 2
  int check_outside = outside.read(4);  //outside = pin 4
  
  
  
  
  Serial.print("INSIDE:");
  switch (check_inside)
  {
    case DHTLIB_OK: 
		Serial.println("OK"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.println("Checksum error"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.println("Time out error"); 
		break;
    default: 
		Serial.println("Unknown error"); 
		break;
  }
  

  Serial.print("Humidity (%): ");
  Serial.println((float)inside.humidity, 0);

  Serial.print("Temperature (C): ");
  Serial.println((float)inside.temperature, 0);
  
  
  
   Serial.print("OUTSIDE:");   switch (check_outside)
  {
    case DHTLIB_OK: 
		Serial.println("OK"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.println("Checksum error"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.println("Time out error"); 
		break;
    default: 
		Serial.println("Unknown error"); 
		break;
  }
  
  
  Serial.print("Humidity (%): ");
  Serial.println((float)outside.humidity, 0);

  Serial.print("Temperature (C): ");
  Serial.println((float)outside.temperature, 0);



  
  
  float in = inside.temperature;
  float out = outside.temperature;
  
  if(in-out > 0) {
    Serial.println("Warmer inside than outside; turn on fan");
    digitalWrite(relay, HIGH);  
  }
  if(in-out < 0) {
    Serial.println("Cooler inside than outside, turn off fan");
    digitalWrite(relay, LOW);  
  }
  
  



  
      
  
  delay(1000);     

}



