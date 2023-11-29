#ifndef ROOM_CLASS_H
#define ROOM_CLASS_H

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"
#include "Shader.h"

class Room {

public:
    VBO vbo;
    VAO vao;
    EBO ebo;
    Shader shader;
    glm::mat4 cubeProjection;
    float roomWidth, roomDepth, roomHeight;

    Room(float width, float depth, float height, Shader &shader);

    void render();

    // cria paredes, teto e chão.
    void setRoom();
    ~Room();

private:
    
    std::vector<glm::mat4> cubeModels;
};

#endif
