#include <scenegraphtraverseanddraw.h>
#include <scene/node.h>
#include <la.h>

SceneGraphTraverseAndDraw::SceneGraphTraverseAndDraw(Node *_root) {
    root = _root;
    transform(root,glm::mat4(1));
}

// apply this transformation to this node and all of its children recursively
void SceneGraphTraverseAndDraw::transform(Node* node,glm::mat4 transformation) {
    transformation = transformation * node->getTransformation();
    node->setTransformation(transformation);
    if ( node->childCount() > 0 ) {
        for(int i=0;i<node->childCount();i++) {
            transform(node->childAt(i),transformation);
        }
    }

}

void SceneGraphTraverseAndDraw::render() {
    draw(root);
}

Node *SceneGraphTraverseAndDraw::getRoot() const
{
    return root;
}

void SceneGraphTraverseAndDraw::setRoot(Node *value)
{
    root = value;
}

void SceneGraphTraverseAndDraw::draw(Node* node) {
    if ( node->childCount() > 0 ) {
        for(int i=0;i<node->childCount();i++) {
            draw(node->childAt(i));
        }
    }
    progLambert->setModelMatrix(node->getTransformation());
    progLambert->draw(*gLWidget277,*node->getGeometry());
}

GLWidget277 *SceneGraphTraverseAndDraw::getGLWidget277()
{
    return gLWidget277;
}

void SceneGraphTraverseAndDraw::setGLWidget277(GLWidget277 *value)
{
    gLWidget277 = value;
}

ShaderProgram* SceneGraphTraverseAndDraw::getProgLambert()
{
    return progLambert;
}

void SceneGraphTraverseAndDraw::setProgLambert(ShaderProgram *value)
{
    progLambert = value;
}


