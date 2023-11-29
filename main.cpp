#include <Windows.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<iostream>
#include <fstream>
#include <sstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Shader.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include <cmath>
#include "Room.h"

unsigned int blockTextures[3];
unsigned int program;


void frameBufferSize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

// camera 
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float scrollDirection;
void processInput(GLFWwindow* window)
{
    float cameraSpeed = 18.5f * deltaTime;; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        cameraPos -= cameraUp * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        cameraPos += cameraUp * cameraSpeed;
    
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    // Atualizar o estado da roda do mouse
    if (yoffset > 0.0)
    {
        // Rotação para cima
        scrollDirection = 1;
        float pitch = 60.0f * deltaTime;  // Ajuste a velocidade de rotação conforme necessário
        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(pitch), glm::vec3(0.f, 1.f, 0.f));
        cameraFront = glm::mat3(rotation) * cameraFront;
    }
    else if (yoffset < 0.0)
    {
        // Rotação para baixo
        scrollDirection = -1;
        float pitch = 60.0f * deltaTime;  // Ajuste a velocidade de rotação conforme necessário
        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(-pitch), glm::vec3(0.f, 1.f, 0.f));
        cameraFront = glm::mat3(rotation) * cameraFront;
    }
}

unsigned int initTexture(const char* path) {
    unsigned int texture;

    // Gerar texturas
    glGenTextures(1, &texture);

    // Configurar texturas
    glBindTexture(GL_TEXTURE_2D, texture);

    std::cout << "\ntexture: " << path;
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture: " << path << std::endl;
    }

    stbi_image_free(data);

    return texture;
}

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int WIDTH = 800, HEIGHT = 600;
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Aprendendo OpenGL/GLFW", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, frameBufferSize_callback);
    glfwMakeContextCurrent(window);

    gladLoadGL(glfwGetProcAddress);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);


    Shader shader("Shaders/SquareVertexShader.glsl", "Shaders/SquareFragmentShader.glsl");
    //Shader lightningShader("Shaders/LightVertexShader.glsl", "Shaders/LightFragmentShader.glsl");

    GLuint brick_texture = initTexture("resources/block_textures/brick/brick_text.jpg");

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
    
    float red = 1.0f, green = 1.0f, blue = 1.0f;
    
    float rotationSpeed = 0.1;
    float translationSpeed = 0.01;
    int hasTextureLocation = glGetUniformLocation(shader.ID, "hasTexture");
    float rotationLoop = 0.f;

    glm::mat4 model = glm::mat4(1.f);
    glm::mat4 view = view = glm::lookAt(cameraPos,
        cameraPos + cameraFront,
        cameraUp
    );


    // room -> width, depth, height.
    Room room1(100.f, 65.f, 30.f, shader);
    while (!glfwWindowShouldClose(window)) {

        glClearColor((80.f / 255), (100.f / 255), (121.f / 255), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glm::vec4 lightColor = glm::vec4(red, green, blue, 1.0);

        shader.use();
        room1.vao.Bind();
        room1.vbo.Bind();
        room1.ebo.Bind();

        // camera.
        glm::mat4 view = glm::mat4(1.0);
        glm::mat4 model = glm::mat4(1.f);
        view = view = glm::lookAt(cameraPos,
            cameraPos + cameraFront,
            cameraUp
        );

        //view = glm::translate(view, glm::vec3(0.f, -25.0f, -1.f * 80.0));
        //view = glm::translate(view, glm::vec3(-translationSpeed / 1.5, 1.f, translationSpeed));
        //view = glm::rotate(view, glm::radians(rotationSpeed), glm::vec3(1.f, 0.f, 0.f));

        // Room.
        glUniform1i(hasTextureLocation, 1);
        glBindTexture(GL_TEXTURE_2D, brick_texture);

        room1.cubeProjection = projection;
        room1.shader.setVec4("lightColor", lightColor);
        room1.shader.setMat4("view", view);

        room1.setRoom();
        room1.render();

        // End
        rotationSpeed += 0.5;
        translationSpeed += 0.08;

        processInput(window);
        glfwSetScrollCallback(window, scrollCallback);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(program);
    return 0;
}