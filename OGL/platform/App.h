#ifndef APP_H
#define APP_H

#include <cstdint>
#include <memory>

#ifdef _WIN32
#include <Windows.h>
#include <gl/GL.h>

#include "Win32/window/Win32Window.h"
#include "Win32/context/OpenGLContext.hpp"
#elif defined (__linux__) || defined (__unix__)
#include <unistd>

#include <X11/X.h>
#include <X11/Xutil.h>
#elif defined (__APPLE__) || defined (__MACH__)
#include <unistd.h>

#endif
class App
{
public:
#if defined (_WIN32)
	App(HINSTANCE hInst);
	~App() = default;

	int runner(); 
#elif defined (__linux__)

#else

#endif
private:
#if defined (_WIN32)
	std::unique_ptr<Win32Window> m_window;
	std::unique_ptr<OpenGLContext> m_GlContext;
#elif defined (__linux__)

#else

#endif
};

#endif