add_library(buzzer buzzer.cc)

target_include_directories(buzzer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(compiler_flags)