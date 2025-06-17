#include <arduinoFFT.h>
#include <FastLED.h>

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
#define heart_beat_pin LED_BUILTIN // digital pin for heart beat LED 

//Function protoypes
void getSamples();
void displayUpdate();
void startupRGB(int lednum);
void heart_beat();
void colourCalibrate(int lednum);
void circle(int lednum);
uint16_t XY(uint8_t x, uint8_t y, uint8_t kMatrixWidth, uint8_t kMatrixHeight);

//global parameters
float g_vReal[SAMPLES];
float g_vImag[SAMPLES];

int g_Intensity[xres] = { }; // initialize Frequency Intensity to zero
int g_displacement = 1;

//Create class objects
CRGB leds[NUM_LEDS];            // Create LED Object

ArduinoFFT<float> FFT = ArduinoFFT<float>(g_vReal, g_vImag, SAMPLES, SAMPLE_FREQ);  // Create FFT object

void setup() {
  // initialise builtin LED for heartbeat status
  pinMode(heart_beat_pin, OUTPUT); 

  // add input pin for audio input
  //pinMode(MIC_IN, INPUT);

  //begin serial for debug
  Serial.begin(115200);
  Serial.println("START");

  delay(1000);                  // power-up safety delay

  //Initialize LED strips FastLED.setCorrection(TypicalSMD5050);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( UncorrectedColor ); 
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setTemperature(Tungsten100W);

  //startup light test - loop through red, green and blue for all pixels
  startupRGB(NUM_LEDS);
  circle(NUM_LEDS);
  //colourCalibrate(NUM_LEDS);
}

void loop() {
  //heartbeat function
  heartbeat();

  //Collect Samples
  //getSamples();
  
  //Update display data
  //displayUpdate();
  
  /*for(int i=0;i<NUM_LEDS;i++){
            leds[i] = 0xAB985B; //gold
      }
    FastLED.show();
    delay(300);*/

  //Update LEDs with data
  FastLED.show();
}