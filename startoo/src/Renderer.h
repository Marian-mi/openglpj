#pragma once
#include "GL/glew.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCALL(x) GlClearError();\
    x;\
    ASSERT(GlLogCall(#x, __FILE__, __LINE__))

void GlClearError();

bool GlLogCall(const char* func, const char* fileName, int line);

class Renderer {
private:
    
public:
    void Draw(VertexArray& vao, IndexBuffer& ibo, Shader& shader) const;
    void Draw(VertexArray& vao, Shader& shader, unsigned int count) const;

    void Clear() const;
};