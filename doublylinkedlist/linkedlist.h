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
        Node *end;

    public:
        LinkedList();
        ~LinkedList();
        void add(int num);
        void del(int num);
        void display();
        void displayReverse();
};
