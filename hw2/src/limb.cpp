#include "limb.h"
#include "scene/node.h"

Limb::Limb() : Node() {

}

Limb::Limb(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) :
    Node(tx,ty,tz,rx,ry,rz,sx,sy,sz){
}

void Limb::init() {
    this->setGeometry(upperGeometry);
    lowerNode->setGeometry(lowerGeometry);
    lowerNode->setParent(this);
}
