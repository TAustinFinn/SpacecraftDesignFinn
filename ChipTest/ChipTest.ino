  // importing libraries for the xchips
  #include <xCore.h>
  #include <xSI01.h>
  #include <xSN01.h>
  #include <xSL01.h>
  #include <xSW01.h>

  xSI01 SI01;
  xSN01 SN01;
  xSL01 SL01;
  xSW01 SW01;

  // uses code or code structure from the 'examples' files of the relevant xinabox chip GitHub libraries, as linked below
  // https://github.com/xinabox/arduino-SL01
  // https://github.com/xinabox/arduino-SW01
  // https://github.com/xinabox/arduino-SN01
  // https://github.com/xinabox/arduino-SI01
  

void setup() {
  // start serial monitor
  Serial.begin(115200);

  // set pins for CW01
  #ifdef ESP8266
    Wire.begin(2,14);
    Wire.setClockStretchLimit(15000);
  #endif

  // start communication
  Wire.begin();

  Serial.println("Printing sensor readings");
  
  SL01.begin();
  SW01.begin();
  SI01.begin();
  SN01.begin();  

}

void loop() {
  // SW01 output
  SW01.poll();

  Serial.print("SW01 Data: Altitude: ");
  Serial.print(SW01.getAltitude(101325));
  Serial.print(" m. Humidity: ");
  Serial.print(SW01.getHumidity());
  Serial.print(" %. Pressure: ");
  Serial.print(SW01.getPressure());
  Serial.print(" Pa. Temperature: ");
  Serial.print(SW01.getTempC());
  Serial.print(" C. Temperature: ");
  Serial.print(SW01.getTempF());
  Serial.println(" F.");
  Serial.println();


  // SL01 output
  SL01.poll();

  Serial.print("SL01 Data: Ambient Light Level: ");
  Serial.print(SL01.getLUX());
  Serial.print(" lux. UVB Index: ");
  Serial.println(SL01.getUVIndex());
  Serial.println();

  
  // SI01 output

  SI01.poll();

  Serial.print("SI01 Data: ");
  Serial.print("G: ");
  Serial.print(SI01.getGX());
  Serial.print(", ");
  Serial.print(SI01.getGY());
  Serial.print(", ");
  Serial.print(SI01.getGZ());  

  Serial.print(". A: ");
  Serial.print(SI01.getAX());
  Serial.print(", ");
  Serial.print(SI01.getAY());
  Serial.print(", ");
  Serial.print(SI01.getAZ());

  Serial.print(". M: ");
  Serial.print(SI01.getMX());
  Serial.print(", ");
  Serial.print(SI01.getMY());
  Serial.print(", ");
  Serial.print(SI01.getMZ());

  Serial.print(". Roll: ");
  Serial.print(SI01.getRoll());
  Serial.print(" Pitch:");
  Serial.print(SI01.getPitch());
  Serial.print(" GForce:");
  Serial.println(SI01.getGForce());
  Serial.println();

  // SN01 output

  // var to store data from SN01
  SN01.poll();
  

  Serial.print("GPS Time: ");
  Serial.print(SN01.getDate());
  Serial.print(". GPS Date: ");
  Serial.print(SN01.getTime());
  Serial.print(". GPS Latitude: ");
  Serial.print(SN01.getLatitude());
  Serial.print(". GPS Longitude: ");
  Serial.println(SN01.getLongitude());

  delay(20000);
}
