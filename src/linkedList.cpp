#include "../include/linkedList.h"

Node::Node(int data) : data(data)
{
    prev = next = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

void LinkedList::insertKey(int key)
{
    Node* n = new Node(key);
    insertNode(n);
}

void LinkedList::insertNode(Node* n)
{
    n->next = head;
    if (head != nullptr) {
        head->prev = n;
    }
    head = n;
    size++;
}

Node* LinkedList::searchKey(int key)
{
    Node *n = head;
    while (n != nullptr && n->data != key) {
        n = n->next;
    }
    return n;
}

void LinkedList::deleteKey(int key)
{
    Node* n = searchKey(key);
    if (n == nullptr) {
        std::cout << "No value: " << key << " in list" << std::endl;
        return;
    }

    deleteNode(n);
}

void LinkedList::deleteNode(Node* n)
{
    if (n->prev != nullptr) {
        n->prev->next = n->next;
    } else {
        head = n->next;
    }

    if (n->next != nullptr) {
        n->next->prev = n->prev;
    }
    size--;
}

void LinkedList::print()
{
    Node* n = head;
    std::cout << "list: ";
    if (n == nullptr) {
        std::cout << "empty list" << std::endl;
        return;
    }
    while (n != nullptr) {
        std::cout << n->data << " ";
        n = n->next;
    }
    std::cout << std::endl;
}
