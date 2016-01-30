#pragma once

#include <scene/cylinder.h>
#include <scene/node.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <la.h>

class Limb : public Node
{
public:
    Limb();
    Limb(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz);
    ~Limb();
    virtual void init();
private:
    Node* lowerNode;
    Cylinder* upperGeometry;
    Cylinder* lowerGeometry;
};
