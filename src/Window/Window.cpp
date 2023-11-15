#include <iostream>
#include "Window.h"
#include "InputManager.h"

namespace MinecraftClone {
	void Window::installMainCallbacks() {
		if (nativeWindow != nullptr) {
			glfwSetKeyCallback(nativeWindow, Input::keyCallback);
			glfwSetCursorPosCallback(nativeWindow, Input::mouseCallback);
			glfwSetMouseButtonCallback(nativeWindow, Input::mouseButtonCallback);
		}
	}

	void Window::close() {
		if (nativeWindow != nullptr) {
			glfwSetWindowShouldClose(nativeWindow, GLFW_TRUE);
		}
	}

  bool Window::isFullScreen(){
    return glfwGetWindowMonitor(nativeWindow) != nullptr;
  }

void Window::setFullScreen(bool fullScreen) {
	if (fullScreen) {
		int monitorCount;
		GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);

		std::cout << "Number of monitors detected: " << monitorCount << std::endl;

		GLFWmonitor* targetMonitor = nullptr;
		// Logic to select the correct monitor, possibly iterating over 'monitors'
		// For now, just selecting the primary monitor
		targetMonitor = glfwGetPrimaryMonitor();

		// Add debug output to log monitor details
		if (targetMonitor) {
			const GLFWvidmode* mode = glfwGetVideoMode(targetMonitor);
			std::cout << "Using monitor: " << glfwGetMonitorName(targetMonitor) << std::endl;
			std::cout << "Resolution: " << mode->width << "x" << mode->height << std::endl;
			// Additional details can be logged here if needed

			// Store the window size and position so we can restore later
			glfwGetWindowPos(this->nativeWindow, &this->windowPosX, &this->windowPosY);
			glfwGetWindowSize(this->nativeWindow, &this->windowWidth, &this->windowHeight);

			// Set the window to full screen on the selected monitor
			glfwSetWindowMonitor(this->nativeWindow, targetMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		} else {
			std::cerr << "No suitable monitor found for full screen." << std::endl;
		}
	} else {
		// Revert to windowed mode
		glfwSetWindowMonitor(this->nativeWindow, nullptr, this->windowPosX, this->windowPosY, this->windowWidth, this->windowHeight, GLFW_DONT_CARE);
	}
}


	Window* Window::createWindow(int width, int height, const char* title, bool fullScreenMode) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWmonitor* primaryMonitor = fullScreenMode ? glfwGetPrimaryMonitor() : nullptr;
		GLFWwindow* newWindow = glfwCreateWindow(width, height, title, fullScreenMode ? glfwGetPrimaryMonitor() : nullptr, nullptr);
    if (newWindow == nullptr) {
			std::cout << "Failed to create GLFW window\n" << std::endl;
			glfwTerminate();
			return nullptr;
    }

		// Only supply the monitor if we want to start the window in full-screen mode
		Window* res = new Window(width, height, newWindow);

		glfwMakeContextCurrent(res->nativeWindow);

		return res;
	}

	void Window::freeWindow(Window* window) {
		if (window) {
			glfwDestroyWindow(window->nativeWindow);
			delete window;
		}
	}
}