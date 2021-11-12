#pragma once

#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray {
private:
	unsigned int m_RendererId = 0;
public:
	VertexArray(VertexBuffer& vbo, VertexBufferLayout& vblo);
	~VertexArray();

	void Bind() const;
	void UnBind() const;
};