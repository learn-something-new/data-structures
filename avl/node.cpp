// in node.cpp
#include <iostream>
#include "node.h"

Node::Node()
{
    nBalanceFactor = 0;
}

Node::Node(int n, Node *nodeParent, Node *left, Node *right)
{
    nData = n;
    nBalanceFactor = 0;
    nodeParent = nodeParent;
    nodeLeft = std::auto_ptr<Node> (left);
    nodeRight = std::auto_ptr<Node> (right);
}

void Node::add(int n, Node *nodeParent)
{
}

void Node::del(int n)
{
}

int Node::data()
{
    return nData;
};

void Node::data(int n)
{
    nData = n;
}

Node* Node::left()
{
    return nodeLeft.get();
}

void Node::left(Node *node)
{
    nodeLeft.release();

    if(node)
    {
        nodeLeft = std::auto_ptr<Node> (node);
    }
}

Node* Node::right()
{
    return nodeRight.get();
}

void Node::right(Node *node)
{
    nodeRight.release();

    if(node)
    {
        nodeRight = std::auto_ptr<Node> (node);
    }
}

Node* Node::parent()
{
    return nodeParent.get();
}

void Node::parent(Node *node)
{
    nodeParent.release();

    if(node)
    {
        nodeParent = std::auto_ptr<Node> (node);
    }
}

void Node::balanceFactor(int n)
{
    nBalanceFactor = n;
}

int Node::balanceFactor()
{
    return nBalanceFactor;
}

void Node::increment()
{
    nBalanceFactor++;
}

void Node::decrement()
{
    nBalanceFactor--;
}

bool Node::hasChildren()
{
    bool status = false;

    if(nodeLeft.get() || nodeRight.get())
    {
        status = true;
    }

    return status;
}
