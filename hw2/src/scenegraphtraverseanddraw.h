#pragma once

#include <scene/node.h>

class SceneGraphTraverseAndDraw {
private:
    Node* root;
    ShaderProgram* progLambert;
    GLWidget277* gLWidget277;
    void draw(Node* node);
    void transform(Node* node,glm::mat4 transformation);
public:
    void render();
    SceneGraphTraverseAndDraw(Node* _root);
    ShaderProgram* getProgLambert();
    void setProgLambert(ShaderProgram *value);
    GLWidget277* getGLWidget277();
    void setGLWidget277(GLWidget277 *value);
    Node *getRoot() const;
    void setRoot(Node *value);
};

