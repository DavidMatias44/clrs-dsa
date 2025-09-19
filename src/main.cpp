#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"
#include "../include/algorithms.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/linkedList.h"

int main(void)
{
    LinkedList l;
    std::cout << "list size: " << l.size;
    l.print();

    l.insertKey(1);
    std::cout << "list size: " << l.size << " | ";
    l.print();
    l.insertKey(2);
    std::cout << "list size: " << l.size << " | ";
    l.print();
    l.insertKey(4);
    std::cout << "list size: " << l.size << " | ";
    l.print();

    std::cout << std::endl;

    l.deleteKey(3);
    std::cout << "list size: " << l.size << " | ";
    l.print();
    l.deleteKey(2);
    std::cout << "list size: " << l.size << " | ";
    l.print();
    l.deleteKey(2);
    std::cout << "list size: " << l.size << " | ";
    l.print();
    l.deleteKey(1);
    std::cout << "list size: " << l.size << " | ";
    l.print();

    return 0;
}
