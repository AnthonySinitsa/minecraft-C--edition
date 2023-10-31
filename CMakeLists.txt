cmake_minimum_required(VERSION 3.10)
project(MinecraftClone)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(MinecraftClone
    src/main.cpp
    src/Camera/Camera.cpp
    src/Renderer/Renderer.cpp
    # ... other source files ...
    src/glad.c
)

# Include directories
include_directories(include)
include_directories(include/GLFW)
include_directories(include/GLAD)

# Link against GLFW and other libraries you might need
target_link_libraries(MinecraftClone glfw dl)
