#include <xCore.h>
#include <xSI01.h>


xSI01 SI01;

#define PRINT_SPEED 250
static unsigned long lastPrint = 0;


void setup() {
  // Start the Serial Monitor at 115200 BAUD
  Serial.begin(115200);
  
  // Set the I2C Pins for CW01
  #ifdef ESP8266
    Wire.pins(2, 14);
    Wire.setClockStretchLimit(15000);
  #endif

  Wire.begin();
    
  if (!SI01.begin()) {
    Serial.println("Failed to communicate with SI01.");
    Serial.println("Check the Connector");
  } else {
    Serial.println("start successful");
  }
  millis();
}

void loop() {
  // last time a test started
  long lastStart = 0;
  // for loop, repeats 5 times
  for (int i = 1; i < 6; i++) {
  lastStart = millis();
  // set up to loop for 20 seconds
  while (lastStart + 20000 > millis()) {
  // need to yield or watchdog makes code restart
  yield(); 
  // Read and calculate data from SI01 sensor
  SI01.poll();
  float vib=(sqrt(sq(SI01.getAX())+sq(SI01.getAY())+sq(SI01.getAZ()))-1)*10.0;

  if ( (lastPrint + PRINT_SPEED) < millis()) {
    Serial.print(millis());
    Serial.print(" ");
    printAccel(); // Print "A: ax, ay, az"
    Serial.println();
    //client.add("vibrations", vib);
    //client.sendAll(true);
    lastPrint = millis(); // Update lastPrint time
  }
  }
  Serial.print("Test number ");
  Serial.print(i);
  Serial.println(" completed");
  // wait 10 seconds to run next test
  delay(10000);
  }
}

void printAccel(void) {
  Serial.println((sqrt(sq(SI01.getAX())+sq(SI01.getAY())+sq(SI01.getAZ()))-1)*10.0);
}
