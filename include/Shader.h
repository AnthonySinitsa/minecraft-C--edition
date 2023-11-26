#ifndef MINECRAFT_CLONE_SHADER_H
#define MINECRAFT_CLONE_SHADER_H
#include <iostream>

namespace MinecraftClone {
    class Shader {
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        void use();

    private:
        unsigned int ID;
        void checkCompileErrors(unsigned int shader, std::string type);
    };
}

#endif
