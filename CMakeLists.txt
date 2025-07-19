cmake_minimum_required(VERSION 3.13)

# Projektname & Sprache
project(infinity_rts_core C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Pico SDK & Extras importieren
include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)

# FreeRTOS, LwIP, TinyUSB einbinden
add_subdirectory(external/FreeRTOS)
add_subdirectory(external/tinyusb)
add_subdirectory(external/lwip)

# Eigene Bibliotheken einbinden
add_subdirectory(lib/blink)
add_subdirectory(lib/lcd_1602_i2c)
add_subdirectory(lib/ssd1306_i2c)

# Hauptanwendung
add_subdirectory(src)

