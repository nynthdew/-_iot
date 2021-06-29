#include "DHT.h"
#define D4 2   // TXD1
#define DHTPIN D4     // what digital pin we're connected to
#define DHTTYPE DHT22  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(115200);
  dht.begin();  // เริ่มต้นเรียกใช้งาน Library DHT11 
}

void loop()
{
  // Wait a few seconds between measurements.
  delay(2000);
  float Humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float Temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(Humidity) || isnan(Temp)) 
  {
    Serial.println("Failed to read from DHT sensor!");  // บอกสถานะหากเกิดการผิดพลาดในการอ่านข้อมูล สาเหตุอาจเกิดได้จากสัญญาณรบกวน หรือการเชื่อมต่อที่ไม่สมบรูณ์
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
