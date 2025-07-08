#include <stdio.h>
#include "pico/stdlib.h"
#include "ssd1306.h"
#include "init.h"
#include "servo.h"

int16_t ax, ay, az;

void txt_display(const char *txt)
{
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, 0, 0, 1, txt);
    ssd1306_show(&display);
}

void inclination_display(float inclination)
{
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "Inclinacao: %.2f", inclination);
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, 0, 0, 1, buffer);

    if (inclination < 0){
        inclination = -inclination;
        int position1 = (int)(inclination) + 10;
        int position2 = (int)(inclination) - 10;
        if (position1 > 64){
            position1 = 64;
        }
        if (position2 > 64){
            position2 = 64;
        }
        ssd1306_draw_line(&display, 10, position1, 50, 32);
        ssd1306_draw_line(&display, 50, 32, 100, 32);
    }
    else{
        int position1 = (int)(inclination) + 10;
        int position2 = (int)(inclination) - 10;
        ssd1306_draw_line(&display, 10, 32, 50, 32);
        ssd1306_draw_line(&display, 50, 32, 100, position1);
    }
    ssd1306_show(&display);
}

int main()
{
    initializeSystem();
    initDisplayI2C();


    while (true)
    {
        mpu6050_read_raw(&ax, &ay, &az);
        float inclination = mpu6050_get_inclination(ax, ay, az);
        printf("Inclination: %.2f\n", inclination);
        int angle = (int)(inclination * 2); 
        if (angle < 0){
            angle = 0;
        }
        else{
            angle = 180;
        }
        servo_set_angle(angle);
        sleep_ms(100);
        inclination_display(inclination);
        sleep_ms(100);
}
} 
