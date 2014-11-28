// in linkedlist.cpp
#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = NULL;
    end = NULL;
}

LinkedList::~LinkedList()
{
    Node *temp = head;

    if(temp)
    {
        while(temp && temp->next)
        {

            head = temp->next;
            delete temp;
            temp = head;
        }

        delete temp;
    }
}

void LinkedList::add(int num)
{
    Node *node = new Node();
    node->data = num;

    if(head == NULL)
    {
        head = node;
        end = node;
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
        end = node;
    }
}

void LinkedList::del(int num)
{
    Node *temp = head;

    while(temp)
    {
        if(temp->data == num)
        {
            std::cout << "deleting " << temp->data << std::endl;
            Node *prev = temp->prev;
            prev->next = temp->next;
            delete temp;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void LinkedList::displayReverse()
{
    Node *temp = end;

    while(temp)
    {
        std::cout << temp->data << std::endl;
        temp = temp->prev;
    }

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
