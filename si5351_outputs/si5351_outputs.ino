/*
 * si5351_outputs.ino - How to set different output sources
 *                      with the Si5351Arduino library
 *
 * Copyright (C) 2016 Jason Milldrum <milldrum@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "si5351.h"
#include "Wire.h"

Si5351 si5351;

void setup()
{
  // Start serial and initialize the Si5351
  Serial.begin(115200);
  
  Serial.println("Si5351 library, MS5351M testing, xiaolaba");
  
  if (si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0) ) {
    Serial.println("MS5351 connected, I2C address 0x60");    
  }else {
    Serial.println("I2C address 0x60, no MS5351 connected");
  }

  // Set CLK0 to output 14 MHz 14,000,000 Hz
  //si5351.set_freq(1400000000ULL, SI5351_CLK0); why 1,400,000,000  ??? 14MHz
  si5351.set_freq(   200000000ULL, SI5351_CLK0); // destired 2MHz, but 1.3MHz frequency, why ?

  // Enable clock fanout for the XO
  //si5351.set_clock_fanout(SI5351_FANOUT_XO, 1);

  // Enable clock fanout for MS
  //si5351.set_clock_fanout(SI5351_FANOUT_MS, 1);

  // Set CLK1 to output the XO signal
  //si5351.set_clock_source(SI5351_CLK1, SI5351_CLK_SRC_XTAL);
  //si5351.output_enable(SI5351_CLK1, 1);

  // Set CLK2 to mirror the MS0 (CLK0) output
  //si5351.set_clock_source(SI5351_CLK2, SI5351_CLK_SRC_MS0);
  //si5351.output_enable(SI5351_CLK2, 1);

  // Change CLK0 output to 2 MHz, observe how CLK2 also changes
  //si5351.set_freq(2000000ULL, SI5351_CLK0);

//  si5351.update_status();
  delay(500);
}

void loop()
{
/*
  // Read the Status Register and print it every 10 seconds
  si5351.update_status();
  Serial.print("  SYS_INIT: ");
  Serial.println(si5351.dev_status.SYS_INIT);
  
  Serial.print("  LOL_A (LOL_1 of MS5351): ");
  Serial.println(si5351.dev_status.LOL_A);
  
  Serial.print("  LOL_B (LOL_2 of MS5351): ");
  Serial.println(si5351.dev_status.LOL_B);
  
  Serial.print("  LOS: ");
  Serial.println(si5351.dev_status.LOS);
  Serial.println("  reg0, bit4, MS5351 reserved, no show by datasheet1.1");
  
  
  Serial.print("  REVID: ");
  Serial.println(si5351.dev_status.REVID);
  Serial.println("  reg0 bit 1:0, MS5351, reserved, no show by datasheet1.1");


  delay(10000);
*/
}
