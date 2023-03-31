add_library(button_headers INTERFACE)

target_include_directories(button_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(button_headers INTERFACE compiler_flags)

add_library(button INTERFACE)

target_sources(button INTERFACE button_controller.cc)

target_link_libraries(button INTERFACE compiler_flags button_headers)