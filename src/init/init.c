// init.c
#include "init.h"

#define I2C_SDA 14 // <- Use os pinos reais do seu circuito
#define I2C_SCL 15

ssd1306_t display;

void initDisplayI2C() {
    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

void initializeSystem(void) {
    stdio_init_all();
    sleep_ms(1000);

    printf("Configurando I2C do OLED...\n");
    initDisplayI2C();

    mpu6050_init();

    printf("Iniciando SSD1306...\n");
    if (!ssd1306_init(&display, 128, 64, 0x3C, i2c1)) {
        printf("Erro ao inicializar SSD1306!\n");
        while(1);
    }

    servo_init();

    printf("Tela limpa.\n");
}
