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
10. Ultrasonic sensor (HY-SRF05)
11. RPi Camera

# Precautions

- To prevent electric shock, ensure that all assembly procedures are carried out with the power turned off.
- Exercise care when assembling the components, as incorrect assembly may result in damage to the components.
- When not in use, please safeguard the components and power them off.

---

# Hardware Setting

<img src=/media/diagram/hardware-architecture.png alt="hardware_architecture" width="100%" height="100%"/>

1. Assemble the Raspberry Pi board with the CAN-BUS shield and a 7.9inch LCD, and then attach it on the PiRacer.
2. Assemble the Arduino board with the CAN-BUS shield and attach it to the front of the PiRacer.

<img src=/media/picture/arduino_assembly.jpg alt="arduino_assembly" width="100%" height="100%"/>

3. Fix the 7inch LCD onto the PiRacer using a robust material like a metal frame to position it above the Arduino.

<img src=/media/picture/display_assembly.jpg alt="display_assembly" width="100%" height="100%"/>

4. Fix the speed sensor's rotor in a way that it aligns and rotates with the PiRacer's rear tires.

<img src=/media/picture/speed_sensor_assembly.jpg alt="speed_sensor_assembly" width="100%" height="100%"/>

5. Connect the receiver of the gamepad controller to one of the USB ports on the Raspberry Pi.

<img src=/media/picture/gamepad_controller.jpg alt="gamepad_controller" width="100%" height="100%"/>

6. (Optional) Install an auxiliary battery to provide additional power during PiRacer operation. Create a case for the auxiliary battery and position it at the rear of the PiRacer vehicle.

<img src=/media/picture/power_bank.jpg alt="power_bank" width="100%" height="100%"/>

<img src=/media/picture/power_bank_assembly.jpg alt="power_bank_assembly" width="100%" height="100%"/>

7. Install RPi Camera and Ultrasonic sensor at the rear of the PiRacer vehicle.

<img src=/media/picture/pdc_part_assembly.jpg alt="pdc_part_assembly" width="100%" height="100%"/>

8. Final result.

<img src=/media/picture/overall_hardware_1.jpg alt="overall_hardware" width="100%" height="100%"/>

<img src=/media/picture/overall_hardware_2.jpg alt="overall_hardware" width="100%" height="100%"/>

<img src=/media/picture/final_result.jpg alt="final_result" width="100%" height="100%"/>

---

# Software Setting

This project was conducted in Yocto, so for accurate testing, please refer to our [meta-infotainment](https://github.com/SEA-ME-COSS/meta-infotainment) repo. However, if you wish to test it on Raspbian, please follow the settings below.

## CommonAPI and vsomeip

Step 1: Install Boost Library

```bash
sudo apt-get install libboost-all-dev
```

Step 2: Build the CommonAPI Runtime Library

```bash
cd ~
mkdir build-commonapi
cd build-commonapi
git clone https://github.com/GENIVI/capicxx-core-runtime.git
cd capicxx-core-runtime/
git checkout 3.2.0
mkdir build
cd build
cmake ..
make -j4
```

Step 3: Build the vsomeip Library

```bash
cd ~
git clone https://github.com/COVESA/vsomeip.git
cd vsomeip
git checkout 3.1.20.3
mkdir build
cd build
cmake -DENABLE_SIGNAL_HANDLING=1 -DDIAGNOSIS_ADDRESS=0x10 ..
make -j4
sudo make install
```

Step 4: Build the CommonAPI SOME/IP Runtime Library

```bash
cd ~/build-commonapi
git clone https://github.com/GENIVI/capicxx-someip-runtime.git
cd capicxx-someip-runtime/
git checkout 3.2.0
mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF ..
make -j4
```

Step 4: Install code generator for Franca files (The architecture of the Raspberry Pi does not support the code generator, so this step must be executed on a laptop.)

```bash
cd ~
mkdir generator
cd generator

wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.2.0.1/commonapi_core_generator.zip
unzip commonapi_core_generator.zip -d core-generator
cd core-generator
chmod +x commonapi-core-generator-linux-x86_64

cd ~/generator
wget https://github.com/COVESA/capicxx-someip-tools/releases/download/3.2.0.1/commonapi_someip_generator.zip
unzip commonapi_someip_generator.zip -d someip-generator
cd someip-generator
chmod +x commonapi-someip-generator-linux-x86_64
```

For more detail about CommonAPI and vsomeip, visit [here](https://github.com/COVESA/vsomeip/wiki/vsomeip-in-10-minutes)

## For the remaining software installation and configuration code, please consult the following link

- [2-Channel CAN-BUS(FD) Shield (MCP2518FD)](https://www.waveshare.com/wiki/2-CH_CAN_FD_HAT)
- [7.9inch DSI LCD (400 x 1280)](https://www.waveshare.com/wiki/7.9inch_DSI_LCD)
- [7inch HDMI LCD (H) (1028 x 600)](https://www.waveshare.com/wiki/7inch_HDMI_LCD_(H)_(with_case))
- [CAN-BUS Shield V2.0 (MCP2515)](https://github.com/autowp/arduino-mcp2515)
- [Qt5](https://qengineering.eu/install-qt5-with-opencv-on-raspberry-pi-4.html)
- [GStreamer plug-in](https://qengineering.eu/install-gstreamer-1.18-on-raspberry-pi-4.html)
- [Qt wayland compositor](https://github.com/qt/qtwayland)

## Display configuration

In this project, we will be using two platforms, eglfs and linuxfb, to simultaneously interface a DSI display and an HDMI display. After completing the installation as per the above procedure, you may notice that part of the 7.9inch display is not visible. This issue arises because the 7inch display's specifications restrict the screen area. To resolve this, you can modify the code written in /boot/config.txt as follows.

```bash
hdmi_cvt 1024 1280 60 6 0 0 0
```

Note that the 7inch display's specifications are recognized as larger than the actual hardware, so you may need to adjust the source files to align the application with the visible area. Typically, for applications developed for a 1024 x 600 screen size in Qt, reducing the scale by x0.5 will display the content correctly.

<img src=/media/diagram/display_configuration.png alt="display_configuration" width="80%" height="80%"/>

## Camera configuration

Generally, we set up raspi-config in order to use the camera on raspberry pi. However, this method makes it impossible to use two screens at the same time. Therefore write the following directly in /boot/config.txt.

```bash
start_x=1
```

## Piracer package configuration

The piracer package can only receive input by two joysticks when first installed, and in order to use other buttons, the code needs to be modified after installing the package. Therefore change code to the following in ~/.local/lib/python3.xx/site-packages/piracer/gamepads.py

```python3
class ShanWanGamepadInput:
    def __init__(self) -> None:
        self.analog_stick_left = Vector3f()
        self.analog_stick_right = Vector3f()
        self.button_l1 = False
        self.button_l2 = False
        self.button_r1 = False
        self.button_r2 = False
        self.button_x = False
        self.button_a = False
        self.button_b = False
        self.button_y = False
        self.button_select = False
        self.button_start = False
        self.button_home = False
```

## Gamepad controller configuration

Several types of gamepad controller have different button recognition. Run the following code to see which buttons give which signal. Modify and use the [ControllerClass.cpp](../src/PiracerController/ControllerClass.cpp) of the PiracerController properly.

```python3
from piracer.gamepads import ShanWanGamepad

if __name__ == '__main__':

	shanwan_gamepad = ShanWanGamepad()

	while True:
		gamepad_input = shanwan_gamepad.read_data()

		throttle = gamepad_input.analog_stick_right.y
		steering = gamepad_input.analog_stick_left.x
		l1 = gamepad_input.button_l1
		l2 = gamepad_input.button_l2
		r1 = gamepad_input.button_r1
		r2 = gamepad_input.button_r2
		x = gamepad_input.button_x
		a = gamepad_input.button_a
		b = gamepad_input.button_b
		y = gamepad_input.button_y
		select = gamepad_input.button_select
		start = gamepad_input.button_start
		home = gamepad_input.button_home

		print('---------------')
		print(f'throttle={throttle}')
		print(f'steering={steering}')
		print(f'l1={l1}')
		print(f'l2={l2}')
		print(f'r1={r1}')
		print(f'r2={r2}')
		print(f'x={x}')
		print(f'a={a}')
		print(f'b={b}')
		print(f'y={y}')
		print(f'select={select}')
		print(f'start={start}')
		print(f'home={home}')
		print('---------------')
```
