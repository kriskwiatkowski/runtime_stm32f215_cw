import chipwhisperer as cw

scope = cw.scope()
scope.default_setup()

# Optional but recommended if you will use a terminal program on /dev/ttyACM*:
# make CW ignore settings changes coming from the CDC client (PuTTY/picocom/etc).
# (Docs mention this typically exists as scope.io.cdc_settings.)
scope.io.cdc_settings = 1  # "ignore CDC USART setting changes" mode on many firmwares

# Create a serial target object just to configure the USART bridge baud
target = cw.target(scope, cw.targets.SimpleSerial)
target.baud = 230400  # set this to whatever your UART1 is using
target.flush()

print(scope.get_serial_ports())