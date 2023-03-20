add_executable(6_player_timer 6_player_timer.cpp)

target_link_libraries(6_player_timer pico_stdlib timer_components)

target_include_directories(6_player_timer PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

pico_set_program_name(6_player_timer "6_player_timer")
pico_set_program_version(6_player_timer "0.1")

# Enable UART, disable USB
pico_enable_stdio_uart(6_player_timer 1)
pico_enable_stdio_usb(6_player_timer 0)

# Generate elf files
pico_add_extra_outputs(6_player_timer)

add_subdirectory(gont/pico)