# Runtime for stm32f215 platform running along ChipWhisprer

Creates runtime environment that allows running apps on ChipWhisprer with STM32F215 UFO board. One needs to build the solution, link resulting static library with the application and push to the board. Solution contains implementation of `printf` that sends data over UART to the terminal.

## Building

```
cmake --preset stm32f215_cw
cmake --build --preset stm32f215_cw
cpack --preset stm32f215_cw
```

Libraries will be compiled and placed in the ``build/pack`` directory.

## Flash to ChipWhisprer

Flash the binary

```
pyocd flash out/stm32f215_cw/bin/hello.bin -t STM32F215RETx
```


### Enable UART output

```
python tools/cw_uart_init.py
```
