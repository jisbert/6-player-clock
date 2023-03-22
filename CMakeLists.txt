cmake_minimum_required(VERSION 3.25)

# Set board to pico
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(6_player_clock VERSION 0.1 LANGUAGES C CXX ASM)

# Enable host platform for tests. Conditionally enable when compiler is not Arm CC.
# I was not able to accomplish this with generator expressions set(PICO_PLATFORM $<IF:$<COMPILE_LANG_AND_ID:CXX,ARMCC>host,rp2040>)
if(NOT ${CMAKE_ARMCC_COMPILER_ID})
  set(PICO_PLATFORM host)
endif()

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(6_player_clock 6_player_clock.cc)

add_library(compiler_flags INTERFACE)
target_compile_definitions(compiler_flags INTERFACE c_std_11 cxx_std_17)

target_link_libraries(6_player_clock compiler_flags pico_stdlib buzzer)

target_include_directories(6_player_clock PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

pico_set_program_name(6_player_clock "6_player_clock")
pico_set_program_version(6_player_clock "0.1")

# Enable UART, disable USB
pico_enable_stdio_uart(6_player_clock 1)
pico_enable_stdio_usb(6_player_clock 0)

# Generate elf files
pico_add_extra_outputs(6_player_clock)

add_subdirectory(buzzer)
add_subdirectory(tests)