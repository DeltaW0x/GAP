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
    Shader* protoShader;
    Mesh* protoMesh;

    GLuint vbo;
    GLint posLoc;

    mat4 model, view, projection, mvp;

public:
    ProtogenFace()
    {
        protoShader = new Shader("./Assets/shaders/BasicShader.vs",
                                 "./Assets/shaders/BasicShader.fs");

        protoMesh = new Mesh("./Assets/models/out.mesh");

        glGenBuffers(1, &vbo);
    }

    ~ProtogenFace(){
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

        glm_scale_uni(model, 1);

        vec3 viewVec = {0.0f, 0.0f, -3.0f};
        glm_ortho(-4.0f, 4.0f, -1.0f, 1.0f, 0.001f, 1000.0f, projection);
        glm_translate(view, viewVec);

        glm_mat4_mul(projection, view, mvp);
        glm_mat4_mul(mvp, model, mvp);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, protoMesh->GetVertexBufferSize(), protoMesh->GetVertexBuffer().data(), GL_DYNAMIC_DRAW);

        GLint mvpLoc = glGetUniformLocation(protoShader->getProgramID(), "mvp");
        glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, (float *)mvp);

        GLint color = glGetUniformLocation(protoShader->getProgramID(), "color");
        glUniform3f(color, 1.0f, 1.0f, 1.0f);

        posLoc = glGetAttribLocation(protoShader->getProgramID(), "pos");
        glEnableVertexAttribArray(posLoc);

        glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glDrawElements(GL_TRIANGLES, protoMesh->GetIndexBufferCount(), GL_UNSIGNED_SHORT, protoMesh->GetIndexBuffer().data());
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }
};