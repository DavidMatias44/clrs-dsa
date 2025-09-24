#include "../../include/redBlackTrees/RBTNode.h"

RBTNode::RBTNode() : data(0), color(Color::BLACK), parent(nullptr), left(nullptr), right(nullptr)
{ }

RBTNode::RBTNode(int data) : data(data), color(Color::RED), parent(nullptr), left(nullptr), right(nullptr)
{ }
