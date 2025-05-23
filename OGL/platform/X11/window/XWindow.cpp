#include "XWindow.h"

XWindow::XWindow(int w, int h)
  : width(w), height(h)
{
    Display* ds;

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
}

XWindow::~XWindow()
{
}