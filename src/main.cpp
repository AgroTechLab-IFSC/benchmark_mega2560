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
#include <limits.h>
#include <avr/power.h>
#include "mega2560.h"
#include "benchmark.h"



const uint8_t benchmark_mode = BENCHMARK_MODE_0;
int64_t var_add, var_sub;
double var_mult, var_div;
float var_analog;




void setup() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, HIGH);
      break;

    case BENCHMARK_MODE_1:
      for (uint8_t i = 0; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, OUTPUT);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.begin(9600);
      break;
    
    case BENCHMARK_MODE_2:
      for (uint8_t i = 3; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, INPUT_PULLUP);
      }
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, LOW);

      pinMode(A0, OUTPUT);
      pinMode(A1, OUTPUT);
      pinMode(A2, OUTPUT);
      pinMode(A3, OUTPUT);
      pinMode(A4, OUTPUT);
      pinMode(A5, OUTPUT);
      pinMode(A6, OUTPUT);
      pinMode(A7, OUTPUT);      
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);
      

      power_adc_disable();
      power_spi_disable();

      Serial.begin(9600);
      break;
  
    case BENCHMARK_MODE_3:
      for (uint8_t i = 3; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, INPUT_PULLUP);
      }
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, LOW);

      pinMode(A0, OUTPUT);
      pinMode(A1, OUTPUT);
      pinMode(A2, OUTPUT);
      pinMode(A3, OUTPUT);
      pinMode(A4, OUTPUT);
      pinMode(A5, OUTPUT);
      pinMode(A6, OUTPUT);
      pinMode(A7, OUTPUT);      
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);

      power_adc_disable();
      power_spi_disable();

      // Put CPU clock at 8MHz
      noInterrupts();
      CLKPR = _BV(CLKPCE);  // enable change of the clock prescaler
      CLKPR = _BV(CLKPS0);  // divide frequency by 2 = 8 MHz
      interrupts();

      Serial.begin(115200);
      break;

    case BENCHMARK_MODE_4:
      for (uint8_t i = 3; i < TOTAL_DIO_PORTS; i++) {
        pinMode(i, INPUT_PULLUP);
      }
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, LOW);

      pinMode(A0, OUTPUT);
      pinMode(A1, OUTPUT);
      pinMode(A2, OUTPUT);
      pinMode(A3, OUTPUT);
      pinMode(A4, OUTPUT);
      pinMode(A5, OUTPUT);
      pinMode(A6, OUTPUT);
      pinMode(A7, OUTPUT);      
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);

      power_adc_disable();
      power_spi_disable();

      // Put CPU clock at 4MHz
      noInterrupts();
      CLKPR = _BV(CLKPCE);  // enable change of the clock prescaler
      CLKPR = _BV(CLKPS1);  // divide frequency by 4 = 4 MHz
      interrupts();

      Serial.begin(9600);
      break;

    default:
      break;
  }
}

void loop() {
  switch (benchmark_mode) {
    case BENCHMARK_MODE_0:      
      break;

    case BENCHMARK_MODE_1:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < TOTAL_DIO_PORTS; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      
      var_analog = analogRead(A0);
      var_analog = analogRead(A1);
      var_analog = analogRead(A2);
      var_analog = analogRead(A3);
      var_analog = analogRead(A4);
      var_analog = analogRead(A5);
      var_analog = analogRead(A6);
      var_analog = analogRead(A7);
      break;
  
    case BENCHMARK_MODE_2:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < 3; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      break;

    case BENCHMARK_MODE_3:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < 3; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      break;

    case BENCHMARK_MODE_4:
      var_add = INT64_MIN;
      var_sub = INT64_MAX;
      var_mult = 1;
      var_div = __DBL_MAX__;
      var_analog = 0.0f;
      
      Serial.println(F("Run"));

      for (uint64_t i = 0; i < 1000; i++) {
        var_add += 3;
        var_sub -= 3;
        var_mult = var_mult * 1.6785;
        var_div = var_div / 1.6785;        
      }

      for (uint8_t i = 0; i < 3; i++) {        
        if (digitalRead(i) == HIGH) {
          digitalWrite(i, LOW);
        } else {
          digitalWrite(i, HIGH);
        }
      }
      break;

    default:
      break;
  }
}