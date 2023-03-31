add_executable(tests src/tests_main.cc
  src/button/button_handler_tests.cc
  src/buzzer/buzzer_tests.cc
)
target_link_libraries(tests
  compiler_flags
  CppUTest
  CppUTestExt
  headers
  sources
  mocks
)
add_subdirectory(mocks)