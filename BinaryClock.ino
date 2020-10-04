#define BIT(n,i) (n>>i&1)
long now = millis();
int second = now / 1000;
int minute = second / 60;
int hour = minute / 60;

int sec_1_digit;
int sec_2_digit;
int min_1_digit;
int min_2_digit;
int hour_1_digit;
int hour_2_digit;
long millis_double_press = 0;
long mills_button_delay = 0;
int mode = 0;
int state_3_current = 0;
int speed_mod = 1;
long millis_add = 0;

boolean led_sec = false;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
}

void set_LED(int pin, int value) {
  if (value == 0) {
    digitalWrite(pin, LOW);
  } else {
    digitalWrite(pin, HIGH);
  }
}

void refresh_time() {
  second = (now / 1000) % 60;
  minute = ((now / 60) / 1000) % 60;
  hour = (((minute / 60) / 60) / 1000) % 24;
  sec_1_digit = second % 10;
  sec_2_digit = (second - sec_1_digit) / 10;
  min_1_digit = minute % 10;
  min_2_digit = (minute - min_1_digit) / 10;
  hour_1_digit = hour % 10;
  hour_2_digit = (hour - hour_1_digit) / 10;


  Serial.println(second);
  Serial.println(minute);
  Serial.println(hour);
  
  // sec blink
  set_LED(13, BIT(sec_1_digit, 0));
}

void dark() {
  // x0-minutes
  set_LED(5, LOW);
  set_LED(4, LOW);
  set_LED(3, LOW);
  set_LED(2, LOW);

  // 0x-minutes
  set_LED(9, LOW);
  set_LED(8, LOW);
  set_LED(7, LOW);
  set_LED(6, LOW);

  // x0 seconds
  set_LED(A3, LOW);
  set_LED(A2, LOW);
  set_LED(A1, LOW);
  set_LED(A0, LOW);

  // 0x seconds
  set_LED(A4, LOW);
  set_LED(A5, LOW);
  set_LED(10, LOW);
  set_LED(12, LOW);
}
void tickMMSS() {

  if (hour < 10) Serial.print("0");
  Serial.print(hour);
  Serial.print(":");
  if (minute < 10) Serial.print("0");
  Serial.print(minute);
  Serial.print(":");
  if (second < 10) Serial.print("0");
  Serial.print(second);

  Serial.print("  ");
  Serial.print(analogRead(A7));
  Serial.print("  ");
  Serial.print(analogRead(A6));

  Serial.println();

  // x0-minutes
  set_LED(5, BIT(min_2_digit, 0));
  set_LED(4, BIT(min_2_digit, 1));
  set_LED(3, BIT(min_2_digit, 2));
  set_LED(2, BIT(min_2_digit, 3));

  // 0x-minutes
  set_LED(9, BIT(min_1_digit, 0));
  set_LED(8, BIT(min_1_digit, 1));
  set_LED(7, BIT(min_1_digit, 2));
  set_LED(6, BIT(min_1_digit, 3));

  // x0 seconds
  set_LED(A3, BIT(sec_2_digit, 0));
  set_LED(A2, BIT(sec_2_digit, 1));
  set_LED(A1, BIT(sec_2_digit, 2));
  set_LED(A0, BIT(sec_2_digit, 3));

  // 0x seconds
  set_LED(A4, BIT(sec_1_digit, 0));
  set_LED(A5, BIT(sec_1_digit, 1));
  set_LED(10, BIT(sec_1_digit, 2));
  set_LED(12, BIT(sec_1_digit, 3));
}

void tickHHMM() {

  if (hour < 10) Serial.print("0");
  Serial.print(hour);
  Serial.print(":");
  if (minute < 10) Serial.print("0");
  Serial.print(minute);
  Serial.print(":");
  if (second < 10) Serial.print("0");
  Serial.print(second);

  Serial.print("  ");
  Serial.print(analogRead(A7));
  Serial.print("  ");
  Serial.print(analogRead(A6));

  Serial.println();

  // x0-minutes
  set_LED(5, BIT(hour_2_digit, 0));
  set_LED(4, BIT(hour_2_digit, 1));
  set_LED(3, BIT(hour_2_digit, 2));
  set_LED(2, BIT(hour_2_digit, 3));

  // 0x-minutes
  set_LED(9, BIT(hour_1_digit, 0));
  set_LED(8, BIT(hour_1_digit, 1));
  set_LED(7, BIT(hour_1_digit, 2));
  set_LED(6, BIT(hour_1_digit, 3));

  // x0 seconds
  set_LED(A3, BIT(min_2_digit, 0));
  set_LED(A2, BIT(min_2_digit, 1));
  set_LED(A1, BIT(min_2_digit, 2));
  set_LED(A0, BIT(min_2_digit, 3));

  // 0x seconds
  set_LED(A4, BIT(min_1_digit, 0));
  set_LED(A5, BIT(min_1_digit, 1));
  set_LED(10, BIT(min_1_digit, 2));
  set_LED(12, BIT(min_1_digit, 3));
}

void tick_state_3() {
  state_3_current++;
  if (state_3_current == 4) state_3_current = 0;

  if (state_3_current == 0) {
    // x0-minutes
    dark();
    set_LED(5, HIGH);
    set_LED(4, HIGH);
    set_LED(3, HIGH);
    set_LED(2, HIGH);
  } else if (state_3_current == 1) {
    dark();
    set_LED(9, HIGH);
    set_LED(8, HIGH);
    set_LED(7, HIGH);
    set_LED(6, HIGH);
  } else if (state_3_current == 2) {
    dark();
    set_LED(A3, HIGH);
    set_LED(A2, HIGH);
    set_LED(A1, HIGH);
    set_LED(A0, HIGH);
  } else if (state_3_current == 3) {
    dark();
    set_LED(A4, HIGH);
    set_LED(A5, HIGH);
    set_LED(10, HIGH);
    set_LED(12, HIGH);
  }
}
void loop() {
  now = (millis()+millis_add) * speed_mod;

  if (now / 1000 % 60 == second) {
    // do nothing
  } else {
    refresh_time();

    if ((analogRead(A6) == 0) && (analogRead(A7) == 0)) {

      if (millis_double_press == 0) {
        millis_double_press = millis();
        Serial.println("Test countdown started");
        dark();
      } else if (millis() - millis_double_press > 2000) {
        Serial.println("test mode");
        millis_double_press = millis();
        mode++;
        if (mode == 4) mode = 0;
        Serial.print("Mode: ");
        Serial.println(mode);
      } else {
        if (mode == 0) {
          // x0-minutes
          dark();
          set_LED(5, HIGH);
          set_LED(4, HIGH);
          set_LED(3, HIGH);
          set_LED(2, HIGH);
        } else if (mode == 1) {
          dark();
          set_LED(9, HIGH);
          set_LED(8, HIGH);
          set_LED(7, HIGH);
          set_LED(6, HIGH);
        } else if (mode == 2) {
          dark();
          set_LED(A3, HIGH);
          set_LED(A2, HIGH);
          set_LED(A1, HIGH);
          set_LED(A0, HIGH);
        } else if (mode == 3) {
          dark();
          set_LED(A4, HIGH);
          set_LED(A5, HIGH);
          set_LED(10, HIGH);
          set_LED(12, HIGH);
        }
      }
    } else if (analogRead(A6) == 0) {
      if (mills_button_delay == 0) {
        mills_button_delay = millis();
        Serial.println("Timeset started");
      } else if (millis() - mills_button_delay > 1000) {
        mills_button_delay = millis();
        Serial.println("HH+1");
        millis_add = millis_add + (1000 * 60 * 60);
      }
      tickHHMM;
    } else if (analogRead(A7) == 0) {
      Serial.println("MM");
      millis_add = millis_add + (1000 * 60);
    } else {
      millis_double_press = 0;
      // 0 clock MM:SS
      // 1 clock HH:MM
      // 2 clock speeeeeed
      // 3 full test
      if (mode == 0) {
        tickMMSS();
        speed_mod = 1;
      } else if (mode == 1) {
        tickHHMM();
        speed_mod = 1;
        Serial.println("Mode 1");
      } else if (mode == 2) {
        tickMMSS();
        speed_mod = 200;
        Serial.println("Mode 2");
      } else if (mode == 3) {
        speed_mod = 10;
        Serial.println("Mode 3");
        tick_state_3();
      }
    }

  }

}
