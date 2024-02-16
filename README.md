# TTGO_buttons

_TTGO buttons made (quite) easy._

__Supports__:
* single press/click
* long press/click
* double press/click

![button_raw](https://github.com/VincentGlueck/TTGO_buttons/assets/139572548/d15c4452-1c30-4bdd-b33b-c120470eabb4)

__Basic usage__

``#include "TtgoButton.h"``

Write a basic callback

```
class ButtonCallback : public TtgoButton::ButtonCallback {
public:
  void onButtonPressed(const int& btnPin, const int &result) override {
    Serial.print("pin " + String(btnPin) + " :: ");
    switch (result) {
      case RESULT_CLICK: Serial.println("click"); break;
      case RESULT_LONG_CLICK: Serial.println("long click"); break;
      case RESULT_DOUBLE_CLICK: Serial.println("double click"); break;
    }
  }
};
```

Use button
```
ButtonCallback ttgoCallback;
TtgoButton btn0(BTN0, &ttgoCallback);
```

Test it
```
void setup() {
  Serial.begin(9600);
}

void loop() {
  btn0.Listen();
  delay(1);
}
```

__Done__
