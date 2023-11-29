#ifndef PRIMITIVES_H
#define PRIMITIVES_H

float groundSize = 5.0f;
float groundPlaneVertices[] = {

    // position                         // texture coords 
    -groundSize, -groundSize,  0.0f,    0.0, 0.0,   // bottom  left
     groundSize, -groundSize,  0.0f,    1.0, 0.0,   // bottom  right
     groundSize,  groundSize,  0.0f,    1.0, 1.0,   // top     right
    -groundSize,  groundSize,  0.0f,    0.0, 1.0    // top     left 
     
};

unsigned int groundPlaneIndices[] = {
    0, 1, 2,   // first triangle
    0, 2, 3    // second triangle
};

unsigned int cubeIndices[] = {
    // Front face
    0, 1, 2,
    0, 2, 3,

    // Right face
    1, 5, 6,
    1, 6, 2,

    // left face
    8, 9, 10,
    8, 10, 11,

    // top
    12, 13, 14, // top está como front?
    12, 14, 15,

    // bottom
    16, 17, 18,
    16, 18, 19,

    // back
    20, 21, 22,
    20, 22, 23
};

// CUBE 
float cubeSize = 0.2f;
float cubeVertices[] = {

    // front   // Correct order
    // position                         // colors           // text Coord       // Normals
    -cubeSize, -cubeSize,  cubeSize,    1.0, 0.0, 0.0f,     0.0f, 0.f,          0.0f, 0.f, 1.0f,// bottom  left  (0)
    cubeSize, -cubeSize,   cubeSize,    1.0, 0.0, 0.0f,     1.0f, 0.f,          0.0f, 0.f, 1.0f,// bottom  right (1)
     cubeSize,  cubeSize,  cubeSize,    1.0, 0.0, 0.0f,     1.0f, 1.f,          0.0f, 0.f, 1.0f,// top     right (2)
    -cubeSize,  cubeSize,  cubeSize,    1.0, 0.0, 0.0f,     0.0f, 1.f,          0.0f, 0.f, 1.0f,// top     left  (3)

    // Right face
    cubeSize, -cubeSize,  cubeSize,     0.0, 1.0, 0.0f,     0.0f, 0.f,      1.0f, 0.f, 0.0f,// bottom front       (4) 
    cubeSize, -cubeSize, -cubeSize,     0.0, 1.0, 0.0f,     0.0f, 0.f,      1.0f, 0.f, 0.0f,// bottom back    (5) 
    cubeSize,  cubeSize, -cubeSize,     0.0, 1.0, 0.0f,     0.0f, 1.f,      1.0f, 0.f, 0.0f,// top back       (6) 
    cubeSize,  cubeSize,  cubeSize,     0.0, 1.0, 0.0f,     1.0f, 1.f,      1.0f, 0.f, 0.0f,// top front          (7)

    // Left face
    -cubeSize, -cubeSize, -cubeSize,     0.0, 0.0, 1.0f,    1.0f, 0.f,      -1.0f, 0.f, 0.0f,// bottom back   (8)
    -cubeSize, -cubeSize,  cubeSize,     0.0, 0.0, 1.0f,    0.0f, 0.f,      -1.0f, 0.f, 0.0f,// bottom front      (9)
    -cubeSize,  cubeSize,  cubeSize,     0.0, 0.0, 1.0f,    0.0f, 1.f,      -1.0f, 0.f, 0.0f,// top front         (10)
    -cubeSize,  cubeSize, -cubeSize,     0.0, 0.0, 1.0f,    1.0f, 1.f,      -1.0f, 0.f, 0.0f,// top back      (11)

    // Top face // Correct order
    -cubeSize,  cubeSize,  cubeSize,     1.0, 1.0, 1.0f,    0.0f, 0.f,      0.0f, 1.f, 0.0f,// front left        (12)
     cubeSize,  cubeSize,  cubeSize,     1.0, 1.0, 1.0f,    1.0f, 0.f,      0.0f, 1.f, 0.0f,// front right       (13)
     cubeSize,  cubeSize, -cubeSize,     1.0, 1.0, 1.0f,    1.0f, 1.f,      0.0f, 1.f, 0.0f,// back right    (14)
    -cubeSize,  cubeSize, -cubeSize,     1.0, 1.0, 1.0f,    0.0f, 1.f,      0.0f, 1.f, 0.0f,// back left     (15)

        // Bottom face // Correct order
    
     cubeSize, -cubeSize,  cubeSize,     0.0, 0.0, 0.0f,    1.0f, 0.f,      0.0f, -1.f, 0.0f,// back right        (16)
    -cubeSize, -cubeSize,  cubeSize,     0.0, 0.0, 0.0f,    0.0f, 0.f,      0.0f, -1.f, 0.0f,// back left          (17)
    -cubeSize, -cubeSize, -cubeSize,     0.0, 0.0, 0.0f,    0.0f, 1.f,      0.0f, -1.f, 0.0f,// front left       (18)
    cubeSize, -cubeSize, -cubeSize,      0.0, 0.0, 0.0f,    1.0f, 1.f,      0.0f, -1.f, 0.0f, // front right      (19)

    // Back face // Correct order
    cubeSize,  -cubeSize,  -cubeSize,    1.0, 1.0, 0.0f,    1.0f, 0.f,          0.0f, 0.f, -1.0f,  // bottom  right (20)
    -cubeSize, -cubeSize,  -cubeSize,    1.0, 1.0, 0.0f,    0.0f, 0.f,          0.0f, 0.f, -1.0f, // bottom  left  (21)
    -cubeSize,  cubeSize,  -cubeSize,    1.0, 1.0, 0.0f,    0.0f, 1.f,          0.0f, 0.f, -1.0f, // top     left  (22)
     cubeSize,  cubeSize,  -cubeSize,    1.0, 1.0, 0.0f,    1.0f, 1.f,          0.0f, 0.f, -1.0f// top     right (23)
     
};

#endif