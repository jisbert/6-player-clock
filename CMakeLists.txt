cmake_minimum_required(VERSION 3.25)

# Set board to pico
set(PICO_BOARD pico CACHE STRING "Board type")

# Enable tests
option(ENABLE_TESTS "Enable tests" ON)

# Enable coverage
option(ENABLE_COVERAGE "Enable coverage")

# Enable host platform for tests.
# Must come before importing pico sdk.
# TODO: conditionally enable when compiler is not Arm CC.
#       Not sure about how to accomplish this, cause CMAKE_<LANG>_COMPILER_ID is populated only after project and this must come before
if(ENABLE_TESTS OR ENABLE_COVERAGE)
  set(PICO_PLATFORM host CACHE STRING "Plataform type")
  set(CMAKE_BUILD_TYPE Debug)
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

add_library(components INTERFACE)
target_link_libraries(components INTERFACE compiler_flags)
target_include_directories(components INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_sources(components INTERFACE
  src/button/button_controller.cc
  src/button/button_event.cc
  src/button/button_event_handler.cc
  src/button/button_setup.cc
  src/buzzer/buzzer.cc
)

add_executable(6_player_clock src/app.cc)
target_link_libraries(6_player_clock
  compiler_flags
  pico_stdlib
  components
)
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

if (ENABLE_COVERAGE)
  set(CMAKE_MODULE_PATH cmake ${CMAKE_MODULE_PATH})
  include(CodeCoverage)
endif()
if(ENABLE_TESTS OR ENABLE_COVERAGE)
  add_subdirectory(tests)
endif()
