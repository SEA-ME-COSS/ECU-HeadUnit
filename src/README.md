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

## [IVICompositor](./IVICompositor/)
IVICompositor is a Qt-based GUI provisioning process designed for constructing In-Vehicle Infotainment systems.


Utilizing the Qt Wayland Compositor, IVICompositor can concurrently display screens from multiple processes. Screens from both HeadUnit and PDCUnit are utilized and managed as layers. Depending on the gear mode, with selections like P (Park), N (Neutral), and D (Drive), the HeadUnit screen takes precedence when displayed. However, when the gear mode transitions to R (Reverse), activating the Parking Distance Control (PDC) feature, the PDCUnit screen appears above the HeadUnit screen. This layered management ensures dynamic visibility based on the vehicle's gear mode, enhancing the user interface for both HeadUnit and PDCUnit functionalities.

## [InstrumentCluster](./InstrumentCluster/)
InstrumentCluster is a Qt-based interface that displays crucial vehicle data to the user in real-time.


Built using Qt, this GUI presents the vehicle's speed, RPM, battery level, and current gear mode status to the user. An additional feature is its ability to dynamically adjust ambient lighting based on user inputs sourced from the HeadUnit.

## [PDCUnit](./PDCUnit/)
Similar to the HeadUnit, the PDCUnit is also part of the In-Vehicle Infotainment system, featuring a Qt-based GUI.


It serves the functionality of displaying the rearview camera's perspective during reverse parking on the screen. The GUI operates on the wayland platform in Qt, ensuring a smooth and responsive user experience within the vehicle's infotainment system. The display incorporates color-coded indicators, with green, yellow, and red signals appearing on the screen based on the distance from rear objects. This visual representation assists the driver in perceiving distances accurately and enhances overall awareness during reverse parking scenarios.

## [PiracerController](./PiracerController/)
PiracerController serves as a bridge between hardware control and controller input, delivering controller input information to the IPC Manager without directly manipulating the hardware. The IPC Manager receives this information and utilizes it to control the vehicle's hardware components.


In achieving this functionality, PiracerController seamlessly integrates the piracer-py Python package with vsomeip communication. This integration involves incorporating Python within a C++ framework. 

## [PiracerSender](./PiracerSender/)
PiracerSender gauges the vehicle's battery voltage, computes the remaining charge, and communicates this data to the IPCManager.


This process, integrating the piracer-py Python package with vsomeip communication, is devised by embedding Python within C++. It periodically measures the vehicle's battery voltage, derives the remaining battery percentage, and subsequently forwards this critical information to the IPCManager.

## [RemoteSpeaker](./RemoteSpeaker/)
RemoteSpeaker is specifically designed for the Parking Distance Control (PDC) functionality, serving as a process that provides users with audio alerts based on data from the rear distance sensor. It receives distance information from the IPC Manager and delivers alerts at varying speeds depending on the distance range.


The method by which RemoteSpeaker generates sound is quite unique. Since there is no onboard speaker on Raspberry Pi and no additional speaker components are attached, an innovative approach is taken. A personal laptop is used to remotely connect to the Raspberry Pi, essentially functioning as an external speaker for the Raspberry Pi. The sound production method involves outputting the '\a' character in the terminal, which emits a beep sound.

To set up and experience this, one needs to establish an SSH connection to the Raspberry Pi from a laptop and then run RemoteSpeaker executable file. Although the RemoteSpeaker process is running within the Raspberry Pi, the output results appear on the laptop's terminal, allowing users to hear the sound.

It's important to note that the beep sound can be tested on the laptop's terminal by pressing the Tab key. If the beep sound is not produced, proper settings may need to be configured first.
