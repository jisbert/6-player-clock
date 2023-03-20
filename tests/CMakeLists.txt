set(PICO_BOARD host CACHE STRING "Board type")

project(timer_components_tests VERSION 0.1 LANGUAGES C CXX ASM)

pico_sdk_init()

add_subdirectory(lib/cpputest)
add_subdirectory(gont/pico)