#include <iostream>

#if defined (_WIN32)
#include "platform/App.h"

#elif defined (__unix__) || defined (__linux__)
#include <unistd.h>

#include <X11/X.h>
#include <X11/Xutil.h>

#endif

int main(int argc, char** argv)
{
#if defined (_WIN32)
    App app(GetModuleHandle(nullptr));
    
    return app.runner();
#elif defined (__unix__) || defined (__linux__)
    

    return app.runner();
#elif defined (__APPLE__) && defined (__MACH__)
    @autoreloeasepool
    {
    	NSLog(@"Hello, World!");
    }
#else
	printf("Hello, World!");
#endif
}
