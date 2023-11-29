#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/gl.h>
#include <vector>
#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 textureUV;
};

class VBO {

public:
    

	GLuint ID;
	VBO(const std::vector<float>& vertices);
	VBO(GLfloat* vertices, GLsizeiptr size);
    VBO(std::vector<Vertex> vertex, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif