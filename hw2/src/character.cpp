#include "Character.h"
#include <la.h>
#include<scenegraphtraverseanddraw.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>


Character::Character(QWidget *parent)
    : GLWidget277(parent)
{
}

Character::~Character()
{
    makeCurrent();

    vao.destroy();
    torso.destroy();
    head.destroy();
    rightUpperArm.destroy();
    rightLowerArm.destroy();
    leftUpperArm.destroy();
    leftLowerArm.destroy();
    rightUpperLeg.destroy();
    rightLowerLeg.destroy();
    leftUpperLeg.destroy();
    leftLowerLeg.destroy();
}

void Character::initializeGL()
{
    // Create an OpenGL context
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    vao.create();

    //Create the body objects
    torso.create();
    head.create();
    rightUpperArm.create();
    rightLowerArm.create();
    leftUpperArm.create();
    leftLowerArm.create();
    rightUpperLeg.create();
    rightLowerLeg.create();
    leftUpperLeg.create();
    leftLowerLeg.create();


    // Create and set up the diffuse shader
    prog_lambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the wireframe shader
    prog_wire.create(":/glsl/wire.vert.glsl", ":/glsl/wire.frag.glsl");

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    vao.bind();
}

void Character::resizeGL(int w, int h)
{
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    // vvv TODO REPLACE THIS CODE IN HW2
    glm::vec4 c1(1.1933f, 0, 1.1933f, 0);
    glm::vec4 c2(0.9856f, 1.9712f, -0.9856f, 0);
    glm::vec4 c3(0.5785f, -0.5785f, -0.5785f, 11.9484f);
    glm::vec4 c4(0.5774f, -0.5774f, -0.5774f, 12.1244f);
    glm::mat4 viewproj(c1, c2, c3, c4);
    viewproj = glm::transpose(viewproj);
    // ^^^ TODO REPLACE THIS CODE IN HW2

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)
    QMatrix4x4 qviewproj = la::to_qmat(viewproj);

    prog_lambert.prog.bind();
    prog_lambert.prog.setUniformValue(prog_lambert.unifViewProj, qviewproj);

    prog_wire.prog.bind();
    prog_wire.prog.setUniformValue(prog_wire.unifViewProj, qviewproj);

    printGLErrorLog();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, paintGL is called implicitly.
void Character::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    initBody();

    SceneGraphTraverseAndDraw* sceneGraphTraverseAndDraw =
            new SceneGraphTraverseAndDraw(scene);
    sceneGraphTraverseAndDraw->setGLWidget277(this);
    sceneGraphTraverseAndDraw->setProgLambert(&prog_lambert);
    sceneGraphTraverseAndDraw->render();
}

// this initializes the body geometry so each polygon is situated
// in RELATION to it's parent
// you can change any of the node variables to transform a body part
void Character::initBody() {
    // the root node is the torso
    scene = new Node(0,1.6,0,0,-32,0,1.5,3,1.5);//float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz);
    torso.setColor(glm::vec4(1,0,0,1));
    scene->setGeometry(&torso);

    headNode = new Node(-0.5,0.5,-0.5,0,0,0,1,0.5,1);
    head.setColor(glm::vec4(0,2,0,1));
    headNode->setGeometry(&head);
    scene->addChild(headNode);

    leftUpperArmNode = new Node(1,0,0.2,0,0,60,0.3,1,0.3);
    leftUpperArm.setColor(glm::vec4(0,0,1,1));
    leftUpperArmNode->setGeometry(&leftUpperArm);
    scene->addChild(leftUpperArmNode);

    leftLowerArmNode  = new Node(0,-1,0,0,0,0,1,1,1);
    leftLowerArm.setColor(glm::vec4(0,1,1,1));
    leftLowerArmNode->setGeometry(&leftLowerArm);
    leftUpperArmNode->addChild(leftLowerArmNode);

    rightUpperArmNode = new Node(-1,0,-0.2,0,0,-60,0.3,1,0.3);
    rightUpperArm.setColor(glm::vec4(0,0,1,1));
    rightUpperArmNode->setGeometry(&rightUpperArm);
    scene->addChild(rightUpperArmNode);

    rightLowerArmNode = new Node(0,-1,0,0,0,0,1,1,1);
    rightLowerArm.setColor(glm::vec4(0,1,1,1));
    rightLowerArmNode->setGeometry(&rightLowerArm);
    rightUpperArmNode->addChild(rightLowerArmNode);

    leftUpperLegNode = new Node(1,-1,0.2,0,0,50,0.5,1.5,0.5);
    leftUpperLeg.setColor(glm::vec4(0,0,1,1));
    leftUpperLegNode->setGeometry(&leftUpperLeg);
    scene->addChild(leftUpperLegNode);

    leftLowerLegNode  = new Node(0,-1,0,0,0,0,1,1,1);
    leftLowerLeg.setColor(glm::vec4(0,1,1,1));
    leftLowerLegNode->setGeometry(&leftLowerLeg);
    leftUpperLegNode->addChild(leftLowerLegNode);

    rightUpperLegNode = new Node(-1,-1,0.2,0,0,-50,0.5,1.5,0.5);
    rightUpperLeg.setColor(glm::vec4(0,0,1,1));
    rightUpperLegNode->setGeometry(&rightUpperLeg);
    scene->addChild(rightUpperLegNode);

    rightLowerLegNode  = new Node(0,-1,0,0,0,0,1,1,1);
    rightLowerLeg.setColor(glm::vec4(0,1,1,1));
    rightLowerLegNode->setGeometry(&rightLowerLeg);
    rightUpperLegNode->addChild(rightLowerLegNode);
}

void Character::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    }
}
