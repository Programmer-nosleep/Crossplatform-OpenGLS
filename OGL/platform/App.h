#ifndef APP_H
#define APP_H

#include <memory>

#include "Win32/window/Win32Window.h"
#include "context/OpenGLContext.hpp"

class App
{
public:
	App(HINSTANCE hInst);
	~App() = default;

	int runner(); 

private:
	std::unique_ptr<Win32Window> m_window;
	std::unique_ptr<OpenGLContext> m_GlContext;
};

#endif