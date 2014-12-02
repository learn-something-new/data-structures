// in node.h
#include <iostream>

struct Node
{
    private:
        int nData;
        int nBalanceFactor;
        Node *nodeLeft;
        Node *nodeRight;
        Node *nodeParent;

    public:
        Node();
        Node(int n, Node* parent = NULL);
        ~Node();

        void add(int n, Node *parent);
        void del(int n);

        Node* left();
        void left(Node* node);

        Node* right();
        void right(Node* node);

        Node* parent();
        void parent(Node* node);

        int balanceFactor();
        void balanceFactor(int n);

        int data();
        void data(int n);

        bool hasChildren();
};

