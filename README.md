# Temperature-Controlled-DC-Fan
Temperature Controlled DC fan built with an Arduino Nano, LM358 op-amp, and a custom KiCad PC

An automated cooling system built with an Arduino Nano, an LM358 op-amp, and an NTC thermistor. This project was developed during my 2nd semester of BTech in Electronics Engineering.

# Overview
This hardware project bridges analog sensing and digital control. An NTC thermistor tracks the ambient temperature, and an LM358 op-amp acts as an open-loop comparator to trigger the cooling fan when the temperature exceeds a precise 40°C threshold. The Arduino Nano processes the ADC readings and multiplexes two 7-segment displays at 200 Hz for a flicker-free real-time temperature readout. 

The system progressed from a dense breadboard prototype to a fully routed custom PCB designed in KiCad.

## Hardware Components
* **Microcontroller:** Arduino Nano (ATmega328P)
* **Temperature Sensor:** 10k NTC Thermistor
* **Analog Comparator:** LM358 Dual Op-Amp
* **Power Switching:** BD139 NPN Transistor (with 1N4007 flyback diode)
* **Display:** 2x Common Cathode 7-Segment Displays
* **Output:** 12V DC Fan

##  Features
* **Custom PCB:** Designed in KiCad with strict 45-degree track routing and zero DRC errors.
* **Firmware Optimization:** Custom C++ code to calculate temperature via the Steinhart-Hart equation and handle 200 Hz display multiplexing to eliminate ghosting.
* **Hardware Protection:** Integrated flyback diode to suppress back-EMF spikes from the fan motor.

##  Project Files
* `dc_fan_controller.ino`: The main Arduino C++ source code.
* `microproject_sem2_fixed.pdf`: Full engineering project report, including circuit analysis, KiCad schematics, and testing methodologies.

##  Author
**Hemil Thakkar** Electronics Engineering Student at BVM Engineering College.
