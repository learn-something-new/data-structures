// in avl.h
#include <iostream>
#include "node.h"

class AVLTree
{
    private:
        Node *root;
        void printTree(Node *node);
        void addBranch(Node *node);
        void reAddBranch(Node *node);
        Node* find(int n, Node *node, bool del = false);

    public:
        AVLTree();
        ~AVLTree();
        void add(int n);
        void del(int n);
        void display();
        Node* find(int n);
};

