// in linkedlist.h
#include <iostream>

struct Node
{
    Node() 
    {
        next = NULL;
        prev = NULL;
    }

    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
    private:
        Node *head;
        Node *end;

    public:
        LinkedList();
        ~LinkedList();
        void add(int num);
        void del(int num);
        void display();
        void displayReverse();
};
