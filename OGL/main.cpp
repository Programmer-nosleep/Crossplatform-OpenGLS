#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <string>

#ifdef _WIN32
#define UNICODE
#include <Windows.h>

#include <gl/GL.h>

#include "platform/Win32/window/Win32Window.h"
#elif defined (__unix__) || defined (__linux__)
#include <unistd.h>

#include <X11/X.h>
#include <X11/Xutil.h>

#include <GL/gl.h>
#include <GL/glx.h>

#include "platform/X11/window/XWindow.h"

#elif defined (__APPLE__) && defined (__MACH__)
#include <unistd.h>

#include "platform/Cocoa/window/Window.mm"
#endif


#if defined (_WIN32)
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
#endif

int main(int argc, char** argv)
{
#if defined (_WIN32)
	Win32Window CLASS_W32();

	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS wc = {};

	wc.lpfnWndProc	 = WindowProc;
	wc.hInstance	 = GetModuleHandle(NULL);
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowExW(
		0,
		CLASS_NAME,
		L"Learn to Program Windows",
		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);

	if (hwnd == NULL)
	{
		printf("Failed to get window handle.\n");
		return 0;
	}

	ShowWindow(hwnd, SW_SHOW);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
#elif defined (__unix__) || defined (__linux__)
  Display *ds;

  XSetWindowAttributes MyAtt;
  Window wnd;
  XSizeHints wmsize;
  XWMHints wmhints;
  XTextProperty wndName, iconName;

  XEvent myEvnt;

  char* title = (char*)"Sample Window Class";
  char* icon_name = (char*)"Ba";

  int screenNum, done;
  uint32_t valueMask;

  ds = XOpenDisplay(NULL);

  screenNum = DefaultScreen(ds);

  MyAtt.background_pixel = WhitePixel(ds, screenNum);
  MyAtt.border_pixel = BlackPixel(ds, screenNum);
  MyAtt.event_mask = ButtonPressMask;

  valueMask = CWBackPixel | CWBorderPixel | CWEventMask;

  wnd = XCreateWindow(
      ds,
      RootWindow(ds, screenNum),
      200, 200, 600, 500, 2,
      DefaultDepth(ds, screenNum),
      InputOutput,
      DefaultVisual(ds, screenNum),
      valueMask,
      &MyAtt      
  );

  wmsize.flags = USPosition | USSize;
  XSetWMNormalHints(ds, wnd, &wmsize);

  wmhints.initial_state = NormalState;
  wmhints.flags = StateHint;

  XSetWMHints(ds, wnd, &wmhints);
  XStringListToTextProperty(&title, 1, &wndName);
  XSetWMName(ds, wnd, &wndName);

  XStringListToTextProperty(&icon_name, 1, &iconName);
  XSetWMIconName(ds, wnd, &iconName);
  XMapWindow(ds, wnd);

  done = 0;

  while (done == 0)
  {
    XNextEvent(ds, &myEvnt);
    switch (myEvnt.type)
    {
      case ButtonPress:
        break;
    }
  }

  XUnmapWindow(ds, wnd);
  XDestroyWindow(ds, wnd);
  XCloseDisplay(ds);
  
  return 0;
#elif defined (__APPLE__) && defined (__MACH__)
	@autoreloeasepool
	{
		NSLog(@"Hello, World!");
	}
#else
	printf("Hello, World!");
#endif
}

#if defined (_WIN32)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
#endif
