#include "FreeRTOS.h"
#include "task.h"
#include "lwip/api.h"
#include "lwip/apps/httpd.h"

void webserver_task(void *pvParameters) {
    httpd_init();
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void start_webserver_task(void) {
    xTaskCreate(webserver_task, "Webserver", 512, NULL, tskIDLE_PRIORITY+1, NULL);
}
