#ifndef __WINDOWS_PLATFORM_x86_64_H__
#define __WINDOWS_PLATFORM_x86_64_H__
#define UNICODE

#include <cstdint>

#include <Windows.h>
#include <gl/GL.h>

class Win32Window
{
public:
	Win32Window() = default;
	~Win32Window() = default;

	void render();

private:
	void* m_handler = nullptr;
	int width, height;
};

#endif
