cmake_minimum_required(VERSION 3.10)
project(RBG_LED C)

# Include the AVR toolchain file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/avr-gcc-toolchain.cmake)

# Add the source files
add_executable(rgb_led.elf src/rgb_led.c)

# Define the hex file
add_custom_command(TARGET rgb_led.elf
    POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom rgb_led.elf rgb_led.hex
    COMMENT "Creating Intel Hex file")

# Specify the include directories for this target
target_include_directories(rgb_led.elf PRIVATE /opt/homebrew/opt/avr-gcc/avr/include)

# Explicitly set C flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I/opt/homebrew/opt/avr-gcc/avr/include")
