// in node.cpp
#include <iostream>
#include "node.h"

Node::Node()
{
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::Node(int n, Node *parent)
{
    data = n;
    left = NULL;
    right = NULL;
    parent = parent;
}

Node::~Node()
{
    Node *temp;
    std::cout << "deleting " << data << std::endl;

    if(left)
    {
        temp = left;
        left = NULL;
        delete temp;
    }

    if(right)
    {
        temp = right;
        right = NULL;
        delete temp;
    }
}

bool Node::hasChildren()
{
    bool status = false;

    if(left || right)
    {
        status = true;
    }

    return status;
}

void Node::add(int n, Node *parent)
{
}

void Node::del(int n)
{
}

int Node::getData()
{
    return data;
};

Node* Node::getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

Node* Node::getParent()
{
    return right;
}

void Node::setParent(Node *node)
{
    parent = node;
}

void Node::setLeft(Node *node)
{
    left = node;
}

void Node::setRight(Node *node)
{
    right = node;
}
