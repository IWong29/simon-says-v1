const int pinsIn[] = {2, 3, 4, 5, 9}; //Part of pinMode setup
const int pinsOut[] = {7, 8, 10, 11, 12, 13}; //part of pinMode setup
const int selections[] = {10, 11, 12, 13}; //Pin# of Button that can be selected

int buttonStates[] = {0, 0, 0, 0}; //Value of buttons 1 - 4 and at any time
int buttonStart = 0;
int s = 0; int i = 0; int n = 0; int p = 1; int k = 0;//Array/Counter test values

int Q1 = 0; //Value of LED Light(0-3) to select for each of the 5 questions - Randomly selected to choose a certain number in selections[]
int Q2 = 0;
int Q3 = 0;
int Q4 = 0;
int Q5 = 0;

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
    count = count + 1;
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
  Serial.begin(9600); //Prepares printing to console for debugging
}

void loop() {
  buttonStart = digitalRead(9); //Starting Sequence
  delay(1000);
  if (buttonStart == HIGH) {
    reassign(); //Resets variables that are to be changed

    Q1 = random(0, 4);  //Selects random 1st light to appear
    delay(500);
    digitalWrite(selections[Q1], HIGH);
    delay(250);
    digitalWrite(selections[Q1], LOW);

    detect();

    if (buttonStates[Q1] == HIGH) { //If the correct button has been pressed, it turns on the green light
      delay(500);
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);



      reassign(); //Reassigns before preparing next sequence

      Q2 = random(0, 4);  //Selects random 2nd light to appear
      delay(500);
      digitalWrite(selections[Q1], HIGH);
      delay(250);
      digitalWrite(selections[Q1], LOW);
      delay(500);
      digitalWrite(selections[Q2], HIGH);
      delay(250);
      digitalWrite(selections[Q2], LOW);

      detect();

      if (buttonStates[Q1] == HIGH) {

        reassign();
        delay(500);
        detect();

        if (buttonStates[Q2] == HIGH) {
          delay(500);
          digitalWrite(8, HIGH);
          delay(500);
          digitalWrite(8, LOW);



          reassign();

          Q3 = random(0, 4);  //Selects random 2nd light to appear
          delay(500);
          digitalWrite(selections[Q1], HIGH);
          delay(250);
          digitalWrite(selections[Q1], LOW);
          delay(500);
          digitalWrite(selections[Q2], HIGH);
          delay(250);
          digitalWrite(selections[Q2], LOW);
          delay(500);
          digitalWrite(selections[Q3], HIGH);
          delay(250);
          digitalWrite(selections[Q3], LOW);
          detect();

          if (buttonStates[Q1] == HIGH) {

            reassign();
            delay(500);
            detect();

            if (buttonStates[Q2] == HIGH) {

              reassign();
              delay(500);
              detect();

              if (buttonStates[Q3] == HIGH) {
                delay(500);
                digitalWrite(8, HIGH);
                delay(500);
                digitalWrite(8, LOW);



                reassign();

                Q4 = random(0, 4);  //Selects random 2nd light to appear
                delay(500);
                digitalWrite(selections[Q1], HIGH);
                delay(250);
                digitalWrite(selections[Q1], LOW);
                delay(500);
                digitalWrite(selections[Q2], HIGH);
                delay(250);
                digitalWrite(selections[Q2], LOW);
                delay(500);
                digitalWrite(selections[Q3], HIGH);
                delay(250);
                digitalWrite(selections[Q3], LOW);
                delay(500);
                digitalWrite(selections[Q4], HIGH);
                delay(250);
                digitalWrite(selections[Q4], LOW);

                detect();

                if (buttonStates[Q1] == HIGH) {

                  reassign();
                  delay(500);
                  detect();

                  if (buttonStates[Q2] == HIGH) {

                    reassign();
                    delay(500);
                    detect();

                    if (buttonStates[Q3] == HIGH) {

                      reassign();
                      delay(500);
                      detect();

                      if (buttonStates[Q4] == HIGH) {

                        delay(500);
                        digitalWrite(8, HIGH);
                        delay(500);
                        digitalWrite(8, LOW);



                        reassign();

                        Q5 = random(0, 4);  //Selects random 2nd light to appear
                        delay(500);
                        digitalWrite(selections[Q1], HIGH);
                        delay(250);
                        digitalWrite(selections[Q1], LOW);
                        delay(500);
                        digitalWrite(selections[Q2], HIGH);
                        delay(250);
                        digitalWrite(selections[Q2], LOW);
                        delay(500);
                        digitalWrite(selections[Q3], HIGH);
                        delay(250);
                        digitalWrite(selections[Q3], LOW);
                        delay(500);
                        digitalWrite(selections[Q4], HIGH);
                        delay(250);
                        digitalWrite(selections[Q4], LOW);
                        delay(500);
                        digitalWrite(selections[Q5], HIGH);
                        delay(250);
                        digitalWrite(selections[Q5], LOW);

                        detect();


                        if (buttonStates[Q1] == HIGH) {

                          reassign();
                          delay(500);
                          detect();

                          if (buttonStates[Q2] == HIGH) {

                            reassign();
                            delay(500);
                            detect();

                            if (buttonStates[Q3] == HIGH) {

                              reassign();
                              delay(500);
                              detect();

                              if (buttonStates[Q4] == HIGH) {

                                reassign();
                                delay(500);
                                detect();

                                if (buttonStates[Q5] == HIGH) {
                                  delay(500);
                                  digitalWrite(8, HIGH);
                                  delay(250);
                                  digitalWrite(8, LOW);
                                  delay(250);
                                  digitalWrite(8, HIGH);
                                  delay(250);
                                  digitalWrite(8, LOW);
                                  delay(250);
                                  digitalWrite(8, HIGH);
                                  delay(3000);
                                  digitalWrite(8, LOW);
                                } else {
                                  finishSequence();
                                }
                              } else {
                                finishSequence();
                              }
                            } else {
                              finishSequence();
                            }
                          } else {
                            finishSequence();
                          }
                        } else {
                          finishSequence();
                        }
                      } else {
                        finishSequence();
                      }
                    } else {
                      finishSequence();
                    }
                  } else {
                    finishSequence();
                  }
                } else {
                  finishSequence();
                }
              } else {
                finishSequence();
              }
            } else {
              finishSequence();
            }
          } else {
            finishSequence();
          }
        } else {
          finishSequence();
        }
      } else {  //If the correct button has not been pressed, it blinks the red light and the current trials ends.
        finishSequence();
      }
    } else {
      finishSequence();
    }
  }
}
