# Define the name of the CMake system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Define the C and C++ compilers
set(CMAKE_C_COMPILER avr-gcc)

# Define the target platform and CPU frequency
set(AVR_MCU atmega328p)
set(F_CPU 16000000UL)

# Set compiler and linker flags
set(CMAKE_C_FLAGS "-mmcu=${AVR_MCU} -DF_CPU=${F_CPU} -Wall -Os")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections")

# Define the root path for finding AVR tools and includes
set(CMAKE_FIND_ROOT_PATH /opt/homebrew/opt/avr-gcc)

# Set CMake to search the root path for headers and libraries
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
