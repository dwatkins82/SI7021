#include <Wire.h>
#include <SI7021.h>

SI7021 sensor;

void setup() {
    Serial.begin(9600);
    
    sensor.begin();
}

void loop() {

    // temperature is an integer in hundredths
    int temperature = sensor.getCelsiusHundredths();

    float temp = ((float)temperature / 100);

    Serial.print(" Temp C: ");
    Serial.print(temp);
    
    delay(5000);
    
    // humidity is an integer representing percent
    int humidity = sensor.getHumidityPercent();

    Serial.print(", Humidity %: ");
    Serial.print(humidity);
    
    delay(5000);
    
    // this driver should work for SI7020 and SI7021, this returns 20 or 21
    int deviceid = sensor.getDeviceId(); 
    
    Serial.print(", DeviceID: ");
    Serial.print(deviceid);
    
    delay(5000);

  /*
    Serial.print(", Apply Heater (20s): ");

    // enable internal heater for testing
    sensor.setHeater(true);
    delay(20000);
    sensor.setHeater(false);

    Serial.print("Applied");
    
    // see if heater changed temperature
    temperature = sensor.getCelsiusHundredths();

    temp = ((float)temperature / 100);

    Serial.print(", Temp C: ");
    Serial.print(temp);

    Serial.print(", Cool down (20s): ");
    
    //cool down
    delay(20000);

    Serial.print("Cooled");

  */

    // get humidity and temperature in one shot, saves power because sensor takes temperature when doing humidity anyway
    si7021_thc data = sensor.getTempAndRH();

    temperature = data.celsiusHundredths;
    temp = ((float)temperature / 100);

    Serial.print(", Temp C: ");
    Serial.print(temp);

    humidity = data.humidityPercent;

    Serial.print(", Humidity %: ");
    Serial.println(humidity);
    
    delay(5000);
}
