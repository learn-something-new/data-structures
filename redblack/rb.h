// in rb.h
#include <iostream>

enum Color
{
    red = 1,
    black = 0
};

struct Node
{
    int data;
    Color color;
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
        color = black;
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
        void addBranch(Node *node);
        void reAddBranch(Node *node);
        Node* deleteBranch(Node *node);
        Node* find(int n, Node *node, bool del = false);

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void add(int n);
        void del(int n);
        void display();
        Node* find(int n);
};

