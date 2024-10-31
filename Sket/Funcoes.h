//////////////////////////////////////////////
//     Codigo de Definições das Funções     //
//                                          //
//     Funções dos Encoders                 //
//     Função de Alteração de Modo          //
//                                          //
//////////////////////////////////////////////

// Funções dos Encoders

//Encoder 1 Giro para a Direita
void encoder1Clockwise() {
  switch (ContadorModo) {
    case 0:
      Serial.println("E1 Direita");
      L1R1();
      break;
    case 1:
      Serial.println("E1 Direita");
      L2R1();
      break;
    case 2:
      Serial.println("E1 Direita");
      L3R1();
      break;
    case 3:
      Serial.println("E1 Direita");
      L4R1();
      break;
  }
}

//Encoder 1 Giro para a Esquerda
void encoder1CounterClockwise() {
  switch (ContadorModo) {
    case 0:
      Serial.println("E1 Esquerda");
      L1L1();
      break;
    case 1:
      Serial.println("E1 Esquerda");
      L2L1();
      break;
    case 2:
      Serial.println("E1 Esquerda");
      L3L1();
      break;
    case 3:
      Serial.println("E1 Esquerda");
      L4L1();
      break;
  }
}

//Encoder 1 Pressionado
void encoder1ButtonPressed() {
  switch (ContadorModo) {
    case 0:
      Serial.println("E1");
      L1E1();
      break;
    case 1:
      Serial.println("E1");
      L2E1();
      break;
    case 2:
      Serial.println("E1");
      L3E1();
      break;
    case 3:
      Serial.println("E1");
      L4E1();
      break;
  }
}
//Encoder 2 Giro para a Direita
void encoder2Clockwise() {
  switch (ContadorModo) {
    case 0:
      Serial.println("E2 Direita");
      L1L2();
      break;
    case 1:
      Serial.println("E2 Direita");
      L2L2();
      break;
    case 2:
      Serial.println("E2 Direita");
      L3L2();
      break;
    case 3:
      Serial.println("E2 Direita");
      L4L2();
      break;
  }
}

//Encoder 2 Giro para a Esquerda
void encoder2CounterClockwise() {
  switch (ContadorModo) {
    case 0:
      Serial.println("E2 Esquerda");
      L1R2();
      break;
    case 1:
      Serial.println("E2 Esquerda");
      L2R2();
      break;
    case 2:
      Serial.println("E2 Esquerda");
      L3R2();
      break;
    case 3:
      Serial.println("E2 Esquerda");
      L4R2();
      break;
  }
}

//Encoder 2 Pressionado
void encoder2ButtonPressed() {
  switch (ContadorModo) {
    case 0:
      Serial.println("E2");
      L1E2();
      break;
    case 1:
      Serial.println("E2");
      L2E2();
      break;
    case 2:
      Serial.println("E2");
      L3E2();
      break;
    case 3:
      Serial.println("E2");
      L4E2();
      break;
  }
}

// Estado e Sentido dos Encoders
void checkEncoders() {
  long newPosEncoder1 = encoder1.read() / ENCODER_STEP;
  if (newPosEncoder1 > posEncoder1) {
    encoder1Clockwise();
  } else if (newPosEncoder1 < posEncoder1) {
    encoder1CounterClockwise();
  }
  posEncoder1 = newPosEncoder1;
  long newPosEncoder2 = encoder2.read() / ENCODER_STEP;
  if (newPosEncoder2 > posEncoder2) {
    encoder2Clockwise();
  } else if (newPosEncoder2 < posEncoder2) {
    encoder2CounterClockwise();
  }
  posEncoder2 = newPosEncoder2;
  int newEncoder1ButtonState = digitalRead(ENCODER1_BUTTON_PIN);
  if (newEncoder1ButtonState == LOW && encoder1ButtonState == HIGH) {
    encoder1ButtonPressed();
  }
  encoder1ButtonState = newEncoder1ButtonState;
  int newEncoder2ButtonState = digitalRead(ENCODER2_BUTTON_PIN);
  if (newEncoder2ButtonState == LOW && encoder2ButtonState == HIGH) {
    encoder2ButtonPressed();
  }
  encoder2ButtonState = newEncoder2ButtonState;
}

// Função de Alteração de Modo
void checkModoBotao() {
  StatusModo = digitalRead(ModoBotao);
  if (StatusModo != UltimoStatusModo) {
    if (StatusModo == LOW) {
      ContadorModo++;
      Cor = 0;
      ledChangingState = true;
      layoutChangeMillis = millis();
    }
    delay(50);
  }
  UltimoStatusModo = StatusModo;
  if (ContadorModo > 3) {
    ContadorModo = 0;
  }
}
