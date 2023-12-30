#include "basic_exp.h"

using namespace daisy;

static BasicExp hw;

bool  led1, led2, led3, led4, led5, led6, led7, led8;
float brightness1, brightness2;

struct RGB
{
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
    for(size_t i = 0; i < 3; i++)
    {
        BlinkLEDColor(rgb, delay);
        BlinkLEDColor({0, 0, 0}, delay);
    }
}

int main()
{
    hw.Init();
    hw.SetAudioBlockSize(4);
    hw.StartAdc();

    brightness1 = brightness2 = 1.0f;
    led1 = led2 = led3 = led4 = led5 = led6 = led7 = led8 = false;

    BlinkLED({1, 1, 1});

    while(1)
    {
        System::Delay(5);
        hw.ProcessAnalogControls();
        hw.ProcessDigitalControls();

        brightness1 = hw.knob3.Process();
        brightness2 = hw.knob4.Process();

        if(hw.button1.RisingEdge())
            led1 = !led1;

        if(hw.button2.RisingEdge())
            led2 = !led2;

        if(hw.button3.RisingEdge())
            led3 = !led3;

        if(hw.button4.RisingEdge())
            led4 = !led4;

        if(hw.button5.RisingEdge())
            led5 = !led5;

        if(hw.button6.RisingEdge())
            led6 = !led6;

        if(hw.button7.RisingEdge())
            led7 = !led7;

        if(hw.button8.RisingEdge())
            led8 = !led8;


        if(led1)
        {
            hw.led1.Set(brightness1, 0, 0);
            hw.UpdateLeds();
        }
        else if(led2)
        {
            hw.led1.Set(0, brightness1, 0);
            hw.UpdateLeds();
        }
        else if(led3)
        {
            hw.led1.Set(0, 0, brightness1);
            hw.UpdateLeds();
        }
        else if(led4)
        {
            hw.led1.Set(brightness1, brightness1, 0);
            hw.UpdateLeds();
        }
        else if(led5)
        {
            hw.led2.Set(brightness2, 0, 0);
            hw.UpdateLeds();
        }
        else if(led6)
        {
            hw.led2.Set(0, brightness2, 0);
            hw.UpdateLeds();
        }
        else if(led7)
        {
            hw.led2.Set(0, 0, brightness2);
            hw.UpdateLeds();
        }
        else if(led8)
        {
            hw.led2.Set(brightness1, brightness1, 0);
            hw.UpdateLeds();
        }
        

        else
        {
            hw.led1.Set(0, 0, 0);
            hw.led2.Set(0, 0, 0);
            hw.UpdateLeds();
        }
    }
}