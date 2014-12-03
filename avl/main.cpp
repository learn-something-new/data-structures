// in main.cpp
#include <iostream>
#include <cstdlib>
#include "avl.h"

int main()
{
    AVLTree *avl = new AVLTree();

    for(int x = 0; x <= 10; x++)
    {
        int num = (rand() % 100) + 1;
        std::cout << num << " ";
        avl->add(num);
    }
    std::cout << std::endl;

    avl->display();

    delete avl;

    return 0;
}
