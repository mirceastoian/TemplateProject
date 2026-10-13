# CMake Module Organization Demo

This small C++17 project demonstrates modules as separate CMake library
targets. All C++ source and header files live under `src/`, including the
application entry point.

## Project Layout

```text
src/
  module1/
    CMakeLists.txt
    module1.cpp
    module1_detail.hpp
    include/module1/summary.hpp
  module2/
    CMakeLists.txt
    application.cpp
    application_detail.hpp
    include/module2/application.hpp
  ...
  main.cpp
```

Each module owns its implementation files and private headers. Public headers
live under that module's `include/` directory. A module adds that directory as
a `PUBLIC` include path and its own source directory as a `PRIVATE` include
path, so consumers can include the public interface but cannot inherit the
module's private header search path.

`module2` depends on `module1` privately (does not expose `module1` as part of
`module2`'s public CMake interface). The root `CMakeLists.txt` recursively
discovers module directories containing their own `CMakeLists.txt` and adds
them as subdirectories. The executable links to `module2`.

## Build

From the project root:

```sh
cmake -S . -B build
cmake --build build
```

Run `build/module_demo` (or `build/Debug/module_demo.exe` with a multi-config
generator) to see the modules work together.

## Ideas

* Create a Python script that checks for module files that use private includes
belonging to other modules (see if https://github.com/chromium/chromium/tree/main/buildtools/checkdeps
could be used).

* Also consider integrating [Include-What-You-Use](https://include-what-you-use.org/)
for header completeness (needs clang).

* Other mechanisms:
  * https://github.com/jeremy-rifkin/build-blame