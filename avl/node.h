// in node.h
#include <iostream>

struct Node
{
    private:
        int data;
        Node *left;
        Node *right;
        Node *parent;

    public:
        Node();
        Node(int n, Node* parent = NULL);
        ~Node();
        void add(int n, Node *parent);
        void del(int n);
        void setLeft(Node* node);
        void setRight(Node* node);
        void setParent(Node* node);
        int getData();
        bool hasChildren();
        Node* getLeft();
        Node* getRight();
        Node* getParent();
};

