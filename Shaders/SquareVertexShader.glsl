#version 330 core
    layout (location = 0) in vec3 aPos;                 // the position variable has attribute position 0
    layout (location = 1) in vec3 aColor;              // defining a input color variable with location position = 1.
    layout (location = 2) in vec2 aTextCoord;
    out vec3 ourColor;                                 // output variable that will be used as input for our fragment shader.
    out vec2 textCoord;

    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main()
    {
        gl_Position = projection  * view * model * vec4(aPos, 1.0);
        ourColor = aColor;                               // set ourColor to the input color we got from the vertex data
        textCoord = aTextCoord;
    };