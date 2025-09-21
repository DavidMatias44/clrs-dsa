#ifndef BST_NODE_H
#define BST_NODE_H

class BSTNode
{
public:
    int data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int);
};

#endif // BST_NODE_H


#ifndef BST_H
#define BST_Hs

#include <iostream>

class BST
{
private:
    void insertNode(BSTNode*);
    void deleteNode(BSTNode*);
    void transplant(BSTNode*, BSTNode*);
public:
    BSTNode* root;
    BST();
    void insertKey(int);
    void deleteKey(int);
    BSTNode* searchKey(BSTNode*, int);
    BSTNode* minimum(BSTNode*);
    BSTNode* maximum(BSTNode*);
    void print(BSTNode*); // inorder
};

#endif // BST_H
