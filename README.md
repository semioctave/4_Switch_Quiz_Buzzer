# 4_Switch_Quiz_Buzzer

___
## Introduction & Overview

Designing Traffic 4-Switch Quiz Buzzer system using <b>TM4C123 Tiva C Series LAUNCHPAD</b> an<b> ARM Cortex M4 based MCU</b>
from Scratch in C using Industrial Tool <b> ARM Keil </b>. ARM Cortex M4 Processor is used in modern Embedded Devices like
fitness bands & other Automative applications. <b>ARM Cortex M series</b> processors are of great importance to modern day Embedded industry. 

___

## Hardware Components used

1. TM4C123 Tiva C Series Launchpad.
2. Resistors.
3. Red , Yellow , Green LEDs
4. Switches
5. Peizo Buzzer

___

## Software tool Used

I used ARM Keil IDE to write code , compile & Burn the code.
One may use other Embedded Designing Tools like <b>IAR Embedded Benchmark</b> or <b>TI Code Compose Studio</b>

### Links for downloading the Tools

1. [ARM Keil](http://www2.keil.com/mdk5/)
2. [IAR Embedded Benchmark](https://www.iar.com/iar-embedded-workbench/)
3. [TI Code Compose Studio](http://www.ti.com/tool/CCSTUDIO)

___

## Working   

Circuit consists of 4 Switches and corresponding to each Switch we have a LED bulb and a Piezo Buzzer.
Whenever, Multiple Switches are pressed the LED corresponding to the Switch which pressed first Start to flash Alog with the Peizo Buzzer & After some time the flashing Stablizes and Buzzer Switches OFF.

Accuracy of Embedded device designed is in Nano secs so it is not possible for humman to presses Switch at exactly same time precise upto nano secs

___

## Deployment of Machine

First of all Make a new project and add <b>Startup.s </b>file to your project or the startupfile provided by your tool for yours praticular processor Model. Now add <b>main.c</b> file , main.c file consists of main C code of your Machine now <b>compile and debug</b> your
code using your Embedded Designing Tool. After Succesful Debugging Burn the code onto your Machine and your Prototype is ready to use
