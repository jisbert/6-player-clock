add_executable(tests src/6_player_clock_tests.cc
  src/button/button_controller_tests.cc
  src/button/button_tests.cc
  src/buzzer/buzzer_tests.cc
  src/clock/clock_tests.cc
  src/player/context_switcher_tests.cc
)
target_link_libraries(tests PRIVATE
  compiler_flags
  CppUTest
  CppUTestExt
  mocks
  components
)
if(ENABLE_COVERAGE)
  target_compile_options(tests PRIVATE --coverage -O0)
  target_link_options(tests PRIVATE --coverage)
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE tests
    DEPENDENCIES tests
    BASE_DIRECTORY ${PROJECT_SOURCE_DIR}
    EXCLUDE tests/* /usr/*
  )
endif()
add_subdirectory(mocks)
