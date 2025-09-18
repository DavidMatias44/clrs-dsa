#include "../include/stack.h"
#include <limits>

Stack::Stack(int n)
{
    for (int i = 0; i < n; i++) {
        data.push_back(0);
    }

    size = 0;
    top = -1;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return size == data.size();
}

void Stack::push(int e)
{
    if (isFull()) {
        std::cout << "Error: stack overflow" << std::endl;
        return;
    }

    data[++top] = e;
    size++;
}

int Stack::pop()
{
    if (isEmpty()) {
        std::cout << "Error: stack underflow" << std::endl;
        return std::numeric_limits<int>::min();
    }

    size--;
    return data[top--];
}

void Stack::print()
{   
    std::cout << "stack: ";
    if (isEmpty()) {
        std::cout << "The stack is empty";
    }
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
