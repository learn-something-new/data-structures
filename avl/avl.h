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
        void addNode(Node *tree, Node *node, bool &fixBalance);
        Node* find(int n, Node *node, bool del = false);
        void leftRotation(Node *node);
        void rightRotation(Node *node);
        void fixRightTree(Node *node, bool &fixBalance);
        void fixLeftTree(Node *node, bool &fixBalance);

    public:
        AVLTree();
        void add(int n);
        void del(int n);
        void display();
        int find(int n);
};
