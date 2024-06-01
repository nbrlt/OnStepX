// -------------------------------------------------------------------------------------------------
// Pin map for OnStep MaxESP4 (ESP32S)
#pragma once

#if defined(ESP32)

// Serial ports (see Pins.defaults.h for SERIAL_A)
// Serial0: RX Pin GPIO3, TX Pin GPIO1 (to USB serial adapter)
// Serial1: RX1 Pin GPIO10, TX1 Pin GPIO9 (on SPI Flash pins, must be moved to be used)
// Serial2: RX2 Pin GPIO16, TX2 Pin GPIO17

#if SERIAL_A_BAUD_DEFAULT != OFF
  #define SERIAL_A              Serial
#endif
#if SERIAL_B_BAUD_DEFAULT != OFF
  #define SERIAL_B              Serial2
#endif


// The multi-purpose pins (Aux3..Aux8 can be analog pwm/dac if supported)
#define AUX2_PIN                4               // M3 pin TMC UART RX
#define AUX3_PIN                5               // Home SW for Axis1
#define AUX4_PIN                16               // Home SW for Axis2
#define AUX5_PIN                1                // TX0 main USB, etc.
#define AUX6_PIN                3                // RX0 main USB, etc.
#define AUX7_PIN                17               // Limit SW, PPS, etc.
#define AUX8_PIN                18               // 1-Wire, Status LED, Reticle LED, Tone, etc.

// The PEC index sense is a logic level input, resets the PEC index on rising edge then waits for 60 seconds before allowing another reset
#ifndef PEC_SENSE_PIN
  #define PEC_SENSE_PIN         35               // [input only 36] PEC Sense, analog (A0) or digital (GPIO36)
#endif

// The status LED w/ 4.7k resistor in series to limit the current to the LED
#ifdef STATUS_LED_ON_STATE
  #undef STATUS_LED_ON_STATE
#endif
#define STATUS_LED_ON_STATE HIGH
#ifndef STATUS_LED_PIN
  #define STATUS_LED_PIN        2               // Default LED Anode (+)
#endif
#ifdef MOUNT_LED_ON_STATE
  #undef MOUNT_LED_ON_STATE
#endif
#define MOUNT_LED_ON_STATE      HIGH
#define MOUNT_LED_PIN           STATUS_LED_PIN   // Default LED Anode (+)

// Specify the ESP32 I2C pins
#define I2C_SDA_PIN             21
#define I2C_SCL_PIN             22

// The PPS pin is a 3.3V logic input, OnStep measures time between rising edges and adjusts the internal sidereal clock frequency
#ifndef PPS_SENSE_PIN
  #define PPS_SENSE_PIN         34         // PPS time source, GPS for example
#endif

// Axis1 RA/Azm step/dir driver
#define AXIS1_ENABLE_PIN        14           // Enable pin control
#define AXIS1_ENABLE_STATE 	    HIGH			//DRV8932 requires HIGH enable pin
#define AXIS1_M0_PIN            OFF              // hardwired for TMC UART address 0
#define AXIS1_M1_PIN            OFF              // hardwired for TMC UART address 0
#define AXIS1_M2_PIN            OFF              // UART TX
#define AXIS1_M3_PIN            OFF              // UART RX
#define AXIS1_STEP_PIN          19
#define AXIS1_DIR_PIN           13                // [must be high at boot 0]
#define AXIS1_VREF_PIN			25				// Vref DAC output



// Axis2 Dec/Alt step/dir driver
#define AXIS2_ENABLE_PIN        27           // Enable pin control
#define AXIS2_ENABLE_STATE 	    HIGH			//DRV8932 requires HIGH enable pin
#define AXIS2_M0_PIN            OFF              // hardwired for TMC UART address 1
#define AXIS2_M1_PIN            OFF              // hardwired for TMC UART address 1
#define AXIS2_M2_PIN            OFF              // N/C
#define AXIS2_M3_PIN            OFF              // UART RX
#define AXIS2_STEP_PIN          33
#define AXIS2_DIR_PIN           32
#define AXIS2_VREF_PIN			26				// Vref DAC output


#else
#error "Wrong processor for this configuration!"

#endif
