cmake_minimum_required(VERSION 3.3)

set(CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT notepad)

project(
    notepad
    LANGUAGES CXX
    VERSION 1.0
    DESCRIPTION "Text editor"
)

add_subdirectory(vendor)
add_subdirectory(src)
