#pragma once

#include <scene/cylinder.h>
#include <scene/geometry.h>
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class Limb : public Geometry
{
private:
    Cylinder lower, upper;
public:
    Limb();
    virtual void create();
    virtual void articulate(long angle);
};
