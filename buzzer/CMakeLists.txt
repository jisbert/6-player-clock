add_library(buzzer_headers INTERFACE)

target_include_directories(buzzer_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(buzzer_headers INTERFACE compiler_flags)

add_library(buzzer INTERFACE)

target_sources(buzzer INTERFACE buzzer.cc)

target_link_libraries(buzzer INTERFACE compiler_flags buzzer_headers)