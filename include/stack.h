#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>

class Stack
{
private:
    std::vector<int> data;
    int size;
public:
    int top;
    Stack(int);
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    void print();
};

#endif // STACK_H
