#ifndef MINECRAFT_CLONE_WINDOW_H
#define MINECRAFT_CLONE_WINDOW_H
#include <GLFW/glfw3.h>

namespace MinecraftClone
{
	struct Window
	{
		GLFWwindow* nativeWindow;
		int windowWidth;
		int windowHeight;
		int windowPosX;
		int windowPosY;

		// Constructor to initialize the members
		Window(int width, int height, GLFWwindow* window)
				: windowWidth(width), windowHeight(height), nativeWindow(window),
					windowPosX(100), windowPosY(100) {} // Initialize with default values

		void installMainCallbacks();

		void close();

    bool isFullScreen();
    void setFullScreen(bool fullScreen);
	
		static Window* createWindow(int width, int height, const char* title, bool fullScreenMode=false);
		static void freeWindow(Window* window);
	};
}

#endif 