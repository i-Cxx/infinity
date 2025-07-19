#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "config.h"

extern void start_usb_rndis_task(void);
extern void start_webserver_task(void);
extern void start_blink_task(void);
extern void start_ssd1306_task(void);
extern void start_lcd1602_task(void);

int main() {
    stdio_init_all();

    // Tasks starten
    start_blink_task();
    start_ssd1306_task();
    start_lcd1602_task();
    start_usb_rndis_task();
    start_webserver_task();

    // FreeRTOS Scheduler starten
    vTaskStartScheduler();

    while (1) {
        tight_loop_contents();
    }

    return 0;
}
