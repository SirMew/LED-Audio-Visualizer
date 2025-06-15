#include <arduinoFFT.h>
#include <FastLED.h>

#define SAMPLES 64        // Must be a power of 2
#define MIC_IN A0         // Use A0 for mic input
#define LED_PIN     5     // Data pin to LEDS
#define NUM_LEDS    16*16
#define BRIGHTNESS  150    // LED information 
#define LED_TYPE    WS2812B
#define SAMPLE_FREQ 5000
#define COLOR_ORDER GRB
#define BUTTON_PIN 3
#define xres 16            // Total number of  columns in the display
#define yres 16            // Total number of  rows in the display
#define heart_beat_pin   LED_BUILTIN // digital pin for heart beat LED 

//Function protoypes
void getSamples();
void displayUpdate();
void startupRGB();
void heart_beat();

//global parameters
float vReal[SAMPLES];
float vImag[SAMPLES];
const uint16_t samples = 64;
const float samplingFrequency = 5000;

int Intensity[xres] = { }; // initialize Frequency Intensity to zero
int displacement = 1;

long unsigned heart_beat_freq = 10; // time(milliseconds) of heart beat frequency 
long unsigned heart_beat_on_off_time; // the time the LED is on and off - 1/2 frequency 
long unsigned last_heart_beat_time;   // time in milliseconds of last heart beat status change 
bool heart_beat_status = HIGH;        // current status of heart beat, start high 

//Create class objects
CRGB leds[NUM_LEDS];            // Create LED Object

ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, SAMPLES, SAMPLE_FREQ);  // Create FFT object

void setup() {
  pinMode(MIC_IN, INPUT);
  delay(1000);                  // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //Initialize LED strips FastLED.setCorrection(TypicalSMD5050);
  FastLED.setBrightness(BRIGHTNESS);

  // initialise builtin LED for heartbeat status
  pinMode(heart_beat_pin, OUTPUT); 
  heart_beat_on_off_time = heart_beat_freq / 2; // LED is on and off at 1/2 frequency time 

  //startup light test - loop through red, green and blue for all pixels
  startupRGB(NUM_LEDS);
}

void loop() {
  //heartbeat function
  heart_beat();

  //Collect Samples
  getSamples();
  
  //Update display data
  displayUpdate();
  
  //Update LEDs with data
  FastLED.show();
}