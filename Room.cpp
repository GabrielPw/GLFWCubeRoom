#include "Room.h"
#include "Primitives.h"

Room::Room(float width, float depth, float height, Shader& shader)
    : roomWidth(width), roomDepth(depth), roomHeight(height), shader(shader), vbo(cubeVertices, sizeof(cubeVertices)), ebo(cubeIndices, sizeof(cubeIndices)) {

    roomWidth = width;
    roomDepth = depth;
    roomHeight = height;

}

void Room::setRoom() {
    // Inicialize as transformações dos cubos para formar a sala
    // Adicione transformações individuais para cada cubo
    
    // parede. (esquerda)
    glm::mat4 cubeModel = glm::mat4(1.0f);
    glm::vec3 wallPos = glm::vec3(0.f, 0.f, 0.f);
    cubeModel = glm::scale(cubeModel, glm::vec3(2.f, roomHeight, roomDepth));
    cubeModel = glm::translate(cubeModel, wallPos);

    cubeModels.push_back(cubeModel);

    // parede. (trás)
    cubeModel = glm::mat4(1.0f);
    wallPos = glm::vec3(0.0 + (roomDepth / 2) * cubeSize , 0.f, 0.f + cubeSize); // x virou z
    cubeModel = glm::rotate(cubeModel,glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
    cubeModel = glm::scale(cubeModel, glm::vec3(2.f, roomHeight, roomWidth));
    cubeModel = glm::translate(cubeModel, wallPos);

    cubeModels.push_back(cubeModel);

    // parede. (direita)
    cubeModel = glm::mat4(1.0f);
    wallPos = glm::vec3(0.0 + roomWidth * cubeSize, 0.f, 0.f); // x virou z
    cubeModel = glm::scale(cubeModel, glm::vec3(2.f, roomHeight, roomDepth));
    cubeModel = glm::translate(cubeModel, wallPos);

    cubeModels.push_back(cubeModel);

    // parede (frontal)
    cubeModel = glm::mat4(1.0f);
    wallPos = glm::vec3(0.0 - (roomDepth / 2) * cubeSize, 0.f, 0.f + cubeSize); // x virou z
    cubeModel = glm::rotate(cubeModel, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
    cubeModel = glm::scale(cubeModel, glm::vec3(2.f, roomHeight, roomWidth));
    cubeModel = glm::translate(cubeModel, wallPos);

    cubeModels.push_back(cubeModel);

    // chão
    cubeModel = glm::mat4(1.0f);
    wallPos = glm::vec3(0.f - (roomHeight * cubeSize) / (2 + cubeSize), -1 * cubeSize, 0.0f);
    cubeModel = glm::rotate(cubeModel, glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f));
    cubeModel = glm::scale(cubeModel, glm::vec3(2.f, roomWidth , roomDepth));
    cubeModel = glm::translate(cubeModel, wallPos);

    cubeModels.push_back(cubeModel);
}

void Room::render() {

    vao.Bind();
    vbo.Bind();
    ebo.Bind();
    // Position attribute (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute (location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // color attribute (location = 2)
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    for (const auto& model : cubeModels) {
        shader.setMat4("model", model);
        shader.setMat4("projection", cubeProjection);      
        glDrawElementsInstancedARB(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, 1);
    }
}

Room::~Room(){

}