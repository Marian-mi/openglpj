#include "VertexArray.h"
#include <iostream>
#include "VertexBufferLayout.h"

VertexArray::VertexArray(VertexBuffer& vbo, VertexBufferLayout& vblo)
{
	glGenVertexArrays(1, &m_RendererId);
	Bind();
	vbo.Bind();

	const auto elements = vblo.GetElements();
	int offset = 0;
	std::cout << vblo.GetStride() << "   stride\n";

	for (int i = 0; i < elements.size() ; i++) {
		
		glEnableVertexAttribArray(i);
		GLCALL(glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, vblo.GetStride(), (void*)offset));

		offset += elements[i].count * LayoutElemnt::GetTypeSize(elements[i].type);
	}

}

VertexArray::~VertexArray()
{
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_RendererId);
}

void VertexArray::UnBind() const
{
	glBindVertexArray(0);
}
