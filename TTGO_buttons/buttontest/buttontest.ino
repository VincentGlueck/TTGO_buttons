#include "TtgoButton.h"

uint16_t globalCnt;

class ButtonCallback : public TtgoButton::ButtonCallback {
public:
  void onButtonPressed(const int &result) override {
    switch (result) {
      case RESULT_CLICK: Serial.println("click"); break;
      case RESULT_LONG_CLICK: Serial.println("long click"); break;
      case RESULT_DOUBLE_CLICK: Serial.println("double click"); break;
    }
  }
};

ButtonCallback ttgoCallback;
TtgoButton btn0(BTN0, &ttgoCallback);
TtgoButton btn1(BTN1, &ttgoCallback);

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(1);
}

void loop() {
  btn0.listen();
  btn1.listen();
  delay(1);
}
