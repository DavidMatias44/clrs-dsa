#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"
#include "../include/algorithms.h"
#include "../include/stack.h"

int main(void)
{
    Stack s(5);

    std::cout << "stack is empty: " << s.isEmpty() << std::endl;
    s.print();

    s.pop();

    s.push(12);
    s.push(23);
    s.push(65);
    s.push(82);
    s.push(92);
    s.push(23);
    s.print();

    s.pop();
    s.pop();
    s.print();

    s.pop();
    s.pop();
    s.pop();
    s.print();
    s.pop();

    return 0;
}
