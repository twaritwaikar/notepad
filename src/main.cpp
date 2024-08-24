#include <iostream>

#include "display/cli_display.h"
#include "notepad.h"

int main() {
	Notepad notepad(std::make_unique<CLIDisplay>());


	return 0;
}
