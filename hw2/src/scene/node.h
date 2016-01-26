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

    float tx, ty, tz;
    float rx, ry, rz;
    float sx, sy, sz;
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

    glm::mat4 getTransMat();
};
