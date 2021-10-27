# Custom Electronics Example
This is example code for Custom Electronics Communication
The code for the Arduino/Teensy is located in \\Arduino Code\\TeensyCode\\TeensyCode.ino
The rest is the PROS Code for PROS 3.2.1

To setup your PROS Project to for custom electronics communication you need to

1. Setup the main.h file
* Include the pros\/apix.h
* Include okapi if using okapi
* Use namespace of choice
* Add cpp includes for \<iostream\>, \<string\>, \<sstream\>
* These are useful for receiving numbers from the Custom Electronics

2. Set up initialize
* Define the serial ports
* Flush the ports
* Set the Baud Rate

3. Start Communicating
* Send with write_byte
* Read with read_byte
