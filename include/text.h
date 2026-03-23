#pragma once

#include <string>
#include "mesh.h"

class BasicShader;

class Text
{
protected:
    Mesh mesh;
    std::string text;

    public:
    float x, y, size;
    int width, height;

    Text();
    Text(float _x, float _y, int _width, int _height, float _size);
    void SetFont(const char* filename);
    void SetText(const std::string& str);
    void SetSize(float _x, float _y, int _width, int _height, float _size);
    void Update();
    void Render(BasicShader* shader);
	
};
