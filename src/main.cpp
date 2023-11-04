#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Window.h"
#include "InputManager.h"

using namespace MinecraftClone::Input;

const int windowWidth = 1920;
const int windowHeight = 1080;
const char* windowTitle = "Minecraft Clone";

void error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

// Define testWindowCreation function
void testWindowCreation(MinecraftClone::Window& window) {
    if (isKeyDown(GLFW_KEY_F1)) {
        bool isFullScreen = window.isFullScreen();
        window.setFullScreen(!isFullScreen); // Toggle fullscreen
    }

    if (mouseX > 50) {
        std::cout << "Mouse position is greater than 50." << std::endl;
    }

    if (isKeyDown(GLFW_KEY_ESCAPE)) {
        window.close();
    }
}

int main() {
    glfwSetErrorCallback(error_callback);

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Use your custom Window class to create a window
    MinecraftClone::Window* myWindow = MinecraftClone::Window::createWindow(windowWidth, windowHeight, windowTitle);
    if (!myWindow) {
        std::cerr << "Failed to create window using Window class" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(myWindow->nativeWindow);

    // Load all OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        MinecraftClone::Window::freeWindow(myWindow);
        glfwTerminate();
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, windowWidth, windowHeight);

    // Install callbacks using your Window class
    myWindow->installMainCallbacks();

    // Main loop
    while (!glfwWindowShouldClose(myWindow->nativeWindow)) {
        // Clear buffer
        glClearColor(0.98f, 0.47f, 0.43f, 1.0f); // Soft red color
        glClear(GL_COLOR_BUFFER_BIT);

        // Call your test function with the instance of the Window class
        testWindowCreation(*myWindow);

        // Swap front and back buffers
        glfwSwapBuffers(myWindow->nativeWindow);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up
    MinecraftClone::Window::freeWindow(myWindow);
    glfwTerminate();
    return 0;
}
