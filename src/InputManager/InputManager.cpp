// src/InputManager/InputManager.cpp
#include "InputManager.h"
#include <iostream>

void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Handle keyboard input
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, true);
                break;
            // Handle other keys here
        }
    }
}

void InputManager::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    // Handle mouse movement
    // std::cout << "Mouse Position: (" << xpos << ", " << ypos << ")\n";
}

void InputManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    // Handle mouse button input
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        // std::cout << "Left mouse button pressed\n";
    }
}
