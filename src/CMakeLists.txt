add_executable(pico_freertos_webserver
    main.c
    led_task.c
    ssd1306_task.c
    lcd1602_task.c
    usb_rndis_task.c
    webserver_task.c
)

target_link_libraries(pico_freertos_webserver
    pico_stdlib
    FreeRTOS-Kernel
    lwip
    tinyusb
    ssd1306
    lcd1602
)
pico_add_extra_outputs(pico_freertos_webserver)
