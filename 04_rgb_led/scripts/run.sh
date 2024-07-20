#!/bin/bash

# Default port
DEFAULT_PORT="/dev/cu.usbmodem101"

# Use the provided port or default to the specified port
PORT=${1:-$DEFAULT_PORT}

# Create build directory and navigate into it
mkdir -p build
cd build

# Run CMake with the custom toolchain file
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=../avr-gcc-toolchain.cmake ..

# Remove existing symlink if it exists
[ -L ../compile_commands.json ] && rm ../compile_commands.json

# Create symlink for neovim lspconfig clangd
ln -s build/compile_commands.json ../compile_commands.json

# Build the project
make

# Upload the program to the board
avrdude -c arduino -p m328p -P $PORT -b 115200 -U flash:w:rgb_led.hex:i

