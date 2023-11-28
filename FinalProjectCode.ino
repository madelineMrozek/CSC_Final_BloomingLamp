#include <IRremote.hpp> 
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, 9);

IRrecv IR(3); // IR Pin

/////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  IR.enableIRIn();
}

/////////////////////////////////////////////////

void loop() {

  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);

// off
      if (IR.decodedIRData.decodedRawData == 0xBA45FF00){ 
        strip.clear();
        strip.show();
      }

// // up / + brightness
//       if (IR.decodedIRData.decodedRawData == 0xF609FF00){
//         brightness += 50;
//         strip.setBrightness(brightness);
//       }

// // down / - brightness
//       if (IR.decodedIRData.decodedRawData == 0xF807FF00){
//         brightness -= 50;
//         strip.setBrightness(brightness);
//       }

// 0 - rainbow
    for (int i = 0; i < strip.numPixels(); i++){
      if (i%3 == 0){
        strip.setPixelColor(i, 255,0,0);
      }
      else if (i%3 == 1){
        strip.setPixelColor(i, 0,255,0);
      }
      else if (i%3 == 2){
        strip.setPixelColor(i, 255,255,50);
      }
      strip.show();
     }

// 1 - red
      if (IR.decodedIRData.decodedRawData == 0xF30CFF00){
        strip.clear();
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 255,0,0);
          strip.show();
        }
      }

// 2 - orange
      if (IR.decodedIRData.decodedRawData == 0xE718FF00){ 
        strip.clear();
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 255,80,0);
          strip.show();
        }
      }

// 3 - yellow
      if (IR.decodedIRData.decodedRawData == 0xA15EFF00){ 
        strip.clear();
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 255,150,0);
          strip.show();
        }
      }

// 4 - green
      if (IR.decodedIRData.decodedRawData == 0xF708FF00){ 
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 20,255,0);
          strip.show();
        }
      }

// 5 - blue
      if (IR.decodedIRData.decodedRawData == 0xE31CFF00){ 
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 0,0,255);
          strip.show();
        }
      }

// 6 - turquoise 
      if (IR.decodedIRData.decodedRawData == 0xA55AFF00){
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 0,255,100);
          strip.show();
        }
      }

// 7 - purple
      if (IR.decodedIRData.decodedRawData == 0xBD42FF00){ 
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 150,0,255);
          strip.show();
        }
      }

// 8 - pink
      if (IR.decodedIRData.decodedRawData == 0xAD52FF00){ 
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 255,0,200);
          strip.show();
        }
      }

// 9 - white
      if (IR.decodedIRData.decodedRawData == 0xB54AFF00){ 
        for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, 255,255,255);
         strip.show();
        }
      }

    delay(250);
    IR.resume();
  }

}

/////////////////////////////////////////////////

void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

