int val1 = 0, val2 = 0, val3 = 0, a, k = 1, debounce = 0, previous = HIGH, l;

bool toggle1 = false, toggle2 = false, toggle3 = false, in;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //b=analogRead(A4);

  in = false;

  switch (k) {

    case 1:
      blink(3);
      do {
        a = analogRead(A5);
        if (a == previous)
          debounce++;
        else debounce = 0;

        if (debounce == 5) {
          l = analogRead(A4);
          if (l < 9 && !toggle1) {
            if (val1 != 255)
              val1 = val1 + 1;
            else
              blink(9);

            delay(7);
            in = true;
          }

          if (l < 9 && toggle1) {
            if (val1 != 0)
              val1 = val1 - 1;
            else
              blink(10);

            delay(7);
            in = true;
          }

          if (in && l > 12) {
            in = false;
            toggle1 = !toggle1;
          }

          analogWrite(3, val1);
          analogWrite(6, val3);
          analogWrite(5, val2);
        }
        previous = a;
      } while (a < 650 || a > 700);

      analogWrite(3, val1);
      analogWrite(6, val3);
      analogWrite(5, val2);
      k = 2;
      break;


    case 2:
      blink(5);
      do {
        a = analogRead(A5);
        if (a == previous)
          debounce++;
        else
          debounce = 0;

        if (debounce == 5) {
          l = analogRead(A4);
          if (l < 9 && !toggle2) {
            if (val2 != 255)
              val2 = val2 + 1;
            else
              blink(9);
            delay(7);
            in = true;
          }

          if (l < 9 && toggle2) {
            if (val2 != 0)
              val2 = val2 - 1;
            else
              blink(10);
            delay(7);
            in = true;
          }

          if (in && l > 12) {
            in = false;
            toggle2 = !toggle2;
          }

          analogWrite(5, val2);
          analogWrite(3, val1);
          analogWrite(6, val3);
        }
        previous = a;
      } while (a < 650 || a > 700);

      analogWrite(3, val1);
      analogWrite(6, val3);
      analogWrite(5, val2);
      k = 3;
      break;


    case 3:
      blink(6);
      do {
        a = analogRead(A5);
        if (a == previous)
          debounce++;
        else
          debounce = 0;

        if (debounce == 5) {
          l = analogRead(A4);
          if (l < 9 && !toggle3) {
            if (val3 != 255)
              val3 = val3 + 1;
            else
              blink(9);

            delay(7);
            in = true;
          }

          if (l < 9 && toggle3) {
            if (val3 != 0)
              val3 = val3 - 1;
            else
              blink(10);

            delay(7);
            in = true;
          }

          if (in && l > 12) {
            in = false;
            toggle3 = !toggle3;
          }

          analogWrite(6, val3);
          analogWrite(3, val1);
          analogWrite(5, val2);
        }
        previous = a;
      } while (a < 650 || a > 700);

      analogWrite(3, val1);
      analogWrite(6, val3);
      analogWrite(5, val2);
      k = 1;
      break;
  }
}


void blink(int i) {

  for (int y = 0; y < 2; y++) {
    digitalWrite(i, HIGH);
    delay(250);
    digitalWrite(i, LOW);
    delay(250);
  }

}
