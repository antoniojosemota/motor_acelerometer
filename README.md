# 📡 Projeto: Controle de Servo com MPU6050 e Display OLED

Este projeto implementa um sistema embarcado utilizando o **Raspberry Pi Pico** que lê a inclinação de um objeto usando o sensor **MPU6050**, exibe essa informação em um **display OLED SSD1306** via I2C e ajusta um **servo motor** com base na inclinação medida.

---

## 🧱 Estrutura do Projeto
``` bash
├── src/
│ ├── init/ # Inicialização dos periféricos e pinos
│ ├── mpu6050/ # Biblioteca e funções para o sensor MPU6050
│ ├── pico-ssd1306 # Driver para display OLED SSD1306 via I2C
│ ├── servo/ # Controle de servo motor com PWM
│ └── motor_acel.c # Código principal do sistema
├── .vscode/ # Configurações do Visual Studio Code
├── CMakeLists.txt # Build system (CMake)
├── pico_sdk_import.cmake # Inclusão do SDK do Raspberry Pi Pico
├── .gitignore # Arquivos ignorados pelo Git
└── README.md # Documentação do projeto
```


---

## 🧠 Descrição

O programa realiza as seguintes etapas:

1. Inicializa periféricos (I2C, MPU6050, Display, PWM).
2. Lê os valores de aceleração bruta (`ax`, `ay`, `az`) do sensor MPU6050.
3. Calcula a inclinação com base nos eixos.
4. Controla um servo motor, mudando seu ângulo com base na inclinação detectada.
5. Exibe o valor da inclinação e um gráfico visual no display OLED SSD1306.

---

## 🚀 Componentes Utilizados

- [x] Raspberry Pi Pico
- [x] MPU6050 (Acelerômetro e Giroscópio)
- [x] Display OLED SSD1306 (I2C)
- [x] Servo Motor (SG90 ou similar)

---

## 🔧 Funções Principais

### `txt_display(const char *txt)`
Exibe uma string simples no display OLED.

### `inclination_display(float inclination)`
Mostra a inclinação calculada e desenha uma linha representando o valor inclinado no display OLED.

### `main()`
Função principal que realiza a leitura do sensor, calcula a inclinação, controla o servo e atualiza o display.

---

## 📈 Exemplo de Saída Serial

```txt
Inclination: 12.47
Inclination: -8.23
Inclination: 0.00
```

## 👨‍💻 Autor
Antonio José Mota Ferreira Brandão
Projeto para fins educacionais e experimentais.
