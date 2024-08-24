add_subdirectory(display)

add_executable(
    notepad
    "main.cpp"
)

target_link_libraries(
    notepad
    PUBLIC
    display
)
