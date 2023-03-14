# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH CACHE PATH "/usr/lib/pico-sdk")

# Set board to pico
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(6_player_timer C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(6_player_timer 6_player_timer.cpp)

# Add the standard library to the build
target_link_libraries(6_player_timer pico_stdlib)

# Add the standard include files to the build
target_include_directories(6_player_timer PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add main
add_subdirectory(src)

# Add main source
add_subdirectory(test)

# Set project name and version
pico_set_program_name(6_player_timer "6_player_timer")
pico_set_program_version(6_player_timer "0.1")

# Enable UART, disable USB
pico_enable_stdio_uart(6_player_timer 1)
pico_enable_stdio_usb(6_player_timer 0)

# Generate elf files
pico_add_extra_outputs(6_player_timer)
