#include "Win32Window.h"
#define UNICODE

#include <cstdio>
#include <cstdint>

#include <Windows.h>
#include <gl/GL.h>

Win32Window::Win32Window(HINSTANCE hInstance, int w, int h, LPCWSTR name)
	: width(w), height(h)
{
	LPCWSTR CLASS_NAME = L"Sample Window Class";
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	m_handler = CreateWindowExW(
		0,
		CLASS_NAME,
		name,
		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	if (m_handler == NULL)
	{
		printf("Failed to get window handle.\n");
		DestroyWindow(m_handler);
	}

	ShowWindow(m_handler, SW_SHOW);
}

bool Win32Window::ProcessMessages()
{
	MSG msg = {};

	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return false;
			
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}

LRESULT CALLBACK Win32Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

HWND Win32Window::GetHWND() const
{
	return m_handler;
}

Win32Window::~Win32Window()
{
	if (m_handler)
	{
		DestroyWindow(m_handler);
	}
}