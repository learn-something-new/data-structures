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

    if(head == NULL)
    {
        head = node;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
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

    if(temp != NULL)
    {
        while(temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

}
