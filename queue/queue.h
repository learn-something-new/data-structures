// in queue.h
#include <iostream>

// maximum size of the stack
#define MAX 10

class Queue
{
    private:
        int t[MAX];
        // the addition end
        int front;
        // the deletion end
        int end;

    public:
        Queue();
        void del();
        void add(int item);
        void display();
};
