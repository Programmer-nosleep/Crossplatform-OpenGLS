#include "App.h"
#define UNICODE

#include <Windows.h>
#include <gl/GL.h>

App::App(HINSTANCE hInst)
{
	m_window = std::make_unique<Win32Window>(hInst, 500, 400, "OpenGL");
	m_GlContext = std::make_unique<OpenGLContext>(m_window->GetHWND());
}

int App::runner()
{
	if (m_window == NULL)
	{
		return -1;
	}

	while (m_window->ProcessMessages())
	{
		glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		m_GlContext->SwapBuffer();
	}

	return 0;
}