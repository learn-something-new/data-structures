// in linkedlist.h
#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
    private:
        Node *head;

    public:
        LinkedList();
        ~LinkedList();
        void add(int num);
        void del(int num);
        void display();
};
