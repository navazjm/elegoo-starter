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

