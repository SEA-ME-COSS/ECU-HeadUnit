# **In-Vehicle Infotainment**

---

# Result

https://github.com/SEA-ME-COSS/In-Vehicle-Infotainment/assets/138571365/dcbd66a4-180e-49f2-ae53-7439cfcd650e


If you want to check out more clearly, [click me!](https://www.youtube.com/watch?v=rZjfliSumWo)

# Introduction

<table border="0" rules="none">
<tr border="0">
    <td width="280" height="200" align="center">
        <a href="#">
            <img alt="Yocto Logo" src="/media/logo/yocto-logo.png">
        </a>
    </td>
    <td width="280" height="200" align="center">
        <a href="#">
            <img alt="Qt Logo" src="/media/logo/qt-logo.png">
        </a>
    </td>
    <td width="350" height="200" align="center">
        <a href="#">
            <img alt="Covesa Logo" src="/media/logo/covesa-logo.png">
        </a>
    </td>
</tr>
</table>

This repository presents of developing the In-Vehicle-Infotainment system for the PiRacer vehicle. Through the design of IPC mechanisms, it enables the implementation of functionalities on a Raspberry Pi4 that closely resemble those found in a real vehicle.

This project is the final compilation of the 'DES Project’. The 'DES Project' stands for Distributed Embedded Systems. The main focus of this In-Vehicle Infotainment project is to create an infotainment system in an environment similar to an actual vehicle using Qt, an embedded GUI development application, and COVESA's vsomeip, an IPC that conforms to the AUTOSAR standard. An essential challenge in this endeavor is to ensure that all of these interactions occur within an operating system developed based on Yocto.

Therefore, if you want to precisely follow this project, you need to have the exact [hardware setup](./setting/) ready and proceed according to the instructions on the [meta-infotainment page](https://github.com/SEA-ME-COSS/meta-infotainment). Once you've done this, you should burn the final image onto an SD card. By doing so, you too can experience and use our project!

# Architecture

<img src=/media/diagram/software-architecture.png alt="software_architecture" width="100%" height="100%"/>

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
- Raspberry Pi 4 Camera
- Arduino ultrasonic sensor (HY-SRF05)

<img src=/media/diagram/hardware-architecture.png alt="hardware_architecture" width="100%" height="100%"/>

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

# Key Concept

## Qt
### Brief on Qt
- Qt is a cross-platform C++ framework used for developing both GUI and non-GUI applications. It is popular for creating applications that can run on various operating systems and includes modules for networking, databases, and graphics.

### Brief on Qt Compositor
- Qt Compositor, part of the Qt framework, is used for developing Wayland compositors. It enables developers to create their custom compositors for managing application windows on the screen, integrating well with Qt's robust graphics capabilities.

### Why Qt Compositor for Headunit Development

1. **Modularity**: Enables handling each application as an independent window, simplifying the addition or removal of applications.
2. **Independent Development**: Facilitates developing applications separately and integrating them smoothly.  
3. **Enhanced User Experience**: Supports seamless transitions and interactions between applications, vital for driver-focused systems.
4. **Resource Efficiency**: Offers efficient resource management, essential in the resource-constrained environment of automotive systems.  
  
These strengths of Qt Compositor make it an ideal choice for developing sophisticated and responsive headunit systems.

## vSomeIP & CommonAPI

### vSomeIP

- The SOME/IP protocol is a standard IPC within AUTOSAR, and vSomeIP is its open-source implementation.

- vSomeIP supports features like service discovery, service-oriented communication, and event notification, making it suitable for complex automotive systems that require reliable and scalable communication solutions.


### CommonAPI

- CommonAPI is one of the developments by the GENIVI Alliance to standardize middleware communication in automotive software.

- It provides an advanced C++ API for developing applications that communicate between various middleware systems within vehicles, such as SOME/IP, DBus, and others.

- CommonAPI abstracts the underlying communication mechanisms, allowing developers to focus on the application logic without worrying about the details of the communication protocols.


vSomeIP and CommonAPI are crucial parts of modern automotive software architecture, enabling efficient and standardized communication in complex vehicle systems. We have chosen these IPCs for implementing vehicle communication on Raspberry Pi.

## Yocto Project

- The Yocto Project is an open-source project designed to create custom Linux-based operating system /media.

- This project assists developers in easily creating Linux distributions tailored for specific hardware. This enables the development of customized Linux environments suitable for a wide range of platforms including IoT (Internet of Things) devices, embedded systems, automotive applications, and mobile phones.


We have utilized the Yocto Project to develop a Linux environment optimized for our IVI (In-Vehicle Infotainment) application. We then created a single image from this environment, making it easily accessible for anyone to download and use this optimized Linux image.

# References

- Yocto Project. (2021). Yocto Project. https://www.yoctoproject.org/
- Qt Project. (2021). Qt Project. https://www.qt.io/
- Raspberry Pi Foundation. (2021). Raspberry Pi. https://www.raspberrypi.org/
- [CAN specification documents](http://esd.cs.ucr.edu/webres/can20.pdf): These documents provide detailed information on the CAN (Controller Area Network) protocol and its implementation.
- [VsomIp documents](https://github.com/COVESA/vsomeip/wiki/vsomeip-in-10-minutes): These documents provide information on the Inter-Process Communication (IPC) frameworks VsomIp and Autosar and their implementation in the automotive industry.

Shield: [![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
