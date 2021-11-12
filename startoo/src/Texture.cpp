#include "Texture.h"
#include "vendors/stb_image/stbi_write_image.h"
#include "vendors/stb_image/stb_image.h"

Texture::Texture(const std::string& filepath)
	: m_RendererId(0), m_Filepath(filepath), m_Width(0)
	, m_Height(0), m_BPP(0), m_LocalBuffer(nullptr)
{
	stbi_set_flip_vertically_on_load(1);

	m_LocalBuffer = stbi_load(m_Filepath.c_str(), &m_Height, &m_Width, &m_BPP, 4);

	GLCALL(glGenTextures(1, &m_RendererId));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_RendererId));

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
	glBindTexture(GL_TEXTURE_2D ,0);

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);
}


void SaveImage(int h, int w, int channgelCount) {
	unsigned char* m_LocalBuffer;
	int m_Height, m_Width, m_BPP;
	m_LocalBuffer = stbi_load("res/img/counts-bg.jpg", &m_Height, &m_Width, &m_BPP, 3);
	unsigned char* data = new unsigned char[m_Width * m_Height * 3];

	int index = 0;
	int r = 0;
	for (int j = (m_Height * m_Width * 3) - 1; j >= 0; --j)
	{
		m_LocalBuffer[r] = m_LocalBuffer[r] * 0.2;
		data[index++] = m_LocalBuffer[(j)];
		r += 3;
	}
	
	stbi_write_jpg("jpg_test_.jpg", m_Width, m_Height, 3, data, 100);
	delete[] data;
}


Texture::~Texture()
{
	GLCALL(glDeleteTextures(1, &m_RendererId));
}

void Texture::Bind(unsigned int slot) const
{
	GLCALL(glActiveTexture(GL_TEXTURE0));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_RendererId));
}

void Texture::UnBind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);

}
