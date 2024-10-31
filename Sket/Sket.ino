/* _________________________________________________
  |     Codigo Geral MacroPad Versão 3.1           |
  |                                                |
  |            Controle de Processos.              |
  |                                                |
  |     Inclusão das Bibliotecas    --- Ok.        |
  |     Definição dos Pinos         --- Ok.        |
  |     Definição das Teclas        --- OK.        |
  |     Definição das Funções       --- Ok.        |
  |     Definição das Layers        --- Ok.        |
  |     Definição dos Leds          --- Ok.        |
  |     Definição das Cores         --- Ok.        |
  |     Definição dos Rotary        --- Ok.        |
  |     Validação das Funções       --- Ok.        |
  |                                                |
  |________________________________________________|*/


//Bibliotecas Inseridas e Instaladas no Programa.
//Biblioteca de Definição Matricial
#include <Keypad.h>

//Biblioteca de Funções HID
#include <HID-Project.h>
#include <HID-Settings.h>

//Biblioteca LED's
#include <FastLED.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

//Biblioteca Encoder
#include <Encoder.h>

//Biliotecas Próprias
#include "Def.h"
#include "Layout.h"
#include "Cores_Efeitos.h"
#include "Comandos.h"
#include "Funcoes.h"



// Configurações do Sistema
void setup() {
  Serial.begin(9600);
  pinMode(ModoBotao, INPUT_PULLUP);
  pinMode(ENCODER1_BUTTON_PIN, INPUT_PULLUP);
  pinMode(ENCODER2_BUTTON_PIN, INPUT_PULLUP);
  Keyboard.begin();
  pixels.begin();
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  randomSeed(analogRead(0));
}

// Loop do Sistema
void loop() {
  char key = keypad.getKey();
  checkModoBotao();
  checkEncoders();

  unsigned long currentMillis = millis();

  if (ledChangingState) {
    if (currentMillis - layoutChangeMillis < layoutChangeDuration) {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;  // Desliga todos os LEDs
      }
      // Modificar a lógica para acender o LED correto
      if (ContadorModo == 2) {
        leds[3] = CRGB::Red;  // Acende o LED 3 quando ContadorModo é 2
      } else if (ContadorModo == 3) {
        leds[2] = CRGB::Red;  // Acende o LED 2 quando ContadorModo é 3
      } else {
        leds[ContadorModo] = CRGB::Red;  // Acende o LED normal para outros modos
      }
      FastLED.show();
    } else {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;  // Desliga todos os LEDs
      }
      ledChangingState = false;  // Para o estado de mudança de LED
      FastLED.show();
      // Chama as funções correspondentes ao modo
      switch (ContadorModo) {
        case 0:
          L1LED();
          break;
        case 1:
          L2LED();
          break;
        case 2:
          L3LED();
          break;
        case 3:
          L4LED();
          break;
      }
    }
  } else {
    switch (ContadorModo) {
      //Layout 1
      case 0:
        if (key) {
          switch (key) {
            case '1':
              L11();
              Keyboard.releaseAll();
              break;
            case '2':
              L12();
              Keyboard.releaseAll();
              break;
            case '3':
              L13();
              Keyboard.releaseAll();
              break;
            case '4':
              L14();
              Keyboard.releaseAll();
              break;
          }
          delay(50);
          Keyboard.releaseAll();
        }
        break;

      // Layout 2
      case 1:
        if (key) {
          switch (key) {
            case '1':
              L21();
              Keyboard.releaseAll();
              break;
            case '2':
              L22();
              Keyboard.releaseAll();
              break;
            case '3':
              L23();
              Keyboard.releaseAll();
              break;
            case '4':
              L24();
              Keyboard.releaseAll();
              break;
          }
          delay(50);
          Keyboard.releaseAll();
        }
        break;

      // Layout 3
      case 2:
        if (key) {
          switch (key) {
            case '1':
              L31();
              Keyboard.releaseAll();
              break;
            case '2':
              L32();
              Keyboard.releaseAll();
              break;
            case '3':
              L33();
              Keyboard.releaseAll();
              break;
            case '4':
              L34();
              Keyboard.releaseAll();
              break;
          }
          delay(50);
          Keyboard.releaseAll();
        }
        break;

      // Layout 4
      case 3:
        if (key) {
          switch (key) {
            case '1':
              L41();
              Keyboard.releaseAll();
              break;
            case '2':
              L42();
              Keyboard.releaseAll();
              break;
            case '3':
              L43();
              Keyboard.releaseAll();
              break;
            case '4':
              L44();
              Keyboard.releaseAll();
              break;
          }
          delay(50);
          Keyboard.releaseAll();
          Serial.println(key);
        }
        break;
    }
  }

  // Acende LEDs de acordo com o modo atual
  if (!ledChangingState) {
    switch (ContadorModo) {
      case 0:
        L1LED();
        break;
      case 1:
        L2LED();
        break;
      case 2:
        L3LED();
        break;
      case 3:
        L4LED();
        break;
    }
  }
}
