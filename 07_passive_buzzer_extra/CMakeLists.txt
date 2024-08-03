cmake_minimum_required(VERSION 3.10)
project(Digital_Inputs C)

# Include the AVR toolchain file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/avr-gcc-toolchain.cmake)

# Add the source files
add_executable(main.elf src/main.c)

# Define the hex file
add_custom_command(TARGET main.elf
    POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom main.elf main.hex
    COMMENT "Creating Intel Hex file")

# Specify the include directories for this target
target_include_directories(main.elf PRIVATE /opt/homebrew/opt/avr-gcc/avr/include)

# Explicitly set C flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I/opt/homebrew/opt/avr-gcc/avr/include")
