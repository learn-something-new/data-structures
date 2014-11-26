// in main.cpp
#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList list;

    list.append(10);
    list.append(4);
    list.append(17);
    list.append(71);

    list.display();

    list.del(4);

    list.display();

    return 0;
}
