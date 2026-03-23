#include "text.h"
#include "Shader.hpp"

Text::Text()
{
mesh.Init();
}
Text::Text(float _x, float _y, int _width, int _height, float _size)
{
size = _size;
width = _width;
height = _height;
x = _x;
y = _y;
mesh.Init();
}
void Text::SetFont(const char* filename)
{
mesh.SetTexture(filename);
}
void Text::SetText(const std::string& str)
{
text = str;	
}

void Text::SetSize(float _x, float _y, int _width, int _height, float _size)
{
size = _size;
width = _width;
height = _height;
x = _x;
y = _y;
}

void Text::Update()
{
mesh.Clear();

for (size_t i = 0; i < text.size(); ++i)
{
char c = text[i];
unsigned char ascii = (unsigned char)c;

int col = ascii % 16;
int row = ascii / 16;

int base = i * 4;

int rowl = i / width;
int coll = i % width;

float xpos = x + coll * size;
float ypos = y - rowl * size; 

float step = 1.0f/16.0f;

if(height <= rowl){break;}

mesh.AddPoint(Point(xpos, ypos,                0, step * col 	   , 1 - (step * row)));
mesh.AddPoint(Point(xpos + size, ypos,         0, step * col + step, 1 - (step * row)));
mesh.AddPoint(Point(xpos, ypos - size,         0, step * col	   , 1 - (step * row + step)));
mesh.AddPoint(Point(xpos + size, ypos - size,     0, step * col + step, 1 - (step * row + step)));


mesh.AddFace(base + 0, base + 1, base + 2);
mesh.AddFace(base + 1, base + 3, base + 2);

}
mesh.Update();
}

void Text::Render(BasicShader* shader)
{
    mesh.Render(shader);
}
