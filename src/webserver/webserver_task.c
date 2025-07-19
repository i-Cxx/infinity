#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/gpio.h"

#include "tusb_lwip_glue.h"
#include "lwip/apps/httpd.h"
#include "webserver.h"

#define LED_PIN 25

static const char *cgi_toggle_led(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
    gpio_put(LED_PIN, !gpio_get(LED_PIN));
    return "/index.html";
}

static const char *cgi_reset_usb_boot(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
    reset_usb_boot(0, 0);
    return "/index.html";
}

static const tCGI cgi_handlers[] = {
    { "/toggle_led", cgi_toggle_led },
    { "/reset_usb_boot", cgi_reset_usb_boot }
};

void webserver_task(void *pvParameters) {
    // Init Netzwerk
    init_lwip();
    wait_for_netif_is_up();
    dhcpd_init();

    // Init HTTP Server
    httpd_init();
    http_set_cgi_handlers(cgi_handlers, LWIP_ARRAYSIZE(cgi_handlers));

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        tud_task();
        service_traffic();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void start_webserver_task(void) {
    xTaskCreate(webserver_task, "Webserver", 1024, NULL, tskIDLE_PRIORITY+3, NULL);
}
