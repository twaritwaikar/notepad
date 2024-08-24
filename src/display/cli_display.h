#pragma once

#include "inttypes.h"
#include "display_interface.h"

class CLIDisplay : public DisplayInterface {
	void register_key_down(wchar_t key_code);

public:
	int64_t rows = -1;
	int64_t columns = -1;

	wchar_t key_states[256] = {};

	CLIDisplay();
	CLIDisplay(int64_t display_rows, int64_t display_columns);
	~CLIDisplay();

	bool needs_update() override;
	void render() override;
};
