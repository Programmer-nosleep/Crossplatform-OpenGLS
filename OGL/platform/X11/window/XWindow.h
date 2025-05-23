#ifndef LINUX_PLATFORM_x86_64_H
#define LINUX_PLATFORM_x86_64_H

#include <cstdint>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class XWindow 
{
public:
  XWindow(int w, int h);
  ~XWindow();

  void InitializeDisplay();
  void CreateWindow();
  void ConfigureAttributes();
  void SetWindowHints();
  void SetWindowProperties();

  void Show();
  void RunEventLoop();

private:
  void* m_handler = nullptr;
  int width, height;
};

#endif
