#include "Shader.h"
#include <GL/glew.h>
#include "Renderer.h"
#include <sstream>
#include <fstream>
#include <iostream>

Shader::Shader(std::string& filepath)
	: m_RendererId(0), m_Filepath(filepath)
{
    auto res = ParseShaders(filepath);

    uint32_t program = CreateShader(res.VertexResource, res.FragmentResource);
    m_RendererId = program;
}

Shader::~Shader()
{
    GLCALL(glDeleteProgram(m_RendererId));
}

void Shader::Bind() const
{
    glUseProgram(m_RendererId);
}

void Shader::UnBind() const
{
    glUseProgram(0);
}

void Shader::SetUniform4f(std::string& name, float v0, float v1, float v2, float v3)
{
    int location = GetUniformLocation(name);
    GLCALL(glUniform4f(location, v0, v1, v2, v3));
}

void Shader::SetUniform1i(std::string& name, int i0)
{
	int location = GetUniformLocation(name);
	GLCALL(glUniform1i(location, i0));
}

void Shader::SetUniformMat4f(std::string& name, glm::mat4& matrix)
{
	int location = GetUniformLocation(name);
	GLCALL(glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]));
}

int Shader::GetUniformLocation(const std::string& name)
{
    GLCALL(int location = glGetUniformLocation(m_RendererId, name.c_str()));
    if (location == -1)
        std::cout << "[WARNING!!]--->  Unform = " + name + "  doesn't exist!\n";
    return location;
}

ProgramShadersResources Shader::ParseShaders(std::string& filepath) {
    std::ifstream stream(filepath);

    enum class ShaderTypes {
        NONE = -1, VERTEX = 0, FRAGMENT = 1,
    };
    std::string line;
    std::stringstream ss[2];
    ShaderTypes mode = ShaderTypes::FRAGMENT;

    while (std::getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                mode = ShaderTypes::VERTEX;
            else
                mode = ShaderTypes::FRAGMENT;
        }
        else {
            ss[(int)mode] << line << "\n";
        }
    }

    return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::ComplieShader(uint32_t type, std::string& source) {
    uint32_t id = glCreateShader(type);

    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (!result) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)_malloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Shader Compilation Failed!" << std::endl << "type:" << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}



uint32_t Shader::CreateShader(std::string& vertexShader, std::string& fragmentShader) {
    uint32_t program = glCreateProgram();
    uint32_t vs = ComplieShader(GL_VERTEX_SHADER, vertexShader);
    uint32_t fs = ComplieShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(fs);
    glDeleteShader(vs);

    return program;
}