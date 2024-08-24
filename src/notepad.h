#pragma once

#include <memory>

#include "display/display_interface.h"

class Notepad {
	std::unique_ptr<DisplayInterface> _display = nullptr;

public:
	Notepad(std::unique_ptr<DisplayInterface> display);
	~Notepad();

	// Return if the window received a user input
	bool poll_inputs() {
		return _display->needs_update();
	}
};
