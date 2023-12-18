# Ultrasonic
# System Overview
This project implements a Distance Measurement System using the ATmega32 microcontroller with a frequency of 8MHz and a ultrasonic sensor. It measures distances and displays them on a 2x16 LCD in centimeters using 4-bit data mode. The project follows a layered architecture model, consisting of GPIO, ICU, LCD, and Ultrasonic drivers.

# System Requirements
# Hardware
ATmega32 Microcontroller with a frequency of 8MHz.
HC-SR04 Ultrasonic Sensor. Refer to the "HC-SR04 Ultrasonic MT Student Tutorial" PDF for interfacing details.
A 2x16 LCD with 4-bit data mode.
🔹 Structured Architecture Model:
Our system is built on a well-organized architecture model:

HAL Layer (Hardware Abstraction Layer): Encompassing LCD, HC-SR04 ultrasonic sensor, this layer simplifies hardware complexities, enhancing overall efficiency.

MCAL Layer (Microcontroller Abstraction Layer): Managing GPIO and Input Capture Unit (ICU), this layer ensures fundamental hardware control, enabling seamless interaction between software and microcontroller components.

# Getting Started
Connect the ATmega32 microcontroller with a frequency of 8MHz, HC-SR04 sensor, and 2x16 LCD in 4-bit data mode according to the specified hardware requirements.
Load the provided code onto the ATmega32 microcontroller.
Power up the system.
# Usage
The Ultrasonic sensor will measure distances and display them on the connected 2x16 LCD using 4-bit data mode.

# Contributing
If you would like to contribute to this project, please fork the repository and submit a pull request.

# Acknowledgments
Thanks to Engineering Mohamed Tarek for guidance and support during the development of this project.
