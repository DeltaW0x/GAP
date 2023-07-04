#pragma once
#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <cglm/cglm.h> 

#include "../utility/shader.hpp"
#include "../utility/mesh.hpp"


class ProtogenFace
{
private:
    Shader *protoShader;
    Mesh *protoMesh;

    GLuint vbo;
    GLint posLoc;

    mat4 model,view,projection,mvp;
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
        glm_mat4_identity(view);
        glm_mat4_identity(model);
        glm_mat4_identity(projection);
        glm_mat4_identity(mvp);

        vec3 viewVec = {0.0f,0.0f,-3.0f};
        glm_ortho(-4.0f,4.0f,-1.0f,1.0f,0.001f,1000.0f,projection);
        glm_translate(view,viewVec);

        glm_mat4_mul(projection,view,mvp);
        glm_mat4_mul(mvp,model,mvp);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, protoMesh->getVertexBufferSize(), protoMesh->getVertexBuffer().data(), GL_STATIC_DRAW);

        GLint mvpLoc = glGetUniformLocation(protoShader->getProgramID(), "mvp");
        glUniformMatrix4fv(mvpLoc,1,GL_FALSE,(float*)mvp);

        posLoc = glGetAttribLocation(protoShader->getProgramID(), "pos");
        glEnableVertexAttribArray(posLoc);

        glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glDrawElements(GL_TRIANGLES, protoMesh->getIndexCount(), GL_UNSIGNED_SHORT, protoMesh->getIndexBuffer().data());
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }
};