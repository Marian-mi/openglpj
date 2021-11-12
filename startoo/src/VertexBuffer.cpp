#include "Renderer.h"
#include "VertexBuffer.h"


VertexBuffer::VertexBuffer(void* data, size_t size)
{
	GLCALL(glGenBuffers(1, &_rendererId));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _rendererId));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _rendererId));
}

void VertexBuffer::UnBind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}