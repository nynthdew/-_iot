#include "DHT.h"
#define D4 2  
#define DHTPIN D4  
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(115200);
  dht.begin();  
}

void loop()
{

  delay(2000);
  float Humidity = dht.readHumidity();

  float Temp = dht.readTemperature();


  if (isnan(Humidity) || isnan(Temp)) 
  {
    Serial.println("Failed to read from DHT sensor!");  
    return;
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(Humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(Temp);
    Serial.println(" *C ");
  }

}
