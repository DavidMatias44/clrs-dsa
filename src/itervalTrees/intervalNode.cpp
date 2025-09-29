#include "../include/intervalTrees/intervalNode.h"

IntervalNode::IntervalNode() :
    interval(0, 0), max(0), color(Color::BLACK), parent(nullptr), left(nullptr), right(nullptr)
{ }

IntervalNode::IntervalNode(int low, int high) :
    IntervalNode(Interval(low, high))
{ }

IntervalNode::IntervalNode(Interval interval) : 
    interval(interval), max(interval.high), color(Color::RED), parent(nullptr), left(nullptr), right(nullptr)
{ }
