#include "Cube.h"
#include<la.h>
#include <iostream>

static const int CUBE_IDX_COUNT = 36;
static const int CUBE_VERT_COUNT = 24;

Cube::Cube() : Geometry()
{}


//These are functions that are only defined in this cpp file. They're used for organizational purposes
//when filling the arrays used to hold the vertex and index data.
void createCubeVertexPositions(glm::vec4 (&cube_vert_pos)[CUBE_VERT_COUNT]){
    // create 4 vertices for each of the 6 faces of the cube
    int index = 0;

    // face 1: bottom, x = 0
    cube_vert_pos[index++] =  glm::vec4(0,0,0,1);
    cube_vert_pos[index++] =  glm::vec4(0,0,1,1);
    cube_vert_pos[index++] =  glm::vec4(0,1,0,1);
    cube_vert_pos[index++] =  glm::vec4(0,1,1,1);

    // face 2: top: x = 1
    cube_vert_pos[index++] =  glm::vec4(1,0,0,1);
    cube_vert_pos[index++] =  glm::vec4(1,0,1,1);
    cube_vert_pos[index++] =  glm::vec4(1,1,0,1);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,1);

    // face 3: left: y = 0
    cube_vert_pos[index++] =  glm::vec4(0,0,0,1);
    cube_vert_pos[index++] =  glm::vec4(0,0,1,1);
    cube_vert_pos[index++] =  glm::vec4(1,0,0,1);
    cube_vert_pos[index++] =  glm::vec4(1,0,1,1);

    // face 4: right: y = 1
    cube_vert_pos[index++] =  glm::vec4(0,1,0,1);
    cube_vert_pos[index++] =  glm::vec4(0,1,1,1);
    cube_vert_pos[index++] =  glm::vec4(1,1,0,1);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,1);

    // face 5: back:  z = 0
    cube_vert_pos[index++] =  glm::vec4(0,0,0,1);
    cube_vert_pos[index++] =  glm::vec4(0,1,0,1);
    cube_vert_pos[index++] =  glm::vec4(1,0,0,1);
    cube_vert_pos[index++] =  glm::vec4(1,1,0,1);

    // face 6: front: z = 1
    cube_vert_pos[index++] =  glm::vec4(0,0,1,1);
    cube_vert_pos[index++] =  glm::vec4(0,1,1,1);
    cube_vert_pos[index++] =  glm::vec4(1,0,1,1);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,1);
}

void createCubeVertexNormals(glm::vec4 (&cube_vert_nor)[CUBE_VERT_COUNT]){
    int index = 0;
    // face 1: bottom, x = 0
    cube_vert_nor[index++] = glm::vec4(0,-1,0,1);
    cube_vert_nor[index++] = glm::vec4(0,-1,0,1);
    cube_vert_nor[index++] = glm::vec4(0,-1,0,1);
    cube_vert_nor[index++] = glm::vec4(0,-1,0,1);

    // face 2: top: x = 1
    cube_vert_nor[index++] = glm::vec4(0,1,0,1);
    cube_vert_nor[index++] = glm::vec4(0,1,0,1);
    cube_vert_nor[index++] = glm::vec4(0,1,0,1);
    cube_vert_nor[index++] = glm::vec4(0,1,0,1);

    // face 3: left: y = 0
    cube_vert_nor[index++] = glm::vec4(-1,0,0,1);
    cube_vert_nor[index++] = glm::vec4(-1,0,0,1);
    cube_vert_nor[index++] = glm::vec4(-1,0,0,1);
    cube_vert_nor[index++] = glm::vec4(-1,0,0,1);

    // face 4: right: y = 1
    cube_vert_nor[index++] = glm::vec4(1,0,0,1);
    cube_vert_nor[index++] = glm::vec4(1,0,0,1);
    cube_vert_nor[index++] = glm::vec4(1,0,0,1);
    cube_vert_nor[index++] = glm::vec4(1,0,0,1);

    // face 5: back:  z = 0
    cube_vert_nor[index++] = glm::vec4(0,0,-1,1);
    cube_vert_nor[index++] = glm::vec4(0,0,-1,1);
    cube_vert_nor[index++] = glm::vec4(0,0,-1,1);
    cube_vert_nor[index++] = glm::vec4(0,0,-1,1);

    // face 6: front: z = 1
    cube_vert_nor[index++] = glm::vec4(0,0,1,1);
    cube_vert_nor[index++] = glm::vec4(0,0,1,1);
    cube_vert_nor[index++] = glm::vec4(0,0,1,1);
    cube_vert_nor[index++] = glm::vec4(0,0,1,1);
}


void createCubeIndices(GLuint (&cube_idx)[CUBE_IDX_COUNT]){
    //Build 6 indices for each of the six faces
    int j = 0;
    for(int i = 0; i < CUBE_VERT_COUNT; i+=4){
        cube_idx[j++] = i + 2;
        cube_idx[j++] = i + 3;
        cube_idx[j++] = i + 1;
        cube_idx[j++] = i + 2;
        cube_idx[j++] = i + 1;
        cube_idx[j++] = i + 0;
    }
}

void Cube::create()
{
    GLuint cube_idx[CUBE_IDX_COUNT];
    glm::vec4 cube_vert_pos[CUBE_VERT_COUNT];
    glm::vec4 cube_vert_nor[CUBE_VERT_COUNT];

    createCubeVertexPositions(cube_vert_pos);
    createCubeVertexNormals(cube_vert_nor);
    createCubeIndices(cube_idx);

    count = CUBE_IDX_COUNT;

    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(cube_idx, CUBE_IDX_COUNT * sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(cube_vert_pos,CUBE_VERT_COUNT * sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(cube_vert_nor, CUBE_VERT_COUNT * sizeof(glm::vec4));
}
