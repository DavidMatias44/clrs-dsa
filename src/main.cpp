#include <iostream>
#include "../include/sorting.h"
#include "../include/priorityQueue.h"
#include "../include/algorithms.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/linkedList.h"
#include "../include/BST.h"

int main(void)
{
    BST t;
    t.print(t.root);

    t.insertKey(50);
    t.insertKey(30);
    t.insertKey(20);
    t.insertKey(40);
    t.insertKey(70);
    t.insertKey(60);
    t.insertKey(80);
    t.print(t.root);
    std::cout << std::endl;

    t.deleteKey(60);
    t.print(t.root);
    std::cout << std::endl;

    t.deleteKey(70);
    t.print(t.root);
    std::cout << std::endl;

    t.deleteKey(30);
    t.print(t.root);
    std::cout << std::endl;

    t.insertKey(90);
    t.insertKey(100);
    t.print(t.root);
    std::cout << std::endl;

    t.insertKey(10);
    t.insertKey(5);
    t.print(t.root);
    std::cout << std::endl;

    return 0;
}
