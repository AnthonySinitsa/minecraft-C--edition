#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Get primary monitor
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    if(!monitor){
        std::cerr << "Failed to get primary monitor" << std::endl;
        return -1;
    }

    // Get video mode of monitor
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    if(!mode){
        std::cerr << "Failed to get video mode" << std::endl;
        return -1;
    }

    // Create a full-screen window
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Minecraft Clone", monitor, NULL);
    if(!window){
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load all OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render here

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate(); // Clean up and close the application
    return 0;
}
