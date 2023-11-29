#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/gl.h>
#include <vector>

class EBO {

public:
	GLuint ID;
	EBO(GLuint* vertices, GLsizeiptr size);
	EBO(std::vector<float> vertices);

	void Bind();
	void Unbind();
	void Delete();
};

#endif