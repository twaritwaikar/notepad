#pragma once

#include "inttypes.h"
#include "display_interface.h"

class CLIDisplay : public DisplayInterface {
	int64_t window_size = 0;
	int64_t window_length = 0;

public:
	CLIDisplay();
	~CLIDisplay();
};
