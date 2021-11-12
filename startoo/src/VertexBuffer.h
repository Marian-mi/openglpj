#pragma once

class VertexBuffer {
private:
	unsigned int _rendererId = 0;
public:
	VertexBuffer(void* data, size_t size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};