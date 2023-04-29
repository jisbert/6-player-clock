add_library(mocks INTERFACE)
target_include_directories(mocks INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_sources(mocks INTERFACE
  src/button/button_controller_mock.cc
  src/button/button_event_handler_mock.cc
  src/buzzer/buzzer_mock.cc
  src/clock/clock_mock.cc
  src/display/display_mock.cc
  src/hardware/gpio_mock.cc
  src/hardware/irq_mock.cc
)
