#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/adc.h"


#define LED_PIN 0


void led_task()
{   

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(500);
        gpio_put(LED_PIN, 0);
        vTaskDelay(5001);
    }
}


void adc_read_task()
{
    while (true){

        printf("Hello World\r\n");
        vTaskDelay(500);

    }
}

int main()
{
    stdio_init_all();

    adc_init();

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    xTaskCreate(adc_read_task, "LED_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}
