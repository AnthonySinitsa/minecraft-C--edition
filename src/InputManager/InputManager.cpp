#include "InputManager.h"
#include <iostream>

namespace MinecraftClone {
    namespace Input {

        // Define static arrays for key and mouse button states
        bool keyPressedData[GLFW_KEY_LAST] = {};
        bool mouseButtonPressedData[GLFW_MOUSE_BUTTON_LAST] = {};
        float mouseX = 0.0f;
        float mouseY = 0.0f;
        float mouseScrollX = 0.0f;
        float mouseScrollY = 0.0f;

        void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (key >= 0 && key < GLFW_KEY_LAST) {
                keyPressedData[key] = action != GLFW_RELEASE;
            }
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
        }

        void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
            mouseX = static_cast<float>(xpos);
            mouseY = static_cast<float>(ypos);
        }

        void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
            if (button >= 0 && button < GLFW_MOUSE_BUTTON_LAST) {
                mouseButtonPressedData[button] = action != GLFW_RELEASE;
            }
        }

        void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
            mouseScrollX += static_cast<float>(xoffset);
            mouseScrollY += static_cast<float>(yoffset);
        }

        bool isKeyDown(int key) {
            return key >= 0 && key < GLFW_KEY_LAST && keyPressedData[key];
        }

        bool isMouseButtonDown(int mouseButton) {
            return mouseButton >= 0 && mouseButton < GLFW_MOUSE_BUTTON_LAST && mouseButtonPressedData[mouseButton];
        }
    }
}