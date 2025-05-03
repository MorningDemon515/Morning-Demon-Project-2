#include "Triangle.h"

void Init_Scene()
{

}

void Draw_Scene()
{
    float pos[] = {0.0f,  0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
                    -0.5f, -0.5f, 0.0f};

    float color[] = {1.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 1.0f};                

    Triangle tri = Triangle(pos,color);
    tri.Draw();
}

void Clean_Scene()
{

}