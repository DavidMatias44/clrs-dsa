#include "../include/queue.h"

Queue::Queue(int n)
{
    for (int i = 0; i < n; i++) {
        data.push_back(0);
    }

    size = 0;
    head = tail = -1;
}

bool Queue::isEmpty()
{
    return size == 0;
}

bool Queue::isFull()
{
    return size == data.size();
}

void Queue::enqueue(int e)
{
    if (isFull()) {
        std::cout << "Error: queue overflow" << std::endl;
        return;
    }

    if (isEmpty()) {
        data[++head] = e;
        tail = head;
        size++;
        return;
    }

    if (tail == data.size() - 1) {
        tail = 0;
    } else {
        tail++;
    }
    data[tail] = e;
    size++;
}

int Queue::dequeue()
{
    if (isEmpty()) {
        std::cout << "Error: queue underflow" << std::endl;
        return std::numeric_limits<int>::min();
    }

    int e = data[head];
    if (head == data.size() - 1) {
        head = 0;
    } else {
        head++;
    }
    size--;

    if (isEmpty()) {
        head = tail = -1;
    }

    return e;
}

void Queue::print()
{
    std::cout << "Queue: ";
    if (isEmpty()) {
        std::cout << "queue is empty";
    }
    int i = head;
    for (int j = 0; j < size; j++) {
        std::cout << data[i] << " ";

        if (i == data.size() - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    std::cout << std::endl;
}
