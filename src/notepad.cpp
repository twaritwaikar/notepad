#include "notepad.h"

Notepad::Notepad(std::unique_ptr<DisplayInterface> display)
	: _display(std::move(display))
{
}

Notepad::~Notepad() {
}
