// in queue.cpp
#include <iostream>
#include "queue.h"

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    node *q;

    if(front == NULL)
    {
        return;
    }

    node *tmp;

    while(front != NULL)
    {
        tmp = front;
        front = front->link;
        delete tmp;
    }
}

void Queue::add(int num)
{
    node *tmp;
    tmp = new node;

    tmp->data = num;
    tmp->link = NULL;

    if(front == NULL)
    {
        rear = front = tmp;
        return;
    }

    rear->link = tmp;
    rear = rear->link;
}

int Queue::del()
{
    if(front == NULL)
    {
        std::cout << "QUEUE EMPTY";
        return 0;
    }

    node *tmp;
    int n;

    n = front->data;
    tmp = front;
    front = front->link;

    delete tmp;
    return n;
}
