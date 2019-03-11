#include <Wire.h>
#include <RTClib.h>
RTC_DS1307 RTC; //code uses Real Time Clock DS1307
const int alarm = 11;
 
void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    pinMode(alarm, OUTPUT);
 
  if (! RTC.isrunning()) {
   Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
  RTC.adjust(DateTime(2017,05,18,11,10,0)); // Set time manually ONCE as above
  }
}

void loop () {
    DateTime now = RTC.now();
     if (now.hour()<10)
    Serial.print('0');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
     if (now.minute()<10)
    Serial.print('0');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    if (now.second()<10)
    Serial.print('0');
    Serial.print(now.second(), DEC);
    if (now.hour() == 10 && now.minute() == 53){
      Alarm();
    }
    
}
void Alarm() {
    tone(alarm, 1000); // Send 1KHz sound signal
    delay(500);       
    noTone(alarm);     // Turn off alarm
    delay(500);        
  }

