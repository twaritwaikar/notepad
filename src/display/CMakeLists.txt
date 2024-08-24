add_library(
	display
	"cli_display.cpp"
)

target_include_directories(display PUBLIC ../)

target_link_libraries(display PUBLIC glm)
