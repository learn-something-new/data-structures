// in linkedlist.cpp
#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
}

void LinkedList::add(int num)
{
    Node *node = new Node();
    node->data = num;
    node->prev = NULL;
    node->next = NULL;

    if(head == NULL)
    {
        head = node;
    }
    else
    {
        Node *temp = head;

        while(temp->next)
        {
            temp = temp->next;
        }

        node->prev = temp;
        temp->next = node;
    }
}

void LinkedList::del(int num)
{
}

void LinkedList::display()
{
    Node *temp = head;

    while(temp)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

}
