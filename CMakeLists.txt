cmake_minimum_required(VERSION 3.14)
project(NES)

set(CMAKE_CXX_STANDARD 14)

#include_directories(/home/rene/Git/C/olcPixelGameEngine)
#add_compile_options(-lglut -lGLU -lGL -lX11 -pthread -lpng)
#add_link_options(-lglut -lGLU -lGL -lX11 -pthread -lpng)

set(ExecutableName NES)
set(SourceFiles drawCPU.cpp)

# Find thread package
set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

# Find GL and GLX package
find_package(OpenGL REQUIRED)

find_package(X11 REQUIRED)
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

# Set platform spesific output names
set(Executable ${ExecutableName}.o)
set(-lstdc++fs)
add_executable(${Executable}
        ${SourceFiles}
        # Add more directories, files or CMake variables here to have them compile too!
        )

target_link_libraries(${Executable}
        Threads::Threads
        OpenGL::OpenGL
        OpenGL::GL
        OpenGL::GLX
        )

target_link_libraries(${Executable}
        ${X11_LIBRARIES}
        PNG::PNG
        )