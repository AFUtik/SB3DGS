#pragma once

inline const char* CmnVxShader = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aUV;
out vec2 fragUV;
void main() {
	fragUV = aUV;
    gl_Position = vec4(aPos, 1);
}
)";

inline const char* CmnFgShader = R"(
#version 330 core
out vec4 FragColor;
in vec2 fragUV;
uniform sampler2D tex;
void main() {
    FragColor = texture(tex, fragUV);;
}
)";


inline const char *VlmVxShader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aUV;\n"

"out vec2 fragUV;\n"

"uniform mat4 proj;\n"
"uniform mat4 view;\n"
"uniform mat4 model;\n"

"void main()\n"
"{\n"
"    fragUV = aUV;\n"
"    gl_Position = proj * view * model * vec4(aPos, 1.0);\n"
"}\n";


inline const char *VlmFgShader =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 fragUV;\n"
"uniform vec4 color;\n"

"uniform sampler2D tex;\n"

"void main()\n"
"{\n"
"    FragColor = texture(tex, fragUV);\n"
"}\n";
