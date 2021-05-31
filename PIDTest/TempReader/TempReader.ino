#include <xCore.h>          // include core library for xCHIPs
#include <xSX01.h>          // include analogue input sensor librar
#include <math.h>           // include maths functions

#define C_Kelvin 273.15     // for conversion from kelvin to celsius
#define series_res 10000    // value of series resistor in ohms
#define B 3200              // B parameter for thermistor
#define room_tempK 298.15   // room temperature in kelvin
#define room_res 10000      // resistance at room temperature in ohms
#define vcc 3.3             // supply voltage

xSX01 SX01(0x55);           // set the i2c address

float voltage;              // variable containing the measured voltage (0 - 3.3V)
float therm_res;            // thermistor resistance
float act_tempK;            // actual temperature kelvin
float act_tempC;            // actual temperature in celsius

void setup() {
  // put your setup code here, to run once:

  // initialize variables to 0
  voltage = 0;
  therm_res = 0;
  act_tempK = 0;
  act_tempC = 0;

  // start serial communication
  Serial.begin(115200);

  // start i2c communication
  Wire.begin();

  // start the analogue input sensor
  SX01.begin();

  // delay to normailze
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the voltage
  SX01.poll();

  // store the volatge
  voltage = SX01.getVoltage();

  // calculate thermistor resistance
  therm_res = ((vcc * series_res) / voltage) - series_res;

  // calculate the actual temperature in kelvin
  act_tempK = (room_tempK * B) / (B + room_tempK * log(therm_res / room_res));

  // convert kelvin to celsius
  act_tempC = act_tempK - C_Kelvin;

  // print to serial monitor
  Serial.println(act_tempC);

  delay(2000);      // update display every 2 seconds
}
