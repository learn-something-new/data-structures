// in main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "avl.h"

int main()
{
    AVLTree *avl = new AVLTree();

    srand(time(NULL));

    for(int x = 0; x <= 100; x++)
    {
        int num = (rand() % 100) + 1;
        std::cout << num << " ";
        avl->add(num);
    }
    std::cout << std::endl << std::endl;

    avl->display();

    delete avl;

    return 0;
}
