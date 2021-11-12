#pragma once

#include "Renderer.h"
#include <GL/glew.h>
#include <vector>

struct LayoutElemnt {
	unsigned int count;
	unsigned int type;
	unsigned char normalized;

	static unsigned int GetTypeSize(unsigned int type) {
		switch (type)
		{
		case GL_UNSIGNED_INT:  return 4;
		case GL_FLOAT:         return 4;
		case GL_UNSIGNED_BYTE: return 1;
		default:               return 0;
		}
	}
};

class VertexBufferLayout {
private:
	std::vector<LayoutElemnt> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout() {}

	template<typename T>
	void Push(unsigned int count) {
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count) {
		m_Elements.push_back(LayoutElemnt{
				count,
				GL_FLOAT,
				GL_FALSE,
			});

		m_Stride += LayoutElemnt::GetTypeSize(GL_FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count) {
		m_Elements.push_back(LayoutElemnt{
				count,
				GL_UNSIGNED_INT,
				GL_FALSE,
			});
		m_Stride += LayoutElemnt::GetTypeSize(GL_UNSIGNED_INT) * count;

	}

	template<>
	void Push<unsigned char>(unsigned int count) {
		m_Elements.push_back(LayoutElemnt{
				count,
				GL_UNSIGNED_BYTE,
				GL_TRUE,
			});
		m_Stride += LayoutElemnt::GetTypeSize(GL_UNSIGNED_BYTE) * count;

	}

	inline std::vector<LayoutElemnt> GetElements() const& { return m_Elements; }
	inline unsigned int GetStride() const& { return m_Stride; }
};