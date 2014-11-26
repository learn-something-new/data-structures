// in linkedlist.cpp
#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList()
{
    p = NULL;
}

LinkedList::~LinkedList()
{
    node *q;

    if(p == NULL)
    {
        return;
    }

    while(p != NULL)
    {
        q = p->link;
        delete p;
        p = q;
    }
}

void LinkedList::append(int num)
{
    node *q, *t;

    if(p == NULL)
    {
        p = new node;
        p->data = num;
        p->link = NULL;
    }
    else
    {
        q = p;

        while(q->link != NULL)
        {
            q = q->link;
        }

        t = new node;
        t->data = num;
        t->link = NULL;
        q->link = t;
    }
}

void LinkedList::display()
{
    node *q;

    for(q = p; q != NULL; q = q->link)
    {
        std::cout << q->data << " ";
    }

    std::cout << std::endl;
}
