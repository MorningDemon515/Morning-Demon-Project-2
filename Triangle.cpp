#include "Triangle.h"

#include "Shader.h"
#include <dxgi.h>

extern ID3D11Device* Device;
extern ID3D11DeviceContext* Context;

struct Triangle_Vertex {
    float x, y, z;    
    float r, g, b;     
};

const D3D11_INPUT_ELEMENT_DESC Triangle_InputLayout[2] = {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
};

Triangle::Triangle(float* pos, float* color)
{
    Triangle_Vertex vertices[] = {
        {  pos[0],  pos[1], pos[2], color[0],  color[1], color[2] }, 
        {  pos[3],  pos[4], pos[5], color[3],  color[4], color[5] }, 
        {  pos[6],  pos[7], pos[8], color[6],  color[7], color[8] }, 
    };

    D3D11_BUFFER_DESC vbd = { 0 };
    vbd.ByteWidth = sizeof(vertices);
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = { 0 };
    initData.pSysMem = vertices;

    Device->CreateBuffer(&vbd, &initData, &VertexBuffer);

}

Triangle::~Triangle()
{
    VertexBuffer->Release();
}

void Triangle::Draw()
{
    Shader shader = Shader("hlsl/Triangle.VS","hlsl/Triangle.PS",
                            "VS_Main","PS_Main");

    shader.SetVertexShader(Triangle_InputLayout);   
    shader.SetPixelShader();                     

    UINT stride = sizeof(Triangle_Vertex);
    UINT offset = 0;
    Context->IASetVertexBuffers(0, 1, &VertexBuffer, &stride, &offset);
    Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    Context->Draw(3, 0);

}