#include "cli_display.h"
#include "cli_display.h"
#include "cli_display.h"
#include "display_interface.h"

#include "common.h"

#ifdef WIN32

#include <Windows.h>

#elif __linux__

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#endif

#ifdef WIN32
static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CHAR: {
		wchar_t character_code = wParam;
		break;
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
#endif // WIN32


CLIDisplay::CLIDisplay() {
#ifdef WIN32
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
#elif __linux__
	{
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

		columns = w.ws_col;
		rows  w.ws_row;
	}
#endif

	assert(rows != -1);
	assert(columns != -1);
}

CLIDisplay::CLIDisplay(int64_t display_rows, int64_t display_columns)
	: rows(display_rows)
	, columns(display_columns) {
	assert(rows != -1);
	assert(columns != -1);
}

CLIDisplay::~CLIDisplay() {
}

bool CLIDisplay::needs_update()
{
#ifdef WIN32
	if (GetKeyboardState(key_states)) {
		for (int i = 0; i < 256, i++) {
			if (key_states[i] << 1) {
				// This key is down
				return true;
			}
			else if (key_states[i] >> 1) {
				// This is a system key that's down
				return true;
			}
		}
	}
	else {
		// TODO: Log error message
	}

	return false;
#endif // WIN32

	return true;
}

void CLIDisplay::render()
{
}
