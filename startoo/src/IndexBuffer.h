#pragma once


class IndexBuffer {
private:
	unsigned int _rendererId = 0;
	unsigned int _count;
public:
	IndexBuffer(void* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	unsigned int GetCount() const { return _count; }
};

