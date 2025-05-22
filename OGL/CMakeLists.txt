# CMakeList.txt : CMake project for OGL, include source and define
# project specific logic here.
#

file(GLOB SOURCE_FILES
	./main.cpp
)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows" OR WIN32)
  include_directories(platform/Win32)
  add_subdirectory(platform/Win32)
  # target_link_libraries(${PROJECT_NAME} PRIVATE Win32Platform)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux" OR UNIX)
  add_subdirectory(platform/Linux)
  # target_link_libraries(${PROJECT_NAME} PRIVATE X11Platform)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin" OR OSX)
  set(CMAKE_OBJCXX_STANDARD 17)
  enable_language(OBJCXX)
  add_subdirectory(platform/Cocoa)
endif()

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCE_FILES} "platform/App.h" "platform/App.cpp" "platform/Win32/context/OpenGLContext.cpp")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
	find_package(X11 REQUIRED)
	target_link_libraries(${PROJECT_NAME} PRIVATE X11::X11)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin" OR OSX)
  find_library(COCOA_LIBRARY Cocoa REQUIRED)
  target_link_libraries(${PROJECT_NAME} PRIVATE ${COCOA_LIBRARY})
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OGL PROPERTY CXX_STANDARD 17)
endif()

# TODO: Add tests and install targets if needed.
