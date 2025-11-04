add_executable(adc
        main.c
)

pico_enable_stdio_uart(adc ENABLE)
pico_enable_stdio_usb(adc DISABLE)

target_link_libraries(adc pico_stdlib

hardware_adc
freertos


)
pico_add_extra_outputs(adc)
