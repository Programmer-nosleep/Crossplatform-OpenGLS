# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)
project ("Crossplatform-OpenGLS" LANGUAGES C CXX)

# Enable Hot Reload for MSVC compilers if supported.
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(CMAKE_CXX_COMPILER STREQUAL "MSVC")
  	if (POLICY CMP0141)
  	  cmake_policy(SET CMP0141 NEW)
  	  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  	endif()
  elseif(CMAKE_CXX_COMPILER STREQUAL "Clang")

  endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
endif()

# Include sub-projects.
add_subdirectory ("OGL")
