#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <iostream>
#include <limits>

class Queue 
{
private:
    std::vector<int> data;
    int size;
public:
    int head;
    int tail;
    Queue(int);
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    int dequeue();
    void print();
};

#endif // QUEUEU_H
