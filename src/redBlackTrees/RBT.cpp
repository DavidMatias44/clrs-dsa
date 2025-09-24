#include "../../include/redBlackTrees/RBT.h"

RBT::RBT()
{ 
    nil = new RBTNode();
    root = nil;
}

void RBT::insertKey(int data)
{
    RBTNode* z = new RBTNode(data);
    insertNode(z);
}

void RBT::insertNode(RBTNode* z)
{
    RBTNode* y = nil;
    RBTNode* x = root;
    while (x != nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nil) {
        root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = nil;
    z->right = nil;
    
    insertNodeFixup(z);
}

void RBT::insertNodeFixup(RBTNode* z)
{
    while (z->parent->color == Color::RED) {
        if (z->parent == z->parent->parent->left) {
            RBTNode* y = z->parent->parent->right;
            if (y->color == Color::RED) {
                z->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }

                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                rotateRight(z->parent->parent);
            }
        } else {
            RBTNode* y = z->parent->parent->left;
            if (y->color == Color::RED) {
                z->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }   
                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                rotateLeft(z->parent->parent);
            }
        }
    }

    root->color = Color::BLACK;
}

void RBT::rotateLeft(RBTNode* x)
{
    RBTNode* y = x->right;
    x->right = y->left;
    if (y->left != nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RBT::rotateRight(RBTNode* x)
{
    RBTNode* y = x->left;
    x->left = y->right;
    if (y->right != nil) {
        y->right->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}


void RBT::print(RBTNode* n) 
{
    if (n != nil) {
        print(n->left);
        if (n == root) std::cout << "root:";
        std::cout << " { " << n->data << ", " << n->color << " } ";
        print(n->right);
    }
}
