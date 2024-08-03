# Lesson 7 Passive Buzzer Extra 

## Table of Contents
- [Extra Challenge](#extra-challenge)
    - [Requirements](#requirements)
    - [Images](#images)
- [Build and Upload Process to Elegoo Uno R3](#build-and-upload-process-to-elegoo-uno-r3)
    - [Run Script](#run-script)
        - [usage](#usage)
    - [Run Manually](#run-manually-with-cmake)

## Extra Challenge

Now that I have made it through a few lessons, I want to start doing my own little side projects apart
from the main lessons to get a better understanding of how things work. For this side quest,
I want to modify lesson 07 to add a button that allows the musical melody to be replayed. Currently,
for lesson 07, the musical melody only plays once after running the run script.

### Requirements

#### MVP

Be able to toggle on/off the musical melody using the push switch.

Melody does not start until the user presses the button. Once the user presses the button, it should play
the melody. Continue to play the melody until the user presses the button again. 

#### Components

- (1) Elegoo Uno R3
- (1) 830 Tie-points Breadboard
- (1) Passive Buzzer
- (1) Push Switch
- (5) M-M Wires
- (2) F-M wires

### Images

#### Outcome

<img src="./images/outcome_1.png" alt="Final Result" width="300">

## Build and Upload Process to Elegoo Uno R3

### Run Script

The `run.sh` script automates the process of running shell commands to build and upload the process 
to the Elegoo Uno R3. 

#### Usage

*NOTE: Make sure you are in the root directory of the lesson 6 before running the script.*

To use the script with the default port /dev/cu.usbmodem101, simply run:

```sh 
./scripts/run.sh
```

If you need to use a different port, you can still provide it as an argument:

```sh 
./scripts/run.sh /dev/cu.otherport
```

### Run Manually with CMake

1. Create build directory and navigate into it

```sh 
mkdir -p build && cd build
```

2. Run CMake with the custom toolchain file

```sh 
cmake -DCMAKE_TOOLCHAIN_FILE=../avr-gcc-toolchain.cmake ..
```

3. Build the project

```sh 
make
```

4. Upload the program to the board

```sh 
avrdude -c arduino -p m328p -P $PORT -b 115200 -U flash:w:main.hex:i
```
