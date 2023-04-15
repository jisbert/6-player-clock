add_library(mocks INTERFACE)
target_include_directories(mocks INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_sources(mocks INTERFACE
  src/button/button_event_handler_mock.cc
)
