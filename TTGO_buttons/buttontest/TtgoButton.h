#ifndef _TTGOBUTTON_H
#define _TTGOBUTTON_H

#define BTN0 0
#define BTN1 35

#define RESULT_CLICK 0
#define RESULT_LONG_CLICK 1
#define RESULT_DOUBLE_CLICK 2
#define RESULT_NONE 0xff

#define SKIP_GLITTER 10
#define LONG_REPEAT_MS 100
#define CLICK_MS 100
#define CLICK_LONG_MS 500
#define DOUBLE_CLICK_MS 50

class TtgoButton {
public:

  class ButtonCallback {
    public:
      virtual void onButtonPressed(const int& result);
  };

  TtgoButton(int _pin = BTN0);
  TtgoButton(int _pin, ButtonCallback* _callback);
  void listen();
  void registerCallback(ButtonCallback* _callback);
  void setPressedOnHigh(bool high = false); // if for some reason Pin level HIGH means "pressed"

  
  

private:
  ButtonCallback* callback;
  bool callbackDone;
  int pinLevelPressed;
  int pin;
  long lastLowMillis;
  int result;
  int lastHighLow;
  long lastHighLowChange;
  bool preventSingleClick;
  bool preventDoubleClick;
  bool waitForSingleClick;
  long nextRepeatLongMillis;
  long resultNotBeforeMillis;
  long lastDoubleLowMillis;
  int doubleClickCount;
  long allowSingleClickMillis;
};

#endif