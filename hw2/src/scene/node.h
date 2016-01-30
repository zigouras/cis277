#pragma once

#include <vector>
#include "shaderprogram.h"
#include <la.h>

class Node
{
private:
    Node* parent;
    std::vector<Node*> children;
    ShaderProgram::Drawable* geometry;
    glm::vec4 geom_color;
    glm::mat4 transformation;
    float tx, ty, tz;
    float rx, ry, rz;
    float sx, sy, sz;

    glm::mat4 calculateTransformation();
public:
    Node();
    Node(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz);
    ~Node();

    int childCount();
    Node* childAt(int idx);
    void addChild(Node* c);
    void setParent(Node* n);
    void setGeomColor(const glm::vec4& c);
    const glm::vec4& getGeometryColor() const;

    void setGeometry(ShaderProgram::Drawable* g);
    ShaderProgram::Drawable* getGeometry();

    glm::mat4 getTransformation();
    void setTransformation(glm::mat4 value);
};
