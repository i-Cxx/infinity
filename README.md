# Infitiy Pico Core OS



Struktur:


```md

pico_freertos_webserver/
├── CMakeLists.txt
├── cmake/
│   └── pico_sdk_import.cmake      # falls nötig
├── include/                       # Public headers
│   └── config.h
├── src/                           # App-spezifische Tasks
│   ├── main.c
│   ├── led_task.c
│   ├── ssd1306_task.c
│   ├── lcd1602_task.c
│   ├── usb_rndis_task.c
│   └── webserver_task.c
├── lib/                           # Eigene statische Libraries
│   ├── lcd1602/
│   │   ├── CMakeLists.txt
│   │   ├── lcd1602.c
│   │   └── lcd1602.h
│   └── ssd1306/
│       ├── CMakeLists.txt
│       ├── ssd1306.c
│       └── ssd1306.h
├── external/                      # Third-party
│   ├── FreeRTOS/                  # Port für RP2040
│   ├── lwip/
│   └── tinyusb/
└── README.md

```# infinity
