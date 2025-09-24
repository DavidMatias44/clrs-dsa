#include <iostream>
#include "../include/redBlackTrees/RBT.h"

int main(void)
{
    RBT t;
    t.insertKey(50);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl << "no rotations, no recoloring" << std::endl;
    t.insertKey(40);
    t.insertKey(60);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl << "only recoloring" << std::endl;
    t.insertKey(30);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl << "recoloring and right rotation" << std::endl;
    t.insertKey(20);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl << "only recoloring" << std::endl;
    t.insertKey(45);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl << "recoloring, right and left rotation" << std::endl;
    t.insertKey(44);
    t.print(t.root);
    std::cout << std::endl;

    std::cout << std::endl << "recoloring, left and right rotation" << std::endl;
    t.insertKey(46);
    t.print(t.root);
    std::cout << std::endl;

    return 0;
}
