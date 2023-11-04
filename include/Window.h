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

		void installMainCallbacks();

		void close();

    bool isFullScreen();
    void setFullScreen(bool fullScreen);
	
		static Window* createWindow(int width, int height, const char* title, bool fullScreenMode=false);
		static void freeWindow(Window* window);
	};
}

#endif 