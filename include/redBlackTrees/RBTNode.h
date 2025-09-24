#ifndef RBTNODE_H
#define RBTNODE_H

#include "color.h"

class RBTNode
{
public:
    int data;
    Color color;
    RBTNode* parent;
    RBTNode* left;
    RBTNode* right;
    RBTNode();
    RBTNode(int);
};

#endif // RBTNODE_H
