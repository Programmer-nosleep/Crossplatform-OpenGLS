#ifndef OPENGL_CONTEXT_HPP
#define OPENGL_CONTEXT_HPP
#define UNICODE

#include <Windows.h>

class OpenGLContext
{
public:
	OpenGLContext(HWND hwnd);
	~OpenGLContext() = default;

	void SwapBuffer() const;

private:
	void* m_handler = nullptr;

	HDC m_hdc;
	HGLRC m_hglrc;
};

#endif