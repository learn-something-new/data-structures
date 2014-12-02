// in main.cpp
#include <iostream>
#include "avl.h"

int main()
{
    AVLTree avl;
    Node *temp;

    avl.add(5);
    avl.add(7);
    avl.add(3);
    avl.add(1);
    avl.add(12);
    avl.add(9);
    avl.add(100);

    avl.del(12);

    avl.display();

    return 0;
}
