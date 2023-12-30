#include "basic_exp.h"

using namespace daisy;

static BasicExp hw;

bool led1, led2, led3, led4, led5, led6, led7, led8;

struct RGB {
  float R, G, B;
};

void BlinkLEDColor(RGB rgb, int delay)
{
  hw.led1.Set(rgb.R, rgb.G, rgb.B);
  hw.UpdateLeds();
  System::Delay(delay);
}

void BlinkLED(RGB rgb, int delay = 150)
{
  for (size_t i = 0; i < 3; i++) {
    BlinkLEDColor(rgb, delay);
    BlinkLEDColor({0, 0, 0}, delay);
  }
}

int main()
{
  hw.Init();
  hw.SetAudioBlockSize(4);
  hw.StartAdc();

  led1 = led2 = led3 = led4 = led5 = led6 = led7 = led8 = false;

  // initialize the logger
  hw.seed.StartLog(false);

  BlinkLED({1, 1, 1});

  while (1) {
    System::Delay(10);
    hw.ProcessAnalogControls();
    hw.ProcessDigitalControls();

    float knob1 = hw.knob1.Process();
    float knob2 = hw.knob2.Process();
    float knob3 = hw.knob3.Process();
    float knob4 = hw.knob4.Process();

    if (hw.button1.RisingEdge())
      led1 = !led1;

    if (hw.button2.RisingEdge())
      led2 = !led2;

    if (hw.button3.RisingEdge())
      led3 = !led3;

    if (hw.button4.RisingEdge())
      led4 = !led4;

    if (hw.button5.RisingEdge())
      led5 = !led5;

    if (hw.button6.RisingEdge())
      led6 = !led6;

    if (hw.button7.RisingEdge())
      led7 = !led7;

    if (hw.button8.RisingEdge())
      led8 = !led8;

    hw.seed.PrintLine("k1: %f k2: %f k3: %f k4: %f", knob1, knob2, knob3, knob4);
    hw.seed.PrintLine("sw1: %d sw2: %d sw3: %d sw4: %d sw5: %d sw6: %d sw7: %d sw8: %d ", led1, led2, led3, led4, led5, led6, led7, led8);
  }
}