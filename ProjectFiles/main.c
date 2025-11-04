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
        vTaskDelay(250);
        gpio_put(LED_PIN, 0);
        vTaskDelay(250);
    }
}


void adc_read_task()
{

     // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    adc_gpio_init(27);
    adc_gpio_init(28);
    // Select ADC input 0 (GPIO26)
    
    while (true){

        adc_select_input(0);
        int adc_x = adc_read();

        adc_select_input(1);
        int adc_y = adc_read();

        adc_select_input(2);
        int adc_z = adc_read();


        printf("V %d,%d,%d\r\n",adc_x,adc_y,adc_z);
        vTaskDelay(100);

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
