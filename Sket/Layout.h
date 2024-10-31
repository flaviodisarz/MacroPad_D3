/////////////////////////////
//   Definição de Matriz   //
//      Matriz 2x2         //
//     Encoder's 1 e 2     //
//       [E1] [E2]         //
//       [ 1] [ 2]         //
//       [ 3] [ 4]         //
//                         //
/////////////////////////////

// Definições de Quantidade de Colunas e Linhas
const byte ROWS = 2;
const byte COLS = 2;

// Definições da Matriz de Teclas
char keys[ROWS][COLS] = {
  { '1', '2' },
  { '3', '4' },
};

byte rowPins[ROWS] = { R1, R2 };
byte colPins[COLS] = { C1, C2 };
//Definições das Led's
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NumLeds, DATA_PIN, NEO_GRB + NEO_KHZ800);

// Instanciando os Encoders
Encoder encoder1(ENCODER1_A, ENCODER1_B);
Encoder encoder2(ENCODER2_A, ENCODER2_B);