#pragma once

#include <vector>

#include "notepad.h"

class App {
	std::vector<Notepad> _notepad_instances;
	std::vector<Notepad*> _stale_notepads;

public:
	void add_notepad(Notepad&& notepad);

	int32_t run();
};
