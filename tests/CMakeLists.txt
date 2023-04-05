add_executable(tests src/tests_app.cc
  src/button/button_handler_tests.cc
  src/buzzer/buzzer_tests.cc
)
target_link_libraries(tests PRIVATE
  compiler_flags
  CppUTest
  CppUTestExt
  headers
  sources
  mocks
)
if(ENABLE_COVERAGE)
  target_compile_options(tests PRIVATE --coverage -O0)
  target_link_options(tests PRIVATE --coverage)
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE tests
    DEPENDENCIES tests
    BASE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    EXCLUDE tests/mocks/*
  )
endif()
add_subdirectory(mocks)