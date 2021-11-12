#pragma once

#include "Renderer.h"


class Texture {
private:
	unsigned int m_RendererId;
	unsigned char* m_LocalBuffer;
	std::string m_Filepath;
	int m_Width, m_Height, m_BPP;
public:
	Texture(const std::string& filepath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void UnBind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};

void SaveImage(int h, int w, int channgelCount);