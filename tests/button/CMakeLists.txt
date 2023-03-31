target_include_directories(6_player_clock_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/mock/include)

target_sources(6_player_clock_test PRIVATE button_handler_test.cc mock/button_handler_mock.cc)