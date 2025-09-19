#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int);
};

#endif // NODE_H


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList
{
private:
    Node* head;
    void insertNode(Node*);
    void deleteNode(Node*);
    Node* searchKey(int);
public:
    int size;
    LinkedList();
    void insertKey(int);
    void deleteKey(int);
    void print();
};

#endif // LINKEDLIST_H