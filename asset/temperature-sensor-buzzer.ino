/*Code opérationnel.
Mercredi 25 mai à 12:42
*/

#include "Seeed_MCP9808.h"
 
MCP9808  sensor;
 
void setup()
{
    Serial.begin(115200);

    pinMode(6, OUTPUT);
    if(sensor.init())
    {
        Serial.println("sensor init failed!!");
    }
    //Set upper limit is 30°C
    sensor.set_upper_limit(SET_UPPER_LIMIT_ADDR,0x01e0);
    delay(10);
    //Set upper limit is 32°C
    sensor.set_critical_limit(SET_CRITICAL_LIMIT_ADDR,0x0200);
    delay(10);    //Enable the alert bit.The alert bit outputs low when the temperature value beyond limit.Otherwise stays high.
    sensor.set_config(SET_CONFIG_ADDR,0x0008);
 
    Serial.println("sensor init!!");
}
 
void loop()
{
    float temp=0;
    //Get temperature ,a float-form value.
    sensor.get_temp(&temp);
    Serial.print("temperature value is: ");
    Serial.println(temp);
    delay(1000);

  if (temp > 30){
      digitalWrite(6, HIGH);
    }
    else{
    digitalWrite(6, LOW);
}
}
