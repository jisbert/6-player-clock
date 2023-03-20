add_executable(6_player_clock_test 6_player_clock_test.cc)

target_link_libraries(6_player_clock_test CppUTest buzzer)

add_subdirectory(buzzer)
