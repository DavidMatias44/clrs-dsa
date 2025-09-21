#include "../include/BST.h"

BSTNode::BSTNode(int data) : data(data), parent(nullptr), left(nullptr), right(nullptr)
{ }

BST::BST() : root(nullptr)
{ }

void BST::insertKey(int data)
{
    BSTNode *n = new BSTNode(data);
    insertNode(n);
}

void BST::insertNode(BSTNode* n)
{
    BSTNode* y = nullptr;
    BSTNode* x = root;

    while (x != nullptr) {
        y = x;
        if (n->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    n->parent = y;

    if (y == nullptr) {
        root = n;
    } else if (n->data < y->data) {
        y->left = n;
    } else {
        y->right = n;
    }
}

void BST::deleteKey(int data)
{
    BSTNode* n = searchKey(root, data);
    deleteNode(n);
}

BSTNode* BST::searchKey(BSTNode* n, int data)
{
    if (n == nullptr || data == n->data) {
        return n;
    }

    if (data < n->data) {
        return searchKey(n->left, data);
    } 
    return searchKey(n->right, data);
}

void BST::deleteNode(BSTNode* n)
{
    if (n->left == nullptr) {
        transplant(n, n->right);
        return;
    }

    if (n->right == nullptr) {
        transplant(n, n->left);
        return;
    }

    BSTNode* y = minimum(n->right);
    if (y->parent != n) {
        transplant(y, y->right);
        y->right = n->right;
        y->right->parent = y;
    }
    transplant(n, y);
    y->left = n->left;
    y->left->parent = y;
}

void BST::transplant(BSTNode* u, BSTNode* v)
{
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != nullptr) {
        v->parent = u->parent;
    }
}


BSTNode* BST::minimum(BSTNode* n)
{
    if (n->left == nullptr) {
        return n;
    }
    
    return minimum(n->left);
}

BSTNode* BST::maximum(BSTNode* n)
{
    if (n->right == nullptr) {
        return n;
    }
    
    return maximum(n->right);
}

void BST::print(BSTNode* n)
{   
    if (n != nullptr) {
        print(n->left);
        std::cout << n->data << " ";
        print(n->right);
        return;
    };
}
