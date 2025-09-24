#ifndef RBT_H
#define RBT_H

#include "RBTNode.h"
#include <iostream>

class RBT
{
private:
    void insertNode(RBTNode*);
    void insertNodeFixup(RBTNode*);
    void deleteNode(RBTNode*);
    void deleteNodeFixup(RBTNode*);
    void transplant(RBTNode*, RBTNode*);
    void rotateLeft(RBTNode*);
    void rotateRight(RBTNode*);
public:
    RBTNode* root;
    RBTNode* nil;
    RBT();
    void insertKey(int);
    void deleteKey(int);
    void print(RBTNode*);
};

#endif // RBT_H
