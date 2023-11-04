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
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);

    glfwSetKeyCallback(window, MinecraftClone::Input::keyCallback);
    glfwSetCursorPosCallback(window, MinecraftClone::Input::mouseCallback);
    glfwSetMouseButtonCallback(window, MinecraftClone::Input::mouseButtonCallback);
    glfwSetScrollCallback(window, MinecraftClone::Input::mouseScrollCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Handle key press
        if (MinecraftClone::Input::isKeyDown(GLFW_KEY_W)) {
            std::cout << "Key W is being pressed." << std::endl;
            // Additional handling for W key press
        }

        // Handle mouse button press
        if (MinecraftClone::Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
            std::cout << "Left mouse button is being pressed." << std::endl;
            // Additional handling for left mouse button press
        }

        // Render here

        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate(); // Clean up and close the application
    return 0;
}
