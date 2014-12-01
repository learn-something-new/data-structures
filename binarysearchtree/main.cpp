// in main.cpp
#include <iostream>
#include "bst.h"

int main()
{
    BinarySearchTree bst;

    bst.add(5);
    bst.add(3);
    bst.add(7);

    bst.display();

    return 0;
}
