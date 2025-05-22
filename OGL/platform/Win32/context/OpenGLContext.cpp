#include "OpenGLContext.hpp"
#define UNICODE

#include <Windows.h>
#include <gl/GL.h>

OpenGLContext::OpenGLContext(HWND hwnd)
	: m_handler(hwnd)
{
	m_hdc = GetDC(hwnd);

	PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1 };
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;

	int format = ChoosePixelFormat(m_hdc, &pfd);
	SetPixelFormat(m_hdc, format, &pfd);

	m_hglrc = wglCreateContext(m_hdc);
	wglMakeCurrent(m_hdc, m_hglrc);
}

void OpenGLContext::SwapBuffer() const
{
	::SwapBuffers(m_hdc);
}