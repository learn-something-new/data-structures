// in node.h
#include <iostream>

struct Node
{
    private:
        int nData;
        int nBalanceFactor;
        std::auto_ptr<Node> nodeLeft;
        std::auto_ptr<Node> nodeRight;
        std::auto_ptr<Node> nodeParent;

    public:
        Node();
        Node(int n, Node* parent = NULL, Node* left = NULL, Node* right = NULL);

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

        void increment();
        void decrement();
        bool hasChildren();
};

