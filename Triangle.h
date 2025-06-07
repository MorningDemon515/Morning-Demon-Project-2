#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <d3d11.h>

class Triangle
{
private:
    ID3D11Buffer* VertexBuffer;

public:    
    Triangle(float* pos);
    ~Triangle();

    void Draw();

};


#endif