#pragma once

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Mesh
{
private:
    std::vector<GLushort> indexBuffer;
    std::vector<float> vertexBuffer;

    GLsizeiptr indexBufferSize;
    GLsizeiptr vertexBufferSize;

    int indexCount;
    int vertexCount;

public:
    Mesh(const char *meshPath)
    {
        bool readIndex = false;

        std::ifstream meshFile;

        try
        {
            meshFile.open(meshPath);
            for (std::string line; getline(meshFile, line);)
            {

                if (line == "INDEX")
                {
                    readIndex = true;
                    continue;
                }
                if (!readIndex && !line.empty())
                {
                    vertexBuffer.push_back(std::stof(line));
                }
                else if (readIndex && !line.empty())
                {
                    indexBuffer.push_back(static_cast<GLushort>(std::stoul(line)));
                }
            }
        }
        catch (std::ifstream::failure &e)
        {
            std::cout << "ERROR::MESH::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        meshFile.close();

        indexCount = indexBuffer.size();
        vertexCount = vertexBuffer.size();

        indexBufferSize = sizeof(GLushort) * indexCount;
        vertexBufferSize = sizeof(float) * vertexCount;
    }

    GLsizeiptr getIndexBufferSize()
    {
        return indexBufferSize;
    }
    GLsizeiptr getVertexBufferSize()
    {
        return vertexBufferSize;
    }

    std::vector<GLushort> getIndexBuffer()
    {
        return indexBuffer;
    }
    std::vector<float> getVertexBuffer()
    {
        return vertexBuffer;
    }

    int getIndexCount()
    {
        return indexCount;
    }

    int getVertexCount()
    {
        return vertexCount;
    }
};