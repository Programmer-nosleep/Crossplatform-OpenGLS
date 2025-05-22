#ifndef WINDOWS_PLATFORM_x86_64_H
#define WINDOWS_PLATFORM_x86_64_H
#define UNICODE

#include <string>

#include <Windows.h>

class Win32Window
{
public:
	Win32Window(HINSTANCE, int, int, const std::string&);
	~Win32Window();

	bool ProcessMessages();

	HWND GetHWND() const;

private:
	HWND m_handler = nullptr;
	int width, height;

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif
