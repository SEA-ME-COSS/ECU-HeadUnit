# Source code

Each directory represents an independent process, and these processes exchange data through vsomeip communication. Here is a list outlining the basic operational principles and purposes of each process.

---

## [CANSender](./CANSender/)
CANSender is designed to process vehicle speed data from an external source and relay this data to the IPCManager after filtering.


This process utilizes two threads. The first thread captures vehicle speed data from the external source through the CAN shield and stores it into a circular queue buffer. Meanwhile, the second thread periodically fetches the latest data from this buffer, subjects it to a Kalman filter for accuracy, and then passes the refined value to the IPCManager. The buffer's primary purpose is to mitigate potential delays arising from communication speed discrepancies and the filtering process. Mutual exclusion (mutexes) ensures both threads coordinate seamlessly when accessing the shared resource.

## [HeadUnit](./HeadUnit/)
HeadUnit is a Qt-based GUI that offers various vehicle-related user interactions, including gear mode selection and media playback.


Developed in Qt, this GUI caters to touch input, enabling users to interact with multiple functions such as selecting gear modes, toggling turn signals, using GPS, and playing media files like MP3 and MP4. It derives data on speed and steering from the IPCManager. Concurrently, it relays data about the chosen gear mode, ambient lighting preferences, and turn signal status. One of its distinctive features is allowing users to power off the OS, analogous to switching off a vehicle.

## [IPCManager](./IPCManager/)
IPCManager functions as a conduit, ensuring seamless data exchange between all processes.


Primarily, the IPCManager ensures the correct flow of data amongst all processes. It is adept at asynchronously disseminating data. A noteworthy feature is its capability to monitor the connectivity of other processes. If it detects a malfunction or disconnect, it can swiftly terminate the erring process and initiate a restart via reboot scripts(only in rasbian version).

## [InstrumentCluster](./InstrumentCluster/)
InstrumentCluster is a Qt-based interface that displays crucial vehicle data to the user in real-time.


Built using Qt, this GUI presents the vehicle's speed, RPM, battery level, and current gear mode status to the user. An additional feature is its ability to dynamically adjust ambient lighting based on user inputs sourced from the HeadUnit.

## [PiracerController](./PiracerController/)
PiracerController integrates the piracer-py Python library with vsomeip communication to control vehicle movements based on gamepad input.


To meld the piracer-py Python library with vsomeip communication, this process incorporates Python within C++. It processes input from the gamepad controller, directing the vehicle's movement and steering according to the selected gear mode. The gear mode data is sourced from the IPC Manager, while steering information is relayed back to the IPC Manager.

## [PiracerSender](./PiracerSender/)
PiracerSender gauges the vehicle's battery voltage, computes the remaining charge, and communicates this data to the IPCManager.


This process, integrating the piracer-py Python library with vsomeip communication, is devised by embedding Python within C++. It periodically measures the vehicle's battery voltage, derives the remaining battery percentage, and subsequently forwards this critical information to the IPCManager.
