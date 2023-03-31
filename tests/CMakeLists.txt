add_executable(6_player_clock_test 6_player_clock_test.cc)

target_link_libraries(6_player_clock_test compiler_flags CppUTest CppUTestExt button_headers buzzer) # Change buzzer for buzzer_headers

add_subdirectory(button)
add_subdirectory(buzzer)
