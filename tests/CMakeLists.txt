cmake_minimum_required(VERSION 3.25)

project(6_player_clock_tests VERSION 0.1 LANGUAGES C CXX ASM)

add_executable(6_player_clock_test 6_player_clock_test.cc)

target_link_libraries(6_player_clock_test CppUTest buzzer_test)

add_subdirectory(buzzer)