// in bst.h
#include <iostream>

struct Node
{
    Node()
    {
    }

    ~Node()
    {
        std::cout << "destroying: " << data << std::endl;
    }

    int data;
};

class BinarySearchTree
{
    private:

    public:
        BinarySearchTree();
        ~BinarySearchTree();
};

