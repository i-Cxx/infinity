# FreeRTOSConfig.h als INTERFACE Lib (Header-only)
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config INTERFACE
    ${CMAKE_SOURCE_DIR}/include
)

# Webserver Subdirectory einbinden (erst hier, weil in src/)
add_subdirectory(webserver)

# Haupt-Executable bauen
add_executable(infinity_rts
    main.c
)

# Benötigte Libraries linken
target_link_libraries(infinity_rts
    pico_stdlib
    hardware_i2c
    hardware_gpio

    freertos_kernel
    freertos_config

    blink_lib
    lcd1602_lib
    ssd1306_lib

    webserver     

    lwipcore
    lwipallapps
    tinyusb_device
)

# Compiler Optionen
target_compile_options(infinity_rts PRIVATE -Wall -Wextra -O2)

# UART für printf aktivieren (USB stdio deaktiviert)
pico_enable_stdio_uart(infinity_rts 1)
pico_enable_stdio_usb(infinity_rts 0)

# Erzeuge ELF, BIN, HEX etc.
pico_add_extra_outputs(infinity_rts)
