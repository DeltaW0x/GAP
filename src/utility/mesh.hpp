#pragma once

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Mesh
{

public:
    Mesh(const char *path)
    {
        std::ifstream f(path);
        json data = json::parse(f);

        m_vertexBuffer = data["BASE_MESH"]["VERTICES"].get<std::vector<float>>();
        m_indexBuffer = data["BASE_MESH"]["INDICES"].get<std::vector<GLushort>>();
    }

    std::vector<float> GetVertexBuffer(){
        return m_vertexBuffer;
    }

    std::vector<GLushort> GetIndexBuffer(){
        return m_indexBuffer;
    }

    GLsizeiptr GetVertexBufferSize(){
        return sizeof(float) * m_vertexBuffer.size();
    }

    GLsizeiptr GetIndexBufferCount(){
        return m_indexBuffer.size();
    }
private:
    std::vector<GLushort> m_indexBuffer;
    std::vector<float> m_vertexBuffer;
};