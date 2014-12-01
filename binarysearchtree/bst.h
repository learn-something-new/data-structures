// in bst.h
#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        std::cout << "destroying: " << data << std::endl;
    }
};

class BinarySearchTree
{
    private:
       Node *root;

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void add(int n);
        void del(int n);
        void display();
};

