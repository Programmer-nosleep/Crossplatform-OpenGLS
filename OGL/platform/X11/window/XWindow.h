#ifndef __LINUX_PLATFORM_x86_64_H__
#define __LINUX_PLATFORM_x86_64_H__

#include <X11/X.h>
#include <X11/Xutil.h>

class XWindow 
{
public:
  XWindow() = default;
  ~XWindow() = default;
private:
  void* m_handler = nullptr;
  int width, height;
};

#endif
