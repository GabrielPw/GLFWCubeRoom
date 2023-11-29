 #version 330 core
    out vec4 FragColor;
    in vec3 ourColor;                // the input variable from the vertex shader (same name and same type)
    in vec2 textCoord;

    uniform int hasTexture;
    uniform sampler2D ourTexture;
    uniform vec4 lightColor;
    
    
    void main()
    {
        //FragColor = vec4(ourColor, 1.0);
        if(hasTexture == 0){
            FragColor = vec4(ourColor, 1.0);
        } else {
            FragColor = texture(ourTexture, textCoord) * lightColor;
        }

    };