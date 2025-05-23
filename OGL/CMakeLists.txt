# CMakeList.txt : CMake project for OGL
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
file(GLOB SOURCE_FILES
    main.cpp
    platform/App.cpp
)

file(GLOB HEADER_FILES
    platform/App.h
)
else()
file(GLOB SOURCE_FILES
    main.cpp
)
endif()


# Add platform subdirectory for window and context implementations
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
add_subdirectory(platform)
endif()

# Add source to this project's executable
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
else()
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif()

# Platform specific configurations
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} PRIVATE
        RenderGl
        opengl32
        gdi32
        user32
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        # RenderGl
        X11::X11
        OpenGL::GL
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        RenderGl
        ${COCOA_LIBRARY}
        OpenGL::GL
    )
endif()

# Set C++ standard
if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
endif()

# TODO: Add tests and install targets if needed.
