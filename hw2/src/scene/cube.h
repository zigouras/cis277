#pragma once

#include <scene/geometry.h>
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class Cube : public Geometry
{
public:
    Cube();
    virtual void create();
};
