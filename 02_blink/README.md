# Elegoo Uno R3 - Blink Led 

## Project setup

I am a programmer who loves their dev environment and want to make things as difficult as possible.
Also, because I despise bloated IDEs and want to vim it up, these are the things I did to be able to build and upload my programs 
to the Elegoo Uno R3 board.

### Install required tools

```zsh
brew tap osx-cross/avr
brew install avr-gcc avrdude
```

### Configure CMake

Due to issue with CMake on M3 MacOS, had to create a toolchain file and the traditional CMakeLists.txt file

- avr-gcc-toolchain.cmake

```
# avr-gcc-toolchain.cmake

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Specify the cross compiler
set(CMAKE_C_COMPILER avr-gcc)

# Define MCU and F_CPU
set(MCU atmega328p)
set(F_CPU 16000000UL)

# Set the compiler flags
set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os -Wall")
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os -Wall")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

# Remove default compiler flags that are not applicable to avr-gcc
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib")

# Specify the location of avr headers
include_directories(/opt/homebrew/opt/avr-gcc/avr/include)
```

- CMakeLists.txt

```
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(blink C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable
add_executable(blink.elf blink.c)

# Add a custom command to convert the ELF file to HEX file
add_custom_command(TARGET blink.elf POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom blink.elf blink.hex
    COMMENT "Converting ELF to HEX"
)
```

### Make build dir

```sh 
mkdir build && cd build
```

### Configure and Build the Project

```sh 
cmake -DCMAKE_TOOLCHAIN_FILE=../avr-gcc-toolchain.cmake ..
make
```

### Upload the Program to the Board

```sh 
avrdude -c arduino -p m328p -P <port> -b 115200 -U flash:w:blink.hex:i
```

#### To find the correct port on which your Elegoo Uno R3 board is connected, follow these steps:

1. Connect your Elegoo Uno R3 to your computer via the USB cable.

2. List Serial Ports:
Open a terminal and run the following command to list the serial devices:

```sh 
ls /dev/cu.*
```
Look for a device that matches the pattern /dev/cu.usbmodem* or /dev/cu.usbserial*

## Automating build and upload process

This script will run terminal commands from steps 4, 5, and 6. Automating the build and upload process.

### Create run.sh 

```sh
touch run.sh
```

### Contents of run.sh 

```sh
#!/bin/bash

# Default port
DEFAULT_PORT="/dev/cu.usbmodem101"

# Use the provided port or default to the specified port
PORT=${1:-$DEFAULT_PORT}

# Create build directory and navigate into it
mkdir -p build
cd build

# Run CMake with the custom toolchain file
cmake -DCMAKE_TOOLCHAIN_FILE=../avr-gcc-toolchain.cmake ..

# Build the project
make

# Upload the program to the board
avrdude -c arduino -p m328p -P $PORT -b 115200 -U flash:w:blink.hex:i

```

### Make the script executable by running:

```sh 
chmod +x run.sh
```

### Usage

To use the script with the default port /dev/cu.usbmodem101, simply run:

```sh 
./run.sh
```


If you need to use a different port, you can still provide it as an argument:

```sh 
./run.sh /dev/cu.otherport
```
