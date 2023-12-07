# Source code

Each directory represents an independent process, and these processes exchange data through vsomeip communication. Here is a list outlining the basic operational principles and purposes of each process.

---

## [CANSender](./CANSender/)
CANSender is designed to process both vehicle speed data and distance data from a rear distance sensor, relaying the refined information to the IPCManager after filtering.


This system employs two threads to manage the processing tasks. In the first thread, vehicle speed and rear distance data is captured from an external source through the CAN shield and stored in a circular queue buffer. Concurrently, the second thread periodically retrieves the latest data from this buffer. Especially for the speed data, it undergoes a Kalman filter to enhance accuracy. Finally, speed and distance value is forwarded to the IPCManager.

The external data source for both speed and distance information is CAN signals originating from an Arduino. The circular buffer plays a crucial role in managing and storing this data, serving as a mechanism to address potential delays resulting from communication speed discrepancies and the filtering process. Additionally, mutual exclusion, implemented through mutexes, ensures seamless coordination between the two threads when accessing and manipulating the shared circular queue buffer.

## [HeadUnit](./HeadUnit/)
HeadUnit, as part of the In-Vehicle Infotainment system, features a Qt-based GUI that facilitates various user interactions related to vehicle functions, such as ambient light color selection and media playback.


The screen of the Head Unit is composed using the wayland compositor in Qt. This Qt-based screen operates on the wayland platform, providing a seamless and responsive user experience within the vehicle's infotainment system. It derives data on speed from the IPCManager. Concurrently, it relays data about ambient lighting preferences. One of its distinctive features is allowing users to power off the OS, analogous to switching off a vehicle.

## [IPCManager](./IPCManager/)
IPCManager functions as a conduit, ensuring seamless data exchange between all processes.


Primarily, the IPCManager ensures the correct flow of data amongst all processes. It is adept at asynchronously disseminating data. A noteworthy feature is its capability to monitor the connectivity of other processes. If it detects a malfunction or disconnect, it can swiftly terminate the erring process and initiate a restart via reboot scripts(only in rasbian version).

In addition to its role in managing data flow and process connectivity, the IPCManager also acts as a repository for storing vital information. Analogous to the engine of a vehicle, it utilizes this stored information to control hardware components. This dual functionality underscores the IPCManager's importance, not only in maintaining seamless communication among processes but also in leveraging stored data to effectively control hardware, resembling the way a vehicle's engine manages and regulates various components.

## [InstrumentCluster](./InstrumentCluster/)
InstrumentCluster is a Qt-based interface that displays crucial vehicle data to the user in real-time.


Built using Qt, this GUI presents the vehicle's speed, RPM, battery level, and current gear mode status to the user. An additional feature is its ability to dynamically adjust ambient lighting based on user inputs sourced from the HeadUnit.

## [PiracerController](./PiracerController/)
PiracerController integrates the piracer-py Python library with vsomeip communication to control vehicle movements based on gamepad input.


To meld the piracer-py Python library with vsomeip communication, this process incorporates Python within C++. It processes input from the gamepad controller, directing the vehicle's movement and steering according to the selected gear mode. The gear mode data is sourced from the IPC Manager, while steering information is relayed back to the IPC Manager.

## [PiracerSender](./PiracerSender/)
PiracerSender gauges the vehicle's battery voltage, computes the remaining charge, and communicates this data to the IPCManager.


This process, integrating the piracer-py Python library with vsomeip communication, is devised by embedding Python within C++. It periodically measures the vehicle's battery voltage, derives the remaining battery percentage, and subsequently forwards this critical information to the IPCManager.
