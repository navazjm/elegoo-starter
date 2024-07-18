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

