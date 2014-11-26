// in linkedlist.h
#include <iostream>

class LinkedList
{
    private:
        struct node
        {
            int data;
            node *link;
        }*p;

    public:
        LinkedList();
        void append(int num);
        void del(int num);
        void display();
        int count();
        ~LinkedList();
};
