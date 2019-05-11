INTRODUCTION 

The Arduino UNO is an open-source microcontroller board based on the Microchip ATmega328P microcontroller and developed by Arduino.cc.
Arduino does not support isolated parallel tasks (Threads), but we can make the main loop switch function execution conditionally and thus simulate threading with Protothread mechanism.
A protothread is a low-overhead mechanism for concurrent programming.
Protothreads function as stackless, lightweight threads, or coroutines, providing a blocking context cheaply using minimal memory per protothread (on the order of single bytes).
Protothreads are used to accomplish a non-preempted form of concurrency known as cooperative multitasking and, therefore, do not incur context switch when yielding to another thread.

OBJECTIVES
The main objective of the project is to run multiple threads on the Arduino Uno by using protothreading mechanism. The project runs 6 threads, all of which perform a singular function: 
1.	Thread 1 (Red LED Thread): Flashes a red LED at an interval of 500 microseconds
2.	 Thread 2 (Green LED Thread): Flashes a green LED at an interval of 1000 microseconds
3.	Thread 3 (Blue LED Thread): Flashes a blue LED at an interval of 2000 microseconds
4.	Thread 4 (Music Thread): Plays the opening few seconds of the “Infinity War” theme song at an interval of 20000 microseconds (20 seconds)
5.	Thread 5 (LCD Thread 1): Flashes the message “OS Project” in the first row of the LCD at an interval of 200 microseconds (plus a delay of 200 microseconds)
6.	Thread 2 (LCD Thread 2): Shows the number of threads in row 2 of the LCD

EQUIPMENTS
The following equipment is used to create the setup for the project: 
•	Arduino Uno
•	16 By 2 Liquid Crystal Display (LCD)
•	Piezo Electric Sensor 
•	3 LED’s (Light Emitting Diodes) 
•	Resistors
•	Jumper Cables
•	Breadboard 
•	Potentiometer 
•	USB Cable 

IMPLEMENTATION
Library Used: https://github.com/ivanseidel/ArduinoThread
This library implements it and helps you to:
•	schedule, manage and simplify parallel, periodic tasks
•	define fixed or variable time between runs
•	organize the code in any type of project
•	put all sensor readings in a thread
•	keep the main loop clean
•	hide the complexity of thread management
•	run "pseudo-background" tasks using Timer interrupts

There are three main classes included in the library:
Thread, ThreadController and StaticThreadController (both controllers inherit from Thread). I have made use of only the Thread class. 
Thread: Basic class, which contains methods to set and run callbacks, check if the Thread should be run, and also creates a unique ThreadID on the instantiation.
LiquidCrystal library has also been used to run the LCD. 

Music Threads 
The music has been created by changing the frequencies being input to the piezo sensor. 

The following notes have been used: 
https://pianoletternotes.blogspot.com/2018/05/the-avengers-infinity-war-main-theme.html

The frequencies for the corresponding notes are as follows (taken from the following link: https://www.intmath.com/trigonometric-graphs/music.php) 

OUTPUT
Through protothreading, the Arduino Uno is able to achieve concurrency and hence the “illusion of multi-threading” is achieved. (https://drive.google.com/file/d/1Ub10pypvVl9dutX0uUGXMh2mRyjFJhZi/view?usp=drivesdk)
