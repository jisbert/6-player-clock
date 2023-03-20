add_executable(timer_components_tests all_tests.cpp buzzer_tests.cpp)

target_link_libraries(timer_components_tests CppUTest timer_components)

target_link_options(timer_components_tests PUBLIC --specs=nosys.specs)