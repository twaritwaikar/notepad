add_subdirectory(display)

add_executable(
    notepad
    "notepad.cpp"
    "app.cpp"
    "main.cpp"
)

target_include_directories(notepad PUBLIC ./)

target_link_libraries(
    notepad
    PUBLIC
    display
)
