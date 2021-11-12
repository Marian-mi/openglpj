#include <iostream>
#include "Renderer.h"

void GlClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GlLogCall(const char* func, const char* fileName, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "\n[OpenGL Erorr!] =>  " << error << "\n" << func << "\n" << fileName << "  :  " << line << std::endl;
        return false;
    }

    return true;
}

void Renderer::Draw(VertexArray& vao, IndexBuffer& ibo, Shader& shader) const
{
    shader.Bind();
    vao.Bind();
    ibo.Bind();

    GLCALL(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}
