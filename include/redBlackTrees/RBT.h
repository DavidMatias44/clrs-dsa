#ifndef RBT_H
#define RBT_H

#include "RBTNode.h"
#include <iostream>

class RBT
{
private:
    RBTNode* nil;
    void insertNode(RBTNode*);
    void insertNodeFixup(RBTNode*);
    void rotateLeft(RBTNode*);
    void rotateRight(RBTNode*);
    RBTNode* searchKey(RBTNode*, int);
    void deleteNode(RBTNode*);
    void transplant(RBTNode*, RBTNode*);
    RBTNode* minimum(RBTNode*);
    void deleteNodeFixup(RBTNode*);
public:
    RBTNode* root;
    RBT();
    void insertKey(int);
    void deleteKey(int);
    void print(RBTNode*);
};

#endif // RBT_H
