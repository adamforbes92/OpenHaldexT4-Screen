#pragma once

#define baudBT 9600                  // Bluetooth Baud Rate (default is 9800)
#define baudAT 38400                 // Bluetooth AT Baud Rate (once reset, is 38400)
#define serialBaud 115200            // for Serial/USB comms
#define btTimeout 3000               // Bluetooth timeout
#define btDelay 1000                 // Bluetooth delay
#define stateDebug 1                 // if 1, will Serial print

#define pinBT_Conf 9                 // 'button' for BT config
#define pinBT_Reset 3                // 'button' for BT reset
#define pinBluetoothRX 21            // Serial RX for BT module
#define pinBluetoothTX 20            // Serial TX for BT module
#define pinRotaryA 4                 // Rotary Rot+
#define pinRotaryB 5                 // Rotary Rot-
#define pinRotarySW 6                // Rotary Button

#define _LCDML_DISP_cols 16          // LCD columns
#define _LCDML_DISP_rows 2           // LCD rows
#define _LCDML_DISP_cfg_cursor 0x7E  // cursor Symbol
#define _LCDML_DISP_cfg_scrollbar 1  // enable a scrollbar
#define _LCDML_DSIP_use_header 0     // always display a header
#define _LCDML_cfg_use_ram 1         // use RAM
#define lcdAddress 0x27              // LCD module address (can use i2c scanner to find)

#define eepRefresh 2000              // EEPROM Refresh in ms
#define btRefresh 500                // BT Send Data Refresh in ms

#define arraySize(array) (sizeof((array)) / sizeof((array)[0]))
#define serialPacketEnd 0xFF  // define Bluetooth Serial Packet end

// Splash screen text
#define splash1 "Booting..."
#define splash2 "OpenHaldex"
#define boardVer "Board Ver:"
#define screenVer "Screen Ver:"

// OpenHaldex module name etc
#define pairingBT "Begin Pairing..."
#define strBTConnected1 "Pairing"
#define strBTConnected2 "Successful!"
#define OpenHaldexT4 "OpenHaldexT4"

// Libary Definitions
/* Functions */
// EEPROM Related
extern void readEEP();
extern void writeEEP();

// Bluetooth Related
extern void btSendStatus();
extern void btReceiveStatus();

// Display Menus
extern void displaySplash();

// Haldex mode types
typedef enum openhaldex_mode_id {
  MODE_STOCK,
  MODE_FWD,
  MODE_5050,
  MODE_CUSTOM
} openhaldex_mode_id;

typedef struct openhaldexState {
  openhaldex_mode_id mode;
  byte ped_threshold;
  bool mode_override;
} openhaldexState;

/* Globals */
extern byte vehicleSpeed = 0;
extern byte haldexEngagement = 0;
extern byte haldexState = 0;
extern float lockTarget = 0;
extern float pedValue = 0;
extern bool autoConnect = true;

/* EEPROM Data */
extern bool isCustom = false;
extern int lastMode = 0;
extern bool isStandalone = false;
extern uint32_t lastTransmission = 0;
extern bool btConnected = false;
extern bool runOnce = false;
extern bool requestPair = false;
extern bool showSplash = true;
extern bool showScreensaver = true;

/* for menu */
extern boolean g_status_if_dyn_content_external_refresh_is_displayed = false;
extern unsigned long g_timer_1000ms = 0;

/* current software version */
extern int screenSoftwareVersion = 203;
extern int boardSoftwareVersion = 0;

/* bluetooth serial data */
int incomingLen;
byte btIncoming[10];
byte btOutgoing[4];

extern const uint8_t scroll_bar[5][8] = {
  { B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001 },  // scrollbar top
  { B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001 },  // scroll state 1
  { B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001 },  // scroll state 2
  { B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001 },  // scroll state 3
  { B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111 }   // scrollbar bottom
};
