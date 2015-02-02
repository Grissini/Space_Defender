//Space Defender



#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
// NEO_RGB Pixels are wired for RGB bitstream
// NEO_GRB Pixels are wired for GRB bitstream
// NEO_KHZ400 400 KHz bitstream (e.g. FLORA pixels)
// NEO_KHZ800 800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 6, NEO_GRB + NEO_KHZ400);
int sonarPin = 9; //pin connected to analog out on maxsonar sensor

int inchesAway; // inches away from the maxsonar sensor


void setup() {
strip.begin();
strip.show(); // Initialize all pixels to 'off'
Serial.begin(9600);
}

void loop() { 
inchesAway = analogRead(sonarPin) /2; // reads the maxsonar sensor and divides the value by 2
// approximate distance in inches
Serial.print(inchesAway); // prints the sensor information from the maxsonar to the serial monitor 
Serial.println(" inches from sensor");
if (inchesAway < 19) { // if something is 24 inches away then make a 1khz sound
long startTime = millis(); // record the beginning of the proximity event.
    while (inchesAway < 19)
    {
         if ((millis() - startTime) >= 3000)  // If we have been in this loop for 5 seconds
         {
              break;  // exit the loop
         }
         inchesAway = analogRead(sonarPin) /2; // keep reading the sensor
     
     if ((millis() - startTime) >= 3000)  // we passed the 5 second test
     {
         
   for(int j = 0; j < 30; j++){  
      
      
         for(int i = 0; i < 4; i++)
{
  strip.setPixelColor(i, strip.Color(250, 0, 0)); 
}
strip.show();
delay(100);
for(int i = 0; i < 4; i++)
{
  strip.setPixelColor(i, strip.Color(0, 0, 0)); 
}
strip.show();
delay(100);// Flash the leds
     }
}

// turn LED on: 

else if (inchesAway > 18){
  
strip.setPixelColor(1, strip.Color(0, 0, 0));
}




    }//end while
    }//end if
  }//end void loop
