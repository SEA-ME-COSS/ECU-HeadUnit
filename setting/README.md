# Hardware & Software Setting Guide

This document provides a guide for hardware assembly, setup, and software environment configuration. All contents of this project have been tested in the environment described below.

# Requirements

Before starting this guide, you will need the following components:

1. Raspberry Pi 4B
2. 2-Channel CAN-BUS(FD) Shield (MCP2518FD)
3. PiRacer AI Kit (PiRacer Standard)
4. 7.9inch DSI LCD (400 x 1280)
5. 7inch HDMI LCD (H) (1028 x 600)
6. Gamepad controller
7. Arduino UNO
8. CAN-BUS Shield V2.0 (MCP2515)
9. IR infrared Speed Sensor (LM393)

# Precautions

- To prevent electric shock, ensure that all assembly procedures are carried out with the power turned off.
- Exercise care when assembling the components, as incorrect assembly may result in damage to the components.
- When not in use, please safeguard the components and power them off.

---

# Hardware Setting

<img src=/Images/diagram/hardware_architecture.png alt="hardware_architecture" width="100%" height="100%"/>

1. Assemble the Raspberry Pi board with the CAN-BUS shield and a 7.9inch LCD, and then attach it on the PiRacer.
2. Assemble the Arduino board with the CAN-BUS shield and attach it to the front of the PiRacer.

<img src=/Images/picture/arduino_assembly.jpg alt="arduino_assembly" width="100%" height="100%"/>

3. Fix the 7inch LCD onto the PiRacer using a robust material like a metal frame to position it above the Arduino.

<img src=/Images/picture/display_assembly.jpg alt="display_assembly" width="100%" height="100%"/>

4. Fix the speed sensor's rotor in a way that it aligns and rotates with the PiRacer's rear tires.

<img src=/Images/picture/speed_sensor_assembly.jpg alt="speed_sensor_assembly" width="100%" height="100%"/>

5. Connect the receiver of the gamepad controller to one of the USB ports on the Raspberry Pi.

<img src=/Images/picture/gamepad_controller.jpg alt="gamepad_controller" width="100%" height="100%"/>

6. (Optional) Install an auxiliary battery to provide additional power during PiRacer operation. Create a case for the auxiliary battery and position it at the rear of the PiRacer vehicle.

<img src=/Images/picture/power_bank.jpg alt="power_bank" width="100%" height="100%"/>

<img src=/Images/picture/power_bank_assembly.jpg alt="power_bank_assembly" width="100%" height="100%"/>

7. Final result.

<img src=/Images/picture/overall_hardware_1.jpg alt="overall_hardware" width="100%" height="100%"/>

<img src=/Images/picture/overall_hardware_2.jpg alt="overall_hardware" width="100%" height="100%"/>

<img src=/Images/picture/final_result.jpg alt="final_result" width="100%" height="100%"/>

---

# Software Setting

…

































Commands to generate code

(fidl file)
~/generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/DESProject.fidl -d ./src-gen-desproject

(fdepl file)
~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 ./fidl/DESProject.fdepl -d ./src-gen-desproject

