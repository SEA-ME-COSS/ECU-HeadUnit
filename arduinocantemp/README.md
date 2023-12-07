# How does this represent speed & distance?

## Speed

Frankly, this code isn't directly measuring "speed." It's measuring the revolutions per minute (RPM), which indicates how many times a wheel rotates in a minute.

If you know the diameter or circumference of the wheel, you can calculate the actual speed (e.g., km/h or m/s) using the RPM. This calculation would follow the formula:

Speed=RPM×Circumference

$$
Speed = RPM \times Circumference
$$

For instance, if the wheel's circumference is 2m and the RPM is 30, the speed would be 3**0 x 2 = 60m/min** or **1m/s**.

So, while the code doesn't provide speed directly, it offers the foundational rotational data that, combined with additional information (like wheel circumference), can facilitate this.

If you want to know more about it, go to our "arduino _can" repo

## Distance

Using an ultrasonic sensor, this code measures the distance by calculating the time it takes for an ultrasonic signal to bounce back from an object. The calculation is performed as follows:

- **Time Measurement (`duration`)**: The `pulseIn` function measures the round-trip time (in microseconds) it takes for the ultrasonic pulse to travel to an object and back.
- **Distance Calculation (`distance`)**: The distance is calculated using the measured time (`duration`). The formula is as follows:
    
    $$
    
    \[ \text{Distance (cm)} = \frac{\text{Time (microseconds)}}{29} \div 2 \]
    
    $$
    
    This calculation is based on the speed of sound in air, which is approximately 343m/s (or about 34300cm/s). To find the distance traveled by the sound wave in the measured time, the formula is:
    
    $$
    
    \[ \text{Distance (cm)} = \frac{34300 \text{ cm/s}}{1000000} \times \text{Time (microseconds)} \]
    
    $$
    
    Simplifying this gives:
    
    $$
    
    \[ \text{Distance (cm)} = \frac{\text{Time (microseconds)}}{29} \]
    
    $$
    
    The division by 2 is necessary because the measured time is for the round trip (to the object and back), and the actual distance to the object is half of this total travel distance.

# Arduino

This Arduino code is designed to transmit RPM and distance measurements using the MCP2515 CAN controller over a CAN (Controller Area Network) bus.

# **Basic Concepts**

---

## **Controller Area Network (CAN)**

1. **CAN Message Format**: CAN messages consist of a unique identifier (ID), data length (DLC), and actual data bytes. This structure enables efficient data transmission and error detection.
2. **Bit Shifting**: Used to divide large data into 8-bit units for CAN messages. Although not currently used, it will be useful later for setting the data's factor and offset.

## **Pulse (RPM Measurement)**

1. **Pulse**: The sensor used in this code generates a pulse with each rotation. It is assumed here that there are 20 pulses per revolution. This pulse is a digital signal produced a set number of times as the sensor completes one full rotation.
2. **Period**: Refers to the time between two consecutive pulses. For example, if pulses occur every 1ms, then the period is 1ms.
3. **Frequency**: Denotes the number of pulses in a unit of time. It can be calculated as the inverse of the period. For example, if the period is 1ms, then the frequency is 1000Hz or 1kHz.

## Distance Measurement

1. **Ultrasonic Sensor**: This code uses an ultrasonic sensor to measure distance. The sensor emits an ultrasonic signal and measures the time it takes for the signal to bounce back from an object.
2. **Distance Calculation**: The distance is calculated using the measured time. This is based on the speed of sound in air and the time taken for the signal to travel to the object and back.

# **How the Code Works:**

1. **Detecting Pulses:** The `attachInterrupt()` function is used to detect pulses from the sensor. Every time a pulse is generated, the `Pulse_Event()` function is invoked.
2. **Calculating the Period:** Inside the `Pulse_Event()` function, the time difference between the last and the current pulse is calculated to determine the period.
3. **Calculating Frequency:** Within the `loop()`, the frequency is calculated using the average period.
4. **Calculating RPM:** Knowing the number of pulses per revolution, RPM is determined using the frequency. This frequency is multiplied by 60 to convert it into revolutions per minute.
5. **Time Measurement (`duration`)**: The `pulseIn` function measures the time taken for the ultrasonic signal to return.
6. **Distance Calculation (`distance`)**: The distance is calculated using the measured time.
7. **Preparing CAN Messages:** CAN messages for RPM and distance are prepared by placing data into specific bytes of the CAN frame. Data is bit-shifted to align correctly within the 8-bit structure of the CAN frame data bytes.
    - For example, **`canMsg1.data[0] = (RPM & 0xFF00) >> 8;`** shifts the higher byte of the RPM value into the first data byte of the CAN message. **`canMsg1.data[1] = (RPM & 0x00FF);`** places the lower byte of the RPM into the second data byte.