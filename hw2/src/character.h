#ifndef Character_H
#define Character_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/node.h>


#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class Character
    : public GLWidget277
{
private:
    QOpenGLVertexArrayObject vao;

    Node body;

    ShaderProgram prog_lambert;
    ShaderProgram prog_wire;

public:
    explicit Character(QWidget *parent = 0);
    ~Character();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void initBody();
protected:
    void keyPressEvent(QKeyEvent *e);
};


#endif // Character_H
