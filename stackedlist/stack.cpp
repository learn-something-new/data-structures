// in stack.cpp
#include <iostream>
#include "stack.h"

// constructor
Stack::Stack()
{
    // set top location to -1 indicating a empty stack
    top = NULL;
}

// deconstructor
Stack::~Stack()
{
    // if top is null the list is already empty
    if(top == NULL)
        return;

    // loop through the list and remove each node
    node *tmp;

    while(top != NULL)
    {
        tmp = top;
        top = top->link;
        delete tmp;
    }
}

// add to the stack
void Stack::push(int a)
{
    node *tmp = new node;

    tmp->data = a;
    tmp->link = top;
    top = tmp;
}

// delete from top of stack and return item
int Stack::pop()
{
    if(top == NULL)
    {
        std::cout << "STACK EMPTY!";
        return 0;
    }

    node *tmp;
    int n;

    tmp = top;
    n = tmp->data;
    top = top->link;

    delete tmp;
    return n;
}
