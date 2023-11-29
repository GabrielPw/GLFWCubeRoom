#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    //~Shader();

    // Ativar o shader
    void use();

    // Funções de configuração do uniform
    void setBool(const std::string& name, bool value) const;


    void setMat4(const std::string& name, const glm::mat4& mat) const;

    void setVec4(const std::string& name, const glm::vec4& value) const;

private:
    std::string readFile(const char* filePath);
    // Utilitário para verificar erros de compilação/linkagem de shaders
    void checkCompileErrors(unsigned int shader, const std::string& type);
};

#endif