#pragma once

#include "mesh.h"

class BasicShader;

class Image
{
protected:
    Mesh mesh;
    float width;
    float height;
    float x;
    float y;

    public:

    Image();
    Image(float _x, float _y, float _width, float _height);
    void SetTexture(const char* filename);
    void SetSize(float _x, float _y, float _width, float _height);

    float getWidth();
    float getHeight();
    float getX();
    float getY();

    void Update();
    void Render(BasicShader* shader);
	
};
