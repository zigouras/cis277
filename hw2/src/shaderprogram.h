#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glwidget277.h>
#include <la.h>
#include <glm/glm.hpp>

#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>


class ShaderProgram
{
public:
    //This defines a class which can be rendered by our shader program.
    //Make any geometry a subclass of ShaderProgram::Drawable in order to render it with the ShaderProgram class.
    class Drawable
    {
    public:
        virtual GLenum drawMode() = 0;
        virtual int elemCount() = 0;
        virtual bool bindIdx() = 0;
        virtual bool bindPos() = 0;
        virtual bool bindNor() = 0;
        virtual bool bindCol() = 0;

        void setColor(const glm::vec4& c);
        glm::vec4 getColor();

    protected:
        glm::vec4 color;
    };

public:
    QOpenGLShaderProgram prog;

    int attrPos;
    int attrNor;
    int attrCol;

    int unifModel;
    int unifModelInvTr;
    int unifViewProj;
    int unifColor;

public:
    void create(const char *vertfile, const char *fragfile);
    void setModelMatrix(const glm::mat4 &model);
    void draw(GLWidget277 &f, Drawable &d);
};


#endif // SHADERPROGRAM_H
