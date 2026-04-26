set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR AMD64)

# Homebrew mingw-w64 14.0.0 cross compiler
set(CMAKE_C_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-windres)

# mingw-w64 sysroot
set(CMAKE_FIND_ROOT_PATH /opt/homebrew/Cellar/mingw-w64/14.0.0/toolchain-x86_64)

# Allow finding programs on host (moc, uic, rcc need to run on macOS)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

# Windows Qt 6.6.2 (target libraries)
set(CMAKE_PREFIX_PATH /Users/chobits/Qt-windows/6.6.2/mingw_64)

# macOS Qt 6.6.2 (host tools: moc, uic, rcc — must match target Qt version)
set(QT_HOST_PATH /Users/chobits/Qt-host/6.6.2/macos)

# Static link libstdc++ and libgcc to avoid DLL version conflicts
set(CMAKE_CXX_FLAGS_INIT "-static-libstdc++ -static-libgcc")
set(CMAKE_C_FLAGS_INIT "-static-libgcc")

# Exclude unnecessary Qt modules to speed up CMake discovery
set(BUILD_SHARED_LIBS ON)
