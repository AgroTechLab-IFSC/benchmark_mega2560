/**
 * @mainpage
 * Energy consumption benchmark for \subpage mega_2560_page. The following modes are provided in order to test energy consumption:
 *  - <b>MODE 0</b>
 *    - Duty cycle: 100%
 *    - Default arduino project configuration;
 *    - Builtin LED on;
 *  - <b>MODE 1</b>
 * 
 * <br><br>
 * <b>AgroTechLab (<i>Laboratory for the Development of Technologies for Agrobusiness</i>)</b><br>
 * <b>IFSC (<i>Instituto Federal de Santa Catarina</i>)</b><br>
 * Rua Heitor Vila Lobos, 222 - São Francisco<br>
 * Lages/SC - Brazil<br>
 * CEP: 88.506-400
 * 
 */

/**
 * \page mega_2560_page Arduino MEGA 2560 
 * The Arduino Mega 2560 is a microcontroller board based on the ATmega2560. It has 54 digital input/output pins 
 * (of which 15 can be used as PWM outputs), 16 analog inputs, 4 UARTs (hardware serial ports), a 16 MHz crystal 
 * oscillator, a USB connection, a power jack, an ICSP header, and a reset button. It contains everything needed to 
 * support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter 
 * or battery to get started. The Mega 2560 board is compatible with most shields designed for the Uno and the former 
 * boards Duemilanove or Diecimila.
 * 
 * Key features are listed below, hardware details can be found into [datasheet](../datasheets/mega2560.pdf):
 * - Supply voltage (recommended): 7V ~ 12V;
 * - Supply voltage (limits): 6V ~ 20V;
 * - Operating voltage: 5V;
 * - Microcontroller: ATmega2560;
 * - Digital I/O pins: 54 (of which 15 provide PWM output);
 * - Analog input pins: 16;
 * - DC Current per I/O Pin: 20 mA;
 * - DC Current for 3.3V Pin: 50 mA;
 * - Flash memory: 256Kb (8Kb used by bootloader);
 * - SRAM: 8Kb;
 * - EEPROM: 4Kb;
 * - CPU clock: 16MHz;
 * 
 * ![MEGA2560 schematic connection](../figs/mega2560.jpg)<br>
 * ![MEGA2560 schematic connection](../figs/mega2560_pinout.png)
 */

/** 
 * @file main.cpp
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief Project main file.
 * @version 0.1.0
 * @since 2020-11-04 
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020 - AgroTechLab. \n
 * Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Unported License (the <em>"License"</em>). You may not
 * use this file except in compliance with the License. You may obtain a copy of the License <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode" target="_blank">here</a>.
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an <em>"as is" basis, 
 * without warranties or  conditions of any kind</em>, either express or implied. See the License for the specific language governing permissions 
 * and limitations under the License.
 */
#include <Arduino.h>
#include "benchmark.h"


/*teste*/


const uint8_t benchmark_mode = BENCHMARK_MODE_0;

void setup() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
  
    default:
      break;
  }
}

void loop() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:
      while (true) {}
      break;
  
    default:
      break;
  }
}