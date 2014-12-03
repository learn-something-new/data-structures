// in node.cpp
#include <iostream>
#include "node.h"

Node::Node()
{
    nBalanceFactor = 0;
    nodeLeft = NULL;
    nodeRight = NULL;
    nodeParent = NULL;
}

Node::Node(int n, Node *nodeParent)
{
    nData = n;
    nBalanceFactor = 0;
    nodeLeft = NULL;
    nodeRight = NULL;
    nodeParent = nodeParent;
}

Node::~Node()
{
    if(nodeLeft)
    {
        Node *temp = nodeLeft;
        nodeLeft = NULL;
        delete temp;
    }

    if(nodeRight)
    {
        Node *temp = nodeRight;
        nodeRight = NULL;
        delete temp;
    }

    nodeParent = NULL;
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
    return nodeLeft;
}

void Node::left(Node *node)
{
    nodeLeft = node;
}

Node* Node::right()
{
    return nodeRight;
}

void Node::right(Node *node)
{
    nodeRight = node;
}

Node* Node::parent()
{
    return nodeParent;
}

void Node::parent(Node *node)
{
    nodeParent = node;
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

    if(nodeLeft || nodeRight)
    {
        status = true;
    }

    return status;
}
