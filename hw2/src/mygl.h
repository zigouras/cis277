#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/cube.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public GLWidget277
{
private:
    QOpenGLVertexArrayObject vao;

    Cube geom_cube;//The instance of a unit cube we can use to render any cube
    ShaderProgram prog_lambert;
    ShaderProgram prog_wire;

public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    void keyPressEvent(QKeyEvent *e);
};


#endif // MYGL_H
