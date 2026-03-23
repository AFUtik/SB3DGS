#pragma once

#include <functional>
#include "image.h"
#include "text.h"

class Button
{
protected:
    std::function<void()> function;
    Image body;
    Image ActiveBody;
    Text text;

    float x, y, width, height, size;
public:
    Button(float _x, float _y, float _width, float _height);

    
    void Update();
    void Call();

    void SetText(const std::string& str);

    void SetCall(std::function<void()> f);
    void SetText(Text _text);
    void SetBody(Image _body);
    void SetActiveBody(Image _activeBody);
    
    void Check(BasicShader* shader,float mosPosX, float mosPosY);
    void Render(BasicShader* shader, float mosPosX, float mosPosY);

	
};
