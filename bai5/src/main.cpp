#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led1(LED_PIN, LED_ACT);
LED led2(5, LED_ACT);
LED *currentLED = &led1;  // LED đang được điều khiển, mặc định là LED1

void btnPush();
void btnDoubleClick();
void btnLongPress();
OneButton button(22, !BTN_ACT);

void setup()
{
    button.attachClick(btnPush);            // ấn 1 lần để bật/tắt LED
    button.attachDoubleClick(btnDoubleClick); // ấn 2 lần để chuyển chế độ điều khiển giữa 2 LED
    button.attachLongPressStart(btnLongPress); // Giữ nút để nhấp nháy LED
    led1.off();
    led2.off();   
}

void loop()
{
    led1.loop();
    led2.loop();
    button.tick();
}

void btnDoubleClick()
{
    // Chuyển chế độ điều khiển giữa LED1 và LED2
    if (currentLED == &led1)
        currentLED = &led2;
    else
        currentLED = &led1;
}

void btnPush()
{
    currentLED->flip(); // Bật/tắt LED hiện tại
}

void btnLongPress()
{
    currentLED->blink(200); // Nhấp nháy LED hiện tại với chu kỳ 200ms
}
