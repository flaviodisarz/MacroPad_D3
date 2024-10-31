////////////////////////////////////////////
//     Codigo de Definições dos Pinos     //
//                                        //
//     Pinos Matriz                       //
//     Pinos Rotary Encoder               //
//     Constantes de Funções              //
//                                        //
////////////////////////////////////////////

// Definição de Pinos para os Encoders
#define ENCODER1_A 9
#define ENCODER1_B 8
#define ENCODER1_BUTTON_PIN 10
#define ENCODER2_A 14
#define ENCODER2_B 15
#define ENCODER2_BUTTON_PIN 16

// Definições de Pinos Led's
#define DATA_PIN 18
#define NumLeds 4
#define NUM_LEDS NumLeds
CRGB leds[NUM_LEDS];

// Definições de Pinos Matriz
int R1 = 2;
int R2 = 3;
int C1 = 4;
int C2 = 5;

//Definição de Pino de Modos
const int ModoBotao = 6;

// Definições das Funções
int Cor = 0;
int ContadorModo = 0;
int StatusModo = 0;
int UltimoStatusModo = 0;

// Variáveis para armazenar o estado dos encoders
long posEncoder1 = 0;
long posEncoder2 = 0;
int encoder1ButtonState = HIGH;
int encoder2ButtonState = HIGH;
const int ENCODER_STEP = 4;

// Variáveis para controlar o LED ao mudar de layout
unsigned long layoutChangeMillis = 0;
const long layoutChangeDuration = 3000;
bool ledChangingState = false;

