# Managing Process by supervisor

This project is designed for Yocto. Currently, in Yocto, each process is managed by python-supervisor. Python-supervisor is a client/server system that allows monitoring and control of multiple processes on UNIX-like operating systems. Through this, the HeadUnit program can operate with enhanced reliability and redundancy.

# Key Features of Python-supervisor:
1. Process Control: The core function of Supervisor is to start, stop, and manage background processes. If a process fails, it is automatically started and restarted.
2. Configuration: Processes are managed based on a configuration file where each process (or group of processes) is defined.
3. Web-based Interface: Supervisor offers a web-based user interface that allows users to view the current status of processes, read logs, and manage the processes.
4. XML-RPC Interface: In addition to the web-based UI, Supervisor provides an XML-RPC interface, allowing for programmatic control of the system.
5. Event Notifications: Supervisor can be configured to send out notifications when specific events occur, such as when a process stops unexpectedly.
6. Extensibility: The event listener functionality of Supervisor allows for a wide range of extensions. Users can craft custom event listeners to address particular scenarios.

# How it works:
When you start Supervisor, it typically begins as a daemon process. Once running, Supervisor initiates the processes defined in its configuration. These child processes are then monitored. If any of them fail or stop, Supervisor takes the action as defined in the configuration, usually by restarting the process.

# Rasbian Lite OS 64bit
However, using Supervisor on the Raspbian OS can be complicated, making a quick start challenging. For this reason, we opted to manage processes using simple shell scripts instead.