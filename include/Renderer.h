#ifndef MINECRAFT_CLONE_RENDERER_H
#define MINECRAFT_CLONE_RENDERER_H

#include "Shader.h"

namespace MinecraftClone {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        void Draw();

    private:
        void initRenderData();

        unsigned int VAO;
        Shader shader;
    };
}

#endif // MINECRAFT_CLONE_RENDERER_H
