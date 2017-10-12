# Ring ABL

## Purpose

A Wifi ringbell. 2 parts projects :

 * emitter: detects when a person wants to ring (with a photoresistor)
 * receptor: perform an action to notify

It is used for the ABL association to notify when a person arrives and we need to open the door.


## Electronics

### Emittor

Green Pin (photoresistance) on pin A0
Red Pin => VCC
Black pin => GND

Leds:

* pin_led_no_wifi => pin 4 (D2 on the board)
* pin_led_message_send => pin 5 (D1 on the board)


### Receptor

Neopixel on pin D2 (gpio 4) of the NodeMCU


## Issues while flashing the esp

https://github.com/espressif/esptool/issues/213

```
This is a bug we should fix, but I think you can un-brick your module right now as well:

    Disconnect the USB cable, depowering the NodeMCU board.
    Hold down the FLASH button while keeping the board unpowered.
    Plug in USB power while continuing to hold down the FLASH button.
    Run esptool.py while continuing to hold FLASH.
    Once esptool.py starts the operation, you can release FLASH.

Holding FLASH down from initial power-on keeps the ESP8266 in bootloader mode, so it never runs the program which sets the RTC timer.
```