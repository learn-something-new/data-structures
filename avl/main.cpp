// in main.cpp
#include <iostream>
#include "avl.h"

int main()
{
    AVLTree *avl = new AVLTree();

    std::cout << "adding 100" << std::endl;
    avl->add(100);

    std::cout << "adding 5" << std::endl;
    avl->add(5);

    std::cout << "adding 3" << std::endl;
    avl->add(3);

    std::cout << "adding 12" << std::endl;
    avl->add(12);

    std::cout << "adding 1" << std::endl;
    avl->add(1);

    std::cout << "adding 9" << std::endl;
    avl->add(9);

    std::cout << "adding 7" << std::endl;
    avl->add(7);

    delete avl;

    return 0;
}
