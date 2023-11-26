# Minecraft-C++-Edition

src: Contains all the source files

include: Contains all the header files

libs: Contains libraries and dependencies

assets: Contains assets like textures, models, etc

build: Contains compiled binaries and object files

Shader Management: Sahder loaders, comilation, and linking code

Rendering: Reder code, including code that deals with VAOs, VBOs, and drawing calls

Utility: Use these files for utility functions that can be used across different parts of project

World and Block: When building minecraft world, use these files to manage blocks and world generation

## Goal 1

1. Create an entry point for my application, main function in C++

2. Inside entry point, create window and start game loop

3. if multiple monitors, add support for switching different monitors on startup

4. add feature to launch game in full screen mode

5. add event handlers for keyboard and mouse input

### Function to test these capabilities

```,
void testWindowCreation(Window& window){
  if(Input::isKeyPressed(GLFW_KEY_F1)){
    bool isFullScreen = window.isFullScreen();
    window.setFullScreen(isFullScreen());
  }

  if(Input::mousePosition.x > 50){
    printf("Mouse position is greater than 50.");
  }

  if(Input::isKeyPressed(GLFW_KEY_ESCAPE)){
    window.close();
  }
}
```

## Goal 2

1. Draw a square on the scren using glDrawArrays

2. Draw a square on the screen using glDrawElements

3. Draw a star using glDrawElements

4. Draw the outline of a square using the GL_LINES primitive

5. Repeat challenge 3, but use the named buffer technique
