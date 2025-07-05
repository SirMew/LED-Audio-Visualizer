#include <arduinoFFT.h>
#include <FastLED.h>
#include <arduino-timer.h>

#define SAMPLES 64        // Must be a power of 2
#define MIC_IN A0         // Use A0 for mic input
#define LED_PIN 5     // Data pin to LEDS
#define NUM_LEDS 256
#define BRIGHTNESS 255    // LED information 
#define LED_TYPE WS2812B
#define SAMPLE_FREQ 5000
#define COLOR_ORDER GRB
#define BUTTON_PIN 3
#define xres 16            // Total number of  columns in the display
#define yres 16            // Total number of  rows in the display 

//Function protoypes
void getSamples();
void displayUpdateSynth();
void startupRGB(int lednum);
//unused
void colourCalibrate(int lednum);
void displayUpdate();
void circle(int lednum);
uint16_t XY(uint8_t x, uint8_t y, uint8_t kMatrixWidth, uint8_t kMatrixHeight);

//global parameters
float g_vReal[SAMPLES];
float g_vImag[SAMPLES];

int g_Intensity[xres] = { }; // initialize Frequency Intensity to zero
int g_displacement = 1;

// create a timer
auto timer = timer_create_default();

//Create class objects
CRGB leds[NUM_LEDS];            // Create LED Object

ArduinoFFT<float> FFT = ArduinoFFT<float>(g_vReal, g_vImag, SAMPLES, SAMPLE_FREQ);  // Create FFT object

// set up heartbeat ISR to display living status
volatile bool heartbeat(void *) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle the LED
  return true; // repeat? true
}

void setup() {
  // initialise builtin LED for heartbeat status
  pinMode(LED_BUILTIN, OUTPUT); 

  // add input pin for audio input
  pinMode(MIC_IN, INPUT);
  delay(1000);                  // power-up safety delay

  //Initialize LED strips FastLED.setCorrection(TypicalSMD5050);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( UncorrectedColor ); 
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setTemperature(Tungsten100W);

  //schedule heartbeat timer to run every 1000ms
  timer.every(1000, heartbeat);
  //startup light test - loop through red, green and blue for all pixels
  startupRGB(NUM_LEDS);
  //colourCalibrate(NUM_LEDS);
}

void loop() {
  

  //Collect Samples
  getSamples();
  
  //Update display data
  displayUpdateSynth();
  
  //Update LEDs with data
  FastLED.show();
  timer.tick(); //process scheduled functions
}