// in queue.h
#include <iostream>

struct node
{
    int data;
    node *link;
};

class Queue 
{
    private:
        node *front, *rear;

    public:
        Queue();
        void add(int num);
        int del();
        ~Queue();
};
