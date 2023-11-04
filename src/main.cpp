#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "InputManager.h"

using namespace MinecraftClone::Input;

const int windowWidth = 1920;
const int windowHeight = 1080;
const char* windowTitle = "Minecraft Clone";

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Minecraft Clone", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load all OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, mouseScrollCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear buffer
        glClearColor(0.98f, 0.47f, 0.43f, 1.0f); // Soft red color
        glClear(Gl_COLOR_BUFFER_BIT);


        // Handle key press
        if (isKeyDown(GLFW_KEY_E)) {
            std::cout << "Key E is being pressed." << std::endl;
            // Additional handling for W key press
        }

        // Check mouse position
        if (mouseX >= windowWidth / 2.0f){
            std::cout << "Mouse is at right part of window." << std::endl;
        }

        // Check for escape key to close window
        if (isKeyDown(GLFW_KEY_ESCAPE)){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate(); // Clean up and close the application
    return 0;
}
