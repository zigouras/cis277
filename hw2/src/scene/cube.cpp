#include "Cube.h"
#include<la.h>
#include <iostream>

static const int CUBE_IDX_COUNT = 24;
static const int CUBE_VERT_COUNT = 24;

Cube::Cube() : Geometry()
{}


//These are functions that are only defined in this cpp file. They're used for organizational purposes
//when filling the arrays used to hold the vertex and index data.
void createCubeVertexPositions(glm::vec4 (&cube_vert_pos)[CUBE_VERT_COUNT]){
    // create 4 vertices for each of the 6 faces of the cube
    int index = 0;

    // face 1: x = 0
    cube_vert_pos[index++] =  glm::vec4(0,0,0,0);
    cube_vert_pos[index++] =  glm::vec4(0,0,1,0);
    cube_vert_pos[index++] =  glm::vec4(0,1,0,0);
    cube_vert_pos[index++] =  glm::vec4(0,1,1,0);

    // face 2: x = 1
    cube_vert_pos[index++] =  glm::vec4(1,0,0,0);
    cube_vert_pos[index++] =  glm::vec4(1,0,1,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,0,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,0);

    // face 3: y = 0
    cube_vert_pos[index++] =  glm::vec4(0,0,0,0);
    cube_vert_pos[index++] =  glm::vec4(0,0,1,0);
    cube_vert_pos[index++] =  glm::vec4(1,0,0,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,0);

    // face 4: y = 1
    cube_vert_pos[index++] =  glm::vec4(0,1,0,0);
    cube_vert_pos[index++] =  glm::vec4(0,1,1,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,0,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,0);

    // face 5: z = 0
    cube_vert_pos[index++] =  glm::vec4(0,0,0,0);
    cube_vert_pos[index++] =  glm::vec4(0,1,0,0);
    cube_vert_pos[index++] =  glm::vec4(1,0,0,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,0,0);

    // face 6: z = 1
    cube_vert_pos[index++] =  glm::vec4(0,0,1,0);
    cube_vert_pos[index++] =  glm::vec4(0,1,1,0);
    cube_vert_pos[index++] =  glm::vec4(1,0,1,0);
    cube_vert_pos[index++] =  glm::vec4(1,1,1,0);
}

void setValueToZeroOrOneAtIndexAndStoreVector(int index, glm::vec4 &v, glm::vec4 (&cube_vert_pos)[CUBE_VERT_COUNT]) {
    for(int j=0;j<2;j++) {
        v[index] = j;
    }
}

void createCubeVertexNormals(glm::vec4 (&cube_vert_nor)[CUBE_VERT_COUNT]){
    //Store top cap normals (IDX 0 - 19)
    for(int i = 0; i < CUBE_VERT_COUNT; i++){
        cube_vert_nor[i] =  glm::vec4(0,1,0,0);
    }

}


void createCubeIndices(GLuint (&cube_idx)[CUBE_IDX_COUNT]){
    //Build indices for the top cap (18 tris, indices 0 - 53, up to vertex 19)
    for(int i = 0; i < CUBE_IDX_COUNT; i++){
        cube_idx[i] = i;
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
