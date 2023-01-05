const int pinsIn[] = {2, 3, 4, 5, 9}; //Part of pinMode setup
const int pinsOut[] = {7, 8, 10, 11, 12, 13}; //part of pinMode setup
const int selections[] = {10, 11, 12, 13}; //Pin# of Button that can be selected

int buttonStates[] = {0, 0, 0, 0}; //Value of buttons 1 - 4 and start button at any time
int buttonStart = 0;
int i = 0; int n = 0; int s = 0; int v = 0; int x = 0; int y = 0; int z = 0;//Array/Counter test values

int Qcount[] = { -1, -1, -1, -1, -1}; //The number LED of each of the five rounds from 0 - 3

void reassign() { //Reassigning changing variables here to be reset after each failure or full completion
  for (i = 0; i < 4; i++) {
    buttonStates[i] = {0};
  }
  buttonStart = 0;
  s = 0;
  i = 0;
  n = 0;
}

void finishSequence() {
  int count = 0;
  delay(500);
  while (count < 3) {
    digitalWrite(7, HIGH);
    delay(250);
    digitalWrite(7, LOW);
    delay(250);
    count++;
  }
}

void detect() {
  while (s == 0) {    //Button pressed detector loop. If a button has been pressed, this loop ends
    for (n = 0; n < 4; n++) { //Loop that repeatedly collects data for whether or not a button has been pressed
      buttonStates[n] = digitalRead(pinsIn[n]);
      if (buttonStates[n] == HIGH) {
        digitalWrite(selections[n], HIGH);
        delay(100);
        digitalWrite(selections[n], LOW);
      }
    }
    for (i = 0; i < 4; i++) { //Loop that sums selections[] array. If the sum != 0, that means one of the buttons has been pressed.
      s += buttonStates[i];
    }
  }
}

void setup() {
  pinMode(pinsIn, INPUT); //B1-4 and Start
  pinMode(pinsOut, OUTPUT); //L1-4, Red and Green
  randomSeed(analogRead(0)); //Ensuring randomized numbers for the game
  Serial.begin(9600); //Prepares printing to console
}

void loop() {
  buttonStart = digitalRead(9); //Starting Sequence
  Serial.println("reset");
  if (buttonStart == HIGH) {
    delay(1000);
    for (z = 0; z < 5; z++) { //HERE IS THE ROUND NUMBERS
      reassign(); //Resets variables that are to be changed
      Qcount[z] = random(0, 4);//Selects random 1st light to appear
      for (y = 0; y < (z + 1); y++) { //Lights each LED for the game
        delay(500);
        digitalWrite(selections[Qcount[y]], HIGH);
        delay(250);
        digitalWrite(selections[Qcount[y]], LOW);
      }
      for (x = 0; x < (z + 1); x++) {
        reassign();
        delay(500);
        detect();
        Serial.println(buttonStates[Qcount[x]]);
        if (buttonStates[Qcount[x]] == 0) {
          finishSequence();
          return;
        }
      }

      if (z == 4) {
        delay(500);
        for (v = 0; v < 2; v++) {
          digitalWrite(8, HIGH);
          delay(250);
          digitalWrite(8, LOW);
          delay(250);
          Serial.print(z);
        }
        digitalWrite(8, HIGH);
        delay(3000);
        digitalWrite(8, LOW);
      } else if (z < 4) {
        delay(500);
        digitalWrite(8, HIGH);
        delay(500);
        digitalWrite(8, LOW);
      }
    }
  }
}
