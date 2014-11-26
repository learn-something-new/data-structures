// in stack.cpp
#include <iostream>
#include "stack.h"

// constructor
Stack::Stack()
{
    // set top location to -1 indicating a empty stack
    top = -1;
}

// add to the stack
void Stack::push(int a)
{
    // increment top
    top++;

    // if top is below limit go ahead and add
    // else cout an error and de-increment top
    if(top<MAX)
    {
        arr[top] = a;
    }
    else
    {
        std::cout << "STACK FULL!" << std::endl;
        top--;
    }
}

// delete from top of stack and return item
int Stack::pop()
{
    // if top is -1 the stack is empty so cout an error
    // else remove the top item from the stack
    if(top == -1)
    {
        std::cout << "STACK IS EMPTY!" << std::endl;

        return 0;
    }
    else
    {
        int data = arr[top];
        arr[top] = 0;
        top--;

        return data;
    }
}
