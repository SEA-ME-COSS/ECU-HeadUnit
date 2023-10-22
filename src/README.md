# Source code

Each directory represents an independent process, and these processes exchange data through vsomeip communication. Here is a list outlining the basic operational principles and purposes of each process.

---

## [CANSender](https://github.com/SEA-ME-COSS/DES-Head-Unit/tree/making_main/src/CANSender)

This process is implemented with two threads. One thread is responsible for storing vehicle speed data received from the external source via the CAN shield into a circular queue buffer. The other thread periodically retrieves the most recent data from the buffer, filters it through a Kalman filter, and then forwards the value to the IPCManager. The reason for the existence of the buffer is to eliminate delays in the synchronization of communication speeds and during the filtering process. Both threads are synchronized through the use of mutexes to access the shared resource.

## HeadUnit

This GUI is developed in Qt and allows user interaction through touch input. Users can engage with functions such as selecting gear modes, operating turn signals, accessing GPS, playing MP3 and MP4, and more. It receives data regarding speed and steering from the IPCManager and, in turn, sends data related to gear mode selection, ambient lighting colors, and turn signals. Users can also power off the OS, similar to turning off a vehicle with a power button.

## IPCManager

It serves as a bridge, ensuring that data flows correctly between all processes. It can rapidly distribute data in an asynchronous manner. Additionally, it checks the connectivity of other processes and, in case of issues, can terminate and restart the problematic process using reboot scripts.

## InstrumentCluster

This GUI is developed in Qt and displays real-time speed and RPM information of the vehicle to the user. It also shows the current battery level and gear mode status of the vehicle. Additionally, it reflects changes in ambient lighting based on user interactions with the HeadUnit.

## PiracerOperator

To enable the integration of the piracer-py Python library with vsomeip communication, this process is implemented by binding the Python language within C++. It receives input data from the gamepad controller and controls the vehicle's drive and steering based on the current gear mode. It receives gear mode information from the IPC Manager and, in turn, sends steering information in the opposite direction.

## PiracerSender

To enable the integration of the piracer-py Python library with vsomeip communication, this process is implemented by binding the Python language within C++. This process periodically measures the voltage from the vehicle's battery and calculates the remaining battery level from it. It then sends this information to the IPCManager.
