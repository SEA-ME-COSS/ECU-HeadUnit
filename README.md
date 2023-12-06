# **DES Project - Head Unit**

---

# Result

<img src=/images/demonstration/ambient_lighting.gif alt="ambient_lighting" width="100%" height="100%"/>

# Introduction

<table border="0" rules="none">
<tr border="0">
    <td width="280" height="200" align="center">
        <a href="#">
            <img alt="Yocto Logo" src="images/logo/yocto-logo.png">
        </a>
    </td>
    <td width="280" height="200" align="center">
        <a href="#">
            <img alt="Qt Logo" src="images/logo/qt-logo.png">
        </a>
    </td>
    <td width="350" height="200" align="center">
        <a href="#">
            <img alt="Covesa Logo" src="images/logo/covesa-logo.png">
        </a>
    </td>
</tr>
</table>


This repository presents of developing the Instrument Cluster and Head Unit for the PiRacer vehicle. Through the design of IPC mechanisms, it enables the implementation of functionalities on a Raspberry Pi4 that closely resemble those found in a real vehicle.

The 'DES Project' stands for Distributed Embedded Systems. The primary focus of this Head Unit project is to implement communication algorithms within the vehicle and facilitate Inter-Process Communication (IPC) among various processes. An essential challenge in this endeavor is to ensure that all of these interactions occur within an operating system developed based on Yocto.

A key communication protocol emphasized in this project is 'vsomeip' It is integrated using 'CommonAPI' Within the system, several processes have distinct roles:

1. One process receives real-time vehicle speed data from external Electronic Control Units (ECUs) via CAN communication.
2. Another process calculates real-time remaining battery levels.
3. A separate process is responsible for controlling vehicle drive and steering, adapting its behavior based on the selected gear mode.


# Architecture

<img src=/images/diagram/software-architecture.png alt="software_architecture" width="100%" height="100%"/>

# Setting

## Requirements

Detailed information regarding setup and configuration can be found within the [settings folder](./setting/). Following the content within this folder should allow you to reproduce the test environment we have implemented.

Below are the specifications of the hardware used in the project.

### Raspberry Pi 4B

- 2-Channel CAN-BUS(FD) Shield (MCP2518FD)
- PiRacer AI Kit (PiRacer Standard)
- 7.9inch DSI LCD (400 x 1280)
- 7inch HDMI LCD (H) (1028 x 600)
- Gamepad controller

### Arduino UNO

- CAN-BUS Shield V2.0 (MCP2515)
- IR infrared Speed Sensor (LM393)

<img src=/images/diagram/hardware-architecture.png alt="hardware_architecture" width="100%" height="100%"/>

# Usage

To run it on a Yocto-based OS go to our [meta-infotainment](https://github.com/SEA-ME-COSS/meta-infotainment) repo.

Additionally, for executing it on Raspbian OS after [setting](./setting/), use the following code:

```bash
mkdir build
cd build
cmake ..
make
./IPCManager
```

# Detail

To learn more about the specific implementation of the project, please refer to the README.md file inside each respective file.

# References

- Yocto Project. (2021). Yocto Project. https://www.yoctoproject.org/
- Qt Project. (2021). Qt Project. https://www.qt.io/
- Raspberry Pi Foundation. (2021). Raspberry Pi. https://www.raspberrypi.org/
- CAN specification documents: These documents provide detailed information on the CAN (Controller Area Network) protocol and its implementation.
- VsomIp/Autosar documents: These documents provide information on the Inter-Process Communication (IPC) frameworks VsomIp and Autosar and their implementation in the automotive industry.

Shield: [![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
