#ifndef INTERVALNODE_H
#define INTERVALNODE_H

#include "interval.h"
#include "../redBlackTrees/color.h"

class IntervalNode
{
public:
    Interval interval;
    int max;
    Color color;
    IntervalNode* parent;
    IntervalNode* left;
    IntervalNode* right;
    IntervalNode();
    IntervalNode(int, int);
    IntervalNode(Interval);
};

#endif // INTERVALNODE_H
