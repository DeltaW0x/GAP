#pragma once
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utility/shader.hpp"
#include "../utility/mesh.hpp"
#include <iostream>

class ProtogenFace
{
private:
    Shader *protoShader;
    Mesh *protoMesh;

    GLuint vbo;
    GLint posLoc;

public:
    ProtogenFace()
    {
        protoShader = new Shader("/home/delta/proto/src/resources/shaders/ProtoFace.vs", 
                                 "/home/delta/proto/src/resources/shaders/ProtoFace.fs");

        protoMesh = new Mesh("/home/delta/proto/src/resources/meshes/protoFaceMesh.ms");

        glGenBuffers(1, &vbo);
    }

    ~ProtogenFace()
    {
        delete protoShader;
        delete protoMesh;
    }

    void render()
    {
        protoShader->use();
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, protoMesh->getVertexBufferSize(), protoMesh->getVertexBuffer().data(), GL_STATIC_DRAW);

        posLoc = glGetAttribLocation(protoShader->getProgramID(), "pos");
        glEnableVertexAttribArray(posLoc);

        glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glDrawElements(GL_TRIANGLES, protoMesh->getIndexCount(), GL_UNSIGNED_SHORT, protoMesh->getIndexBuffer().data());
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }
};