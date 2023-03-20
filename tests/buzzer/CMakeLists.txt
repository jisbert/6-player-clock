add_library(buzzer_test buzzer_test.cc)

target_include_directories(buzzer_test INTERFACE ${CMAKE_SOURCE_DIR}/../buzzer)

target_link_libraries(buzzer_test CppUTest buzzer)