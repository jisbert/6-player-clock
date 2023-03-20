add_library(timer_components
  buzzer.cpp
  ${PROJECT_SOURCE_DIR}/include/gont/pico/buzzer.hpp
)

target_include_directories(timer_components PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/gont/pico>
  $<INSTALL_INTERFACE:include>
)