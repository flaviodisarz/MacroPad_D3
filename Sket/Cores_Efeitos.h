////////////////////////////////////////
//     Codigo de Definições das       //
//     Cores e Efeitos dos LED's      //
//                                    //
//     Efeitos                        //
//     Cores                          //
//     Constantes de Funções          //
//                                    //
////////////////////////////////////////

//Funções de Cor e Efeitos dos LED's
CRGB randomColor() {
  return CRGB(random(256), random(256), random(256));
}

// Funções Rainbow
unsigned long previousMillisRainbow = 0;
const long intervalRainbow = 10;
static uint8_t hue = 0;

// Efeito Rainbow
void Rainbow() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisRainbow >= intervalRainbow) {
    previousMillisRainbow = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(hue + (i * 64), 255, 255);
    }
    FastLED.show();
    hue++;
    if (hue >= 256) {
      hue = 0;
    }
  }
}

// Funções Fade
unsigned long FadePreviousMillis = 0;
const long FadeInterval = 100;
static uint8_t FadeHue = 0;

// Efeito Fade
void Fade() {
  unsigned long currentMillis = millis();
  if (currentMillis - FadePreviousMillis >= FadeInterval) {
    FadePreviousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(FadeHue, 255, 255);
    }
    FastLED.show();
    FadeHue += 1;
  }
}

// Funções Breathing
unsigned long previousBreathingMillis = 0;
const long breathingInterval = 100;
int breathingBrightness = 0;
int breathingFadeAmount = 25; 
int breathingHue = 0; 

// Efeito Breathing
void Breathing() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousBreathingMillis >= breathingInterval) {
    previousBreathingMillis = currentMillis;
    if (breathingBrightness == 0 || breathingBrightness == 255) {
      breathingFadeAmount = -breathingFadeAmount;
      if (breathingBrightness == 0) {
        breathingHue += 32;
        if (breathingHue >= 256) {
          breathingHue = 0;
        }
      }
    }
    breathingBrightness += breathingFadeAmount;
    if (breathingBrightness < 0) {
      breathingBrightness = 0;
    } else if (breathingBrightness > 255) {
      breathingBrightness = 255;
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(breathingHue, 255, breathingBrightness);
    }
    FastLED.show();
  }
}

// Funções Dancing
unsigned long dancingPreviousMillis = 0;
const long dancingInterval = 200;
int dancingIndex = 0;

// Efeito Dancing
void Dancing() {
  unsigned long currentMillis = millis();
  if (currentMillis - dancingPreviousMillis >= dancingInterval) {
    dancingPreviousMillis = currentMillis;
    leds[dancingIndex] = CHSV(random(0, 255), 255, 255);
    FastLED.show();
    dancingIndex = (dancingIndex + 1) % NUM_LEDS;
  }
}

//Funções Perseguição
unsigned long previousMillisChase = 0;
unsigned long chaseColorChangeMillis = 0;
int chaseIndex = 0;
const unsigned long colorChangeIntervalChase = 2000;
uint32_t currentChaseColor = pixels.Color(255, 0, 0);

//Efeito Perseguição
void Chase() {
  unsigned long currentMillis = millis();
  if (currentMillis - chaseColorChangeMillis >= colorChangeIntervalChase) {
    chaseColorChangeMillis = currentMillis;
    currentChaseColor = pixels.Color(random(256), random(256), random(256));
  }
  if (currentMillis - previousMillisChase >= 200) {
    previousMillisChase = currentMillis;
    pixels.clear();
    pixels.setPixelColor(chaseIndex, currentChaseColor);
    pixels.show();
    chaseIndex = (chaseIndex + 1) % pixels.numPixels();
  }
}

//Funções Cinema
unsigned long previousMillisTheaterChase = 0;
unsigned long theaterColorChangeMillis = 0;
int theaterIndex = 0;
const unsigned long colorChangeIntervalTheater = 2000;
uint32_t currentTheaterColor = pixels.Color(255, 0, 0);

//Efeito Cinema
void Theater() {
  unsigned long currentMillis = millis();
  if (currentMillis - theaterColorChangeMillis >= colorChangeIntervalTheater) {
    theaterColorChangeMillis = currentMillis;
    currentTheaterColor = pixels.Color(random(256), random(256), random(256)); 
  }
  if (currentMillis - previousMillisTheaterChase >= 100) {
    previousMillisTheaterChase = currentMillis;
    pixels.clear();
    for (int i = 0; i < pixels.numPixels(); i += 3) {
      pixels.setPixelColor((theaterIndex + i) % pixels.numPixels(), currentTheaterColor);
    }
    pixels.show();
    theaterIndex = (theaterIndex + 1) % 3;
  }
}

//Funções Caminho
unsigned long previousMillisColorWipe = 0;
unsigned long colorWipeColorChangeMillis = 0;
int currentLEDColorWipe = 0;
bool wipeOn = true;
const unsigned long colorChangeIntervalColorWipe = 2000;
uint32_t currentColorWipeColor = pixels.Color(255, 0, 0);

//Efeito Caminho
void Wipe() {
  unsigned long currentMillis = millis();
  if (currentMillis - colorWipeColorChangeMillis >= colorChangeIntervalColorWipe) {
    colorWipeColorChangeMillis = currentMillis;
    currentColorWipeColor = pixels.Color(random(256), random(256), random(256));
  }
  if (currentMillis - previousMillisColorWipe >= 100) {
    previousMillisColorWipe = currentMillis;
    if (currentLEDColorWipe < pixels.numPixels()) {
      if (wipeOn) {
        pixels.setPixelColor(currentLEDColorWipe, currentColorWipeColor);
      } else {
        pixels.setPixelColor(currentLEDColorWipe, 0);
      }
      pixels.show();
      currentLEDColorWipe++;
    } else {
      currentLEDColorWipe = 0; 
      wipeOn = !wipeOn;
    }
  }
}

// Funções Jump
unsigned long previousMillisPula = 0;
const long intervalPula = 50;
float transitionProgressPula = 0;
uint8_t hue1 = 0; 
uint8_t hue2 = 128;

// Efeito Jump
void Jump() {
unsigned long currentMillisPula = millis();
  if (currentMillisPula - previousMillisPula >= intervalPula) {
    previousMillisPula = currentMillisPula;
    transitionProgressPula += 0.01;
    if (transitionProgressPula >= 1.0) {
      transitionProgressPula = 0;
      hue1 += 16;
      hue2 += 16;
      if (hue1 >= 256) hue1 = 0;
      if (hue2 >= 256) hue2 = 0;
    }
    CRGB currentColor1 = CHSV(hue1, 255, 255);
    CRGB currentColor2 = CHSV(hue2, 255, 255);
    leds[0] = currentColor1;
    leds[1] = currentColor2;
    leds[2] = currentColor1;
    leds[3] = currentColor2;
    FastLED.show();
  }
}

// Funções Jump2
unsigned long previousMillisPula2 = 0;
const long intervalPula2 = 50;
float transitionProgressPula2 = 0;
uint8_t hue12 = 0; 
uint8_t hue22 = 128;

// Efeito Jump2
void Jump2() {
unsigned long currentMillisPula = millis();
  if (currentMillisPula - previousMillisPula2 >= intervalPula2) {
    previousMillisPula2 = currentMillisPula;
    transitionProgressPula2 += 0.01;
    if (transitionProgressPula2 >= 1.0) {
      transitionProgressPula2 = 0;
      hue12 += 16;
      hue22 += 16;
      if (hue12 >= 256) hue1 = 0;
      if (hue22 >= 256) hue2 = 0;
    }
    CRGB currentColor1 = CHSV(hue12, 255, 255);
    CRGB currentColor2 = CHSV(hue22, 255, 255);
    leds[0] = currentColor1;
    leds[1] = currentColor1;
    leds[2] = currentColor2;
    leds[3] = currentColor2;
    FastLED.show();
  }
}

//Led's na Cor Vermelha
void Vermelho() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Laranja
void Laranja() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(255, 69, 0));
    pixels.setPixelColor(1, pixels.Color(255, 69, 0));
    pixels.setPixelColor(2, pixels.Color(255, 69, 0));
    pixels.setPixelColor(3, pixels.Color(255, 69, 0));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Amarela
void Amarelo() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(255, 255, 0));
    pixels.setPixelColor(1, pixels.Color(255, 255, 0));
    pixels.setPixelColor(2, pixels.Color(255, 255, 0));
    pixels.setPixelColor(3, pixels.Color(255, 255, 0));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Verde
void Verde() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(0, 20, 0));
    pixels.setPixelColor(1, pixels.Color(0, 20, 0));
    pixels.setPixelColor(2, pixels.Color(0, 20, 0));
    pixels.setPixelColor(3, pixels.Color(0, 20, 0));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Azul
void Azul() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Ciano
void Ciano() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 255));
    pixels.setPixelColor(1, pixels.Color(0, 255, 255));
    pixels.setPixelColor(2, pixels.Color(0, 255, 255));
    pixels.setPixelColor(3, pixels.Color(0, 255, 255));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Lilas
void Lilas() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(75,0,130));
    pixels.setPixelColor(1, pixels.Color(75,0,130));
    pixels.setPixelColor(2, pixels.Color(75,0,130));
    pixels.setPixelColor(3, pixels.Color(75,0,130));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Rosa
void Rosa() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(255, 10, 147));
    pixels.setPixelColor(1, pixels.Color(255, 10, 147));
    pixels.setPixelColor(2, pixels.Color(255, 10, 147));
    pixels.setPixelColor(3, pixels.Color(255, 10, 147));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Lima
void Lima() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(0, 255, 0));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Branco
void Branco() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(255, 255, 255));
    pixels.setPixelColor(1, pixels.Color(255, 255, 255));
    pixels.setPixelColor(2, pixels.Color(255, 255, 255));
    pixels.setPixelColor(3, pixels.Color(255, 255, 255));
    pixels.show();
    Cor = 1;
  }
}

//Led's na Cor Desligado
void Desligado() {
  if (Cor == 0) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.show();
    Cor = 1;
  }
}