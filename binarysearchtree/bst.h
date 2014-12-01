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
    }
};

class BinarySearchTree
{
    private:
        Node *root;
        bool hasChildren(Node *node);
        void printTree(Node *node);
        Node* deleteBranch(Node *node);
        Node* find(int n, Node *node);

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void add(int n);
        void del(int n);
        void display();
        Node* find(int n);
};

