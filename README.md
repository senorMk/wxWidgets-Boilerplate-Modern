# wxWidgets Boilerplate Modern

A small C++17 GUI starter for Windows, macOS, and Linux. This project updates
[senorMk/wxWidgets-Boilerplate](https://github.com/senorMk/wxWidgets-Boilerplate)
and keeps its Git history and wxCrafter design.

## Requirements

- CMake 3.24 or later.
- A C++17 compiler: Visual Studio 2022 with Desktop development with C++, Apple
  Command Line Tools, or GCC/Clang on Linux.
- Internet access for the first configure step.
- On Ubuntu, install the native GUI dependencies:

```sh
sudo apt-get update
sudo apt-get install -y build-essential cmake libgtk-3-dev libgl1-mesa-dev libglu1-mesa-dev
```

CMake downloads and checks the SHA-256 hash of wxWidgets 3.2.12, then builds it
as a static library. The first build can take several minutes.

## Build

```sh
git clone https://github.com/senorMk/wxWidgets-Boilerplate-Modern.git
cd wxWidgets-Boilerplate-Modern
cmake --preset debug
cmake --build --preset debug --parallel 3
```

Use `release` in place of `debug` for a Release build. CMake selects the default
build tool for your platform. You can also open this folder in Visual Studio
or an editor with CMake support.

## Run

```sh
# macOS
open build/debug/wxwidgets_boilerplate.app

# Linux
./build/debug/wxwidgets_boilerplate
```

For the default Visual Studio generator on Windows:

```powershell
.\build\debug\Debug\wxwidgets_boilerplate.exe
```

The window has Exit and Minimize buttons. Exit uses the window close event.
Minimize reduces the window to an icon.

## Test

```sh
ctest --preset debug
```

The smoke test starts the GUI and sends the Exit button event. It fails if the
application returns an error or does not close within 20 seconds. It needs a
GUI session. For a Linux machine without a display:

```sh
sudo apt-get install -y xvfb
xvfb-run -a ctest --preset debug
```

GitHub Actions builds Debug and Release configurations on Windows, macOS, and
Linux, then runs the smoke test. This test does not check the window appearance
or the Minimize action. Check these manually after you change the GUI.

## Use an installed wxWidgets library

Install wxWidgets 3.2 or later, including its development files and XRC library.
Use a separate build folder:

```sh
cmake -S . -B build/system -DBOILERPLATE_USE_SYSTEM_WX=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build/system --config Debug --parallel 3
ctest --test-dir build/system -C Debug --output-on-failure
```

On Unix, `wx-config` must be on `PATH`. On Windows, you can set
`wxWidgets_ROOT_DIR` to your wxWidgets installation. The compiler, architecture,
and build configuration must match the installed library.

## Change the application

- `App.cpp` and `App.h`: startup, command-line options, and image handlers.
- `AppFrame.cpp` and `AppFrame.h`: application actions. Add event handlers here.
- `AppFrameBase.wxcp`: open this design in wxCrafter to change the GUI.
- `AppFrameBase.*` and `AppFrameBase_bitmaps.*`: generated GUI and resource files.
  Use the design tool to regenerate them.
- `CMakeLists.txt`: application target, source files, and dependency version.

Set your application name in `App.cpp` and your window title in `AppFrame.cpp`.
Set your own bundle identifier in `CMakeLists.txt` before distribution.

The old Visual Studio project files remain for reference. Use CMake for current
builds. The generated files retain their original content.

## Source and license

The original repository has no license file. This update does not assign a new
license to the original code. Select a project license before you distribute a
reusable template. wxWidgets has its own
[license](https://www.wxwidgets.org/about/licence/).
