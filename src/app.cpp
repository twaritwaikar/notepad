#include "app.h"

void App::add_notepad(Notepad&& notepad) {
	_notepad_instances.emplace_back(notepad);
}

int32_t App::run()
{
	_stale_notepads.reserve(_notepad_instances.size());

	for (auto& notepad_instance : _notepad_instances) {
		if (notepad_instance.poll_inputs()) {
			_stale_notepads.push_back(&notepad_instance);
		}
	}

	for (auto& stale_notepad : _stale_notepads) {
		_stale_notepad.render();
	}

	return 0;
}
