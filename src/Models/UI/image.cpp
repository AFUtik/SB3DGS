#include "image.h"

Image::Image()
{
mesh.Init();
}

Image::Image(float _x, float _y, float _width, float _height)
{
width = _width;
height = _height;
x = _x;
y = _y;

mesh.Init();

mesh.AddPoint(Point(x,y,0,1,1));
mesh.AddPoint(Point(x + width,y,0,0,1));
mesh.AddPoint(Point(x,y - height,0,1,0));
mesh.AddPoint(Point(x + width,y - height,0,0,0));
mesh.AddFace(2,0,1);
mesh.AddFace(1,2,3);
mesh.Update();
	
}

void Image::SetSize(float _x, float _y, float _width, float _height)
{
mesh.Clear();

width = _width;
height = _height;
x = _x;
y = _y;

mesh.AddPoint(Point(x,y,0,1,1));
mesh.AddPoint(Point(x + width,y,0,0,1));
mesh.AddPoint(Point(x,y - height,0,1,0));
mesh.AddPoint(Point(x + width,y - height,0,0,0));
mesh.AddFace(2,0,1);
mesh.AddFace(1,2,3);
mesh.Update();
}


float Image::getWidth() { return width; }
float Image::getHeight() { return height; }
float Image::getX() { return x; }
float Image::getY() { return y; }


void Image::SetTexture(const char* filename)
{
mesh.SetTexture(filename);
}
void Image::Update()
{
mesh.Update();
}
void Image::Render(BasicShader* shader)
{
mesh.Render(shader);
}
