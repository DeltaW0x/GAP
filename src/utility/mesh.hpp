#pragma once

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

class Mesh
{

public:
    Mesh(const char *path)
    {
        
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
    std::unordered_map<std::string,std::vector<float>> m_blendshapesBuffer;
};