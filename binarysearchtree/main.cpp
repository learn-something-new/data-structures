// in main.cpp
#include <iostream>
#include "bst.h"

int main()
{
    BinarySearchTree bst;

    bst.add(5);
    bst.add(7);
    bst.add(3);
    bst.add(1);
    bst.add(12);
    bst.add(9);
    bst.add(100);

    bst.display();

    return 0;
}
