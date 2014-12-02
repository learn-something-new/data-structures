// in avl.h
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
    }
};

class AVLTree
{
    private:
        Node *root;
        bool hasChildren(Node *node);
        void printTree(Node *node);
        void addBranch(Node *node);
        void reAddBranch(Node *node);
        Node* deleteBranch(Node *node);
        Node* find(int n, Node *node, bool del = false);

    public:
        AVLTree();
        ~AVLTree();
        void add(int n);
        void del(int n);
        void display();
        Node* find(int n);
};

