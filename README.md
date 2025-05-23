# OGL (OpenGL Cross-Platform Project Study Case)

This project is a cross-platform OpenGL implementation that supports multiple operating systems, including **Windows**, **Linux**, and **macOS**.

## 📋 System Requirements

- [CMake](https://cmake.org/) version **3.15** or higher
- A C++ compiler supporting:
  - **MSVC** (for Windows).
  - **Clang** (optional for Linux/macOS).
- **OpenGL** version **3.3** or higher.
- **libx11** (Linux) or **XQuartz** (macOS).
- (Planned) Native Cocoa Objective-C runtime for macOS.

## 📁 Project Structure
```powershell
Crossplatform-OpenGLS
│
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
└── OGL
    ├── CMakeFiles
    └── platform
        ├── Cocoa
        ├── Win32
        │   ├── context
        │   ├── core
        │   ├── input
        │   └── window
        └── X11
            ├── context
            ├── core
            ├── input
            └── window
```

## ✨ Features

- Hot Reload support for MSVC compiler
- Optimized Debug Information Format
- Cross-platform: Windows / Linux / macOS
- Auto-configured build and output directories

## 🛠️ Build Instructions

### 🪟 Windows (Visual Studio)

1. Generate the Visual Studio project:
    ```powershell
    cmake -B build -G "Visual Studio 17 2022"
    ```

2. Run the application:
    ```powershell
    out/build/x64-debug/OGL/Crossplatform-OpenGLS.exe
    ```

### 🐧 Linux (GCC/Clang)

1. Create a build directory:
    ```bash
    cmake -B build .
    ```

2. Navigate into it:
    ```bash
    cd build
    ```

3. Run the application:
    ```bash
    ./Crossplatform-OpenGLS
    ```

### 🍎 macOS (Planned)

Support for macOS using **Cocoa** and **XQuartz** is planned. The build process will include:

- CMake generation with Xcode:
    ```bash
    cmake -B build -G "Xcode"
    ```

- Linking with Cocoa and OpenGL frameworks
- Running via native Objective-C integration

## 📌 Notes

- Windows build output is placed in `build/Debug/` or `out/build/x64-debug/OGL/`
- Linux build output is placed in `build/` by default
- macOS output location and instructions will be added soon

---

Feel free to open issues or contribute to improving cross-platform support!
