#include <iostream>
#include "Window.h"
#include "InputManager.h"

namespace MinecraftClone
{
	void Window::installMainCallbacks()
	{
		if (nativeWindow != nullptr)
		{
			glfwSetKeyCallback(nativeWindow, Input::keyCallback);
			glfwSetCursorPosCallback(nativeWindow, Input::mouseCallback);
			glfwSetMouseButtonCallback(nativeWindow, Input::mouseButtonCallback);
		}
	}

	void Window::close()
	{
		if (nativeWindow != nullptr)
		{
			glfwSetWindowShouldClose(nativeWindow, GLFW_TRUE);
		}
	}

  bool Window::isFullScreen(){
    return glfwGetWindowMonitor(nativeWindow) != nullptr;
  }

  void Window::setFullScreen(bool fullScreen){
    if(fullScreen){
      const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
      glfwSetWindowMonitor(this->nativeWindow, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
    } else {
      glfwSetWindowMonitor(this->nativeWindow, nullptr, 100, 100, this->windowWidth, this->windowHeight, GLFW_DONT_CARE);
    }
  }

	Window* Window::createWindow(int width, int height, const char* title, bool fullScreenMode)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Only supply the monitor if we want to start the window in full-screen mode
		Window* res = new Window();
		GLFWmonitor* primaryMonitor = fullScreenMode ? glfwGetPrimaryMonitor() : nullptr;
		res->nativeWindow = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);
		if (res->nativeWindow == nullptr)
		{
			std::cout << "Failed to create GLFW window\n" << std::endl;
			glfwTerminate();
			return nullptr;
		}
		glfwMakeContextCurrent(res->nativeWindow);

		return res;
	}

	void Window::freeWindow(Window* window)
	{
		if (window)
		{
			glfwDestroyWindow(window->nativeWindow);
			delete window;
		}
	}
}