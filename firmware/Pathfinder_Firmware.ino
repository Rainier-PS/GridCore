const int buttonPins[4] = {26, 27, 28, 29};  // BTN1 (TL), BTN2 (TR), BTN3 (BL), BTN4 (BR)
const int ledPins[4] = {0, 7, 6, 1};         // LED1 (BL), LED2 (TL), LED3 (TR), LED4 (BR)

int currentLed = -1;
int score = 0;
bool gameStarted = false;
bool waitingForInput = false;
unsigned long reactionStart = 0;
unsigned long timeLimit = 3000;  // starts at 3000 ms

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  splashScreen();
}

void loop() {
  if (!gameStarted) {
    delay(1000);
    startRound();
    gameStarted = true;
  }

  if (waitingForInput) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        handleInput(i);
        break;
      }
    }

    if (millis() - reactionStart > timeLimit) {
      showFail();
      resetGame();
    }
  }
}

void splashScreen() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(150);
  }
}

void startRound() {
  currentLed = random(0, 4);
  digitalWrite(ledPins[currentLed], HIGH);
  reactionStart = millis();
  waitingForInput = true;
}

void handleInput(int buttonIndex) {
  waitingForInput = false;
  digitalWrite(ledPins[currentLed], LOW);

  if (buttonIndex == currentLed) {
    showSuccess();
    score++;
    timeLimit = max(1000, 3000 - (score * 200)); // reduce time per round
  } else {
    showFail();
    resetGame();
  }

  delay(1000);
  gameStarted = false;
}

void showSuccess() {
  for (int i = 0; i < 2; i++) {
    allLeds(HIGH);
    delay(150);
    allLeds(LOW);
    delay(150);
  }
}

void showFail() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPins[currentLed], HIGH);
    delay(150);
    digitalWrite(ledPins[currentLed], LOW);
    delay(150);
  }
}

void allLeds(bool state) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], state);
  }
}

void resetGame() {
  score = 0;
  timeLimit = 3000;
  waitingForInput = false;
  gameStarted = false;
}
