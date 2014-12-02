// in node.cpp
#include <iostream>
#include "node.h"

Node::Node()
{
    nodeLeft = NULL;
    nodeRight = NULL;
    nodeParent = NULL;
}

Node::Node(int n, Node *nodeParent)
{
    nData = n;
    nodeLeft = NULL;
    nodeRight = NULL;
    nodeParent = nodeParent;
}

Node::~Node()
{
    Node *temp;
    std::cout << "deleting " << nData << std::endl;

    if(nodeLeft)
    {
        temp = nodeLeft;
        nodeLeft = NULL;
        delete temp;
    }

    if(nodeRight)
    {
        temp = nodeRight;
        nodeRight = NULL;
        delete temp;
    }
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
    return nodeRight;
}

void Node::parent(Node *node)
{
    nodeParent = node;
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
