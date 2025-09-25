#include "../../include/redBlackTrees/RBT.h"

RBT::RBT()
{ 
    nil = new RBTNode();
    root = nil;
}

void RBT::insertKey(int key)
{
    RBTNode* z = new RBTNode(key);
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

void RBT::deleteKey(int key) 
{
    RBTNode* n = searchKey(root, key);
    deleteNode(n);
}

RBTNode* RBT::searchKey(RBTNode* n, int key)
{
    if (n == nil || key == n->data) {
        return n;
    }

    if (key < n->data) {
        return searchKey(n->left, key);
    } 
    return searchKey(n->right, key);
}

void RBT::deleteNode(RBTNode* z)
{
    RBTNode* y = z;
    Color yOriginalColor = y->color;
    RBTNode* x = nil;

    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (yOriginalColor == Color::BLACK) {
        deleteNodeFixup(x);
    }
}

RBTNode* RBT::minimum(RBTNode* n)
{
    if (n->left == nil) {
        return n;
    }
    
    return minimum(n->left);
}

void RBT::transplant(RBTNode* u, RBTNode* v)
{
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RBT::deleteNodeFixup(RBTNode* x)
{
    while (x != root && x->color == Color::BLACK) {
        if (x == x->parent->left) {
            RBTNode* w = x->parent->right;

            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->right->color == Color::BLACK) {
                    w->left->color = Color::BLACK;
                    w->color = Color::RED;
                }

                rotateRight(w);
                w = x->parent->right;
                w->color = x->parent->color;
                x->parent->color = Color::BLACK;
                w->right->color = Color::BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            RBTNode* w = x->parent->left;

            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }

            if (w->right->color == Color::BLACK && w->left->color == Color::BLACK) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->left->color == Color::BLACK) {
                    w->right->color = Color::BLACK;
                    w->color = Color::RED;
                }

                rotateLeft(w);
                w = x->parent->left;
                w->color = x->parent->color;
                x->parent->color = Color::BLACK;
                w->left->color = Color::BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }

    x->color = Color::BLACK;
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
