add_library(mocks INTERFACE)
target_include_directories(mocks INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/button
)
target_sources(mocks INTERFACE
  button/button_handler_mock.cc
)