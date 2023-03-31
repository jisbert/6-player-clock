cmake_minimum_required(VERSION 3.25)

# Set board to pico
set(PICO_BOARD pico CACHE STRING "Board type")

# Enable tests
option(ENABLE_TESTS "Enable tests" ON)

# Enable host platform for tests.
# Must come before importing pico sdk.
# TODO: conditionally enable when compiler is not Arm CC.
#       Not sure about how to accomplish this, cause CMAKE_<LANG>_COMPILER_ID is populated only after project and this must come before
if(ENABLE_TESTS)
  set(PICO_PLATFORM host CACHE STRING "Plataform type")
endif()

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)
if(PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(6_player_clock VERSION 0.1 LANGUAGES C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_library(compiler_flags INTERFACE)
target_compile_definitions(compiler_flags INTERFACE c_std_11 cxx_std_17)

add_library(headers INTERFACE)
target_include_directories(headers INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/button
  ${CMAKE_CURRENT_SOURCE_DIR}/include/buzzer
)
target_link_libraries(headers INTERFACE compiler_flags)

add_library(sources INTERFACE)
target_sources(sources INTERFACE
  src/button/button_controller.cc
  src/buzzer/buzzer.cc
)
target_link_libraries(sources INTERFACE compiler_flags)

add_executable(6_player_clock src/app.cc)
target_include_directories(6_player_clock PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)
target_link_libraries(6_player_clock
  compiler_flags
  pico_stdlib
  headers
  sources
)

pico_set_program_name(6_player_clock "6_player_clock")
pico_set_program_version(6_player_clock "0.1")

# Enable UART, disable USB
pico_enable_stdio_uart(6_player_clock 1)
pico_enable_stdio_usb(6_player_clock 0)

# Generate elf files
pico_add_extra_outputs(6_player_clock)

if(ENABLE_TESTS)
  add_subdirectory(tests)
endif()