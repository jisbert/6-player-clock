add_executable(tests src/tests_app.cc
  src/button/button_controller_tests.cc
  src/button/button_event_handler_tests.cc
  src/buzzer/buzzer_tests.cc
)
target_link_libraries(tests PRIVATE
  compiler_flags
  CppUTest
  CppUTestExt
  mocks
  headers
  sources
)
if(ENABLE_COVERAGE)
  target_compile_options(tests PRIVATE --coverage -O0)
  target_link_options(tests PRIVATE --coverage)
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE tests
    DEPENDENCIES tests
    BASE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    EXCLUDE tests/*
  )
endif()
add_subdirectory(mocks)
