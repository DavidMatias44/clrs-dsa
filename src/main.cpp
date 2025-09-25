#include <iostream>
#include "../include/redBlackTrees/RBT.h"

int main(void)
{
    RBT t;
    t.insertKey(50);
    t.insertKey(40);
    t.insertKey(60);
    t.insertKey(30);
    t.insertKey(20);
    t.insertKey(45);
    t.insertKey(44);
    t.insertKey(46);
    t.insertKey(55);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "delete node with no children - no recoloring" << std::endl;
    t.deleteKey(46);
    t.print(t.root);
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "delete node with left children - only recoloring" << std::endl;
    t.deleteKey(60);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "delete node with two children - only recoloring" << std::endl;
    t.deleteKey(30);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "delete node (root) with two children - only recoloring" << std::endl;
    t.deleteKey(44);
    t.print(t.root);
    std::cout << std::endl;


    return 0;
}
