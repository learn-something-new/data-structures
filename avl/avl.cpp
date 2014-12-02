// in avl.cpp
#include <iostream>
#include "avl.h"

AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::~AVLTree()
{
    if(root)
    {
        delete root;
    }
}

void AVLTree::addNode(Node *tree, Node *node, bool &fixBalance)
{

    if(node->getData() < tree->getData())
    {
        if(tree->getLeft() == NULL)
        {
            tree->setLeft(node);
            node->setParent(tree);
            fixBalance = true;
        }
        else
        {
            addNode(tree->getLeft(), node, fixBalance);
        }
    }
    else
    {
        if(tree->getRight() == NULL)
        {
            tree->setRight(node);
            node->setParent(tree);
            fixBalance = true;
        }
        else
        {
            addNode(tree->getRight(), node, fixBalance);
        }
    }
}

void AVLTree::add(int n)
{
    Node *node = new Node(n);

    if(root == NULL)
    {
        root = node;
    }
    else
    {
        bool fixBalance = false;
        AVLTree::addNode(root, node, fixBalance);
    }
}

Node* AVLTree::find(int n)
{
    Node* temp = NULL;

    if(root)
    {
        temp = AVLTree::find(n, root);
    }

    return temp;
}

void AVLTree::del(int n)
{
    if(root)
    {
        Node *temp;

        AVLTree::find(n, root, true);
    }
}

Node* AVLTree::find(int n, Node *node, bool del)
{
    Node *temp = NULL;

    if(node->getData() == n)
    {
        temp = node;
    }
    else
    {
        if(node->hasChildren())
        {
            Node* left = node->getLeft();
            Node* right = node->getRight();

            if(left)
            {
                temp = AVLTree::find(n, left, del);

                if(del && temp == left)
                {
                    node->setLeft(NULL);
                    AVLTree::reAddBranch(temp);
                }
            }

            if(!temp && right)
            {
                temp = AVLTree::find(n, right, del);

                if(del && temp == right)
                {
                    node->setRight(NULL);
                    AVLTree::reAddBranch(temp);
                }
            }
        }
    }

    return temp;
}

void AVLTree::reAddBranch(Node *node)
{
    if(node->getRight())
    {
        AVLTree::addBranch(node->getRight());
    }

    if(node->getLeft())
    {
        AVLTree::addBranch(node->getLeft());
    }

    delete node;
}

void AVLTree::addBranch(Node *node)
{
    AVLTree::add(node->getData());

    if(node->hasChildren())
    {
        Node* left = node->getLeft();
        Node* right = node->getRight();

        if(left)
        {
            AVLTree::addBranch(left);
        }

        if(right)
        {
            AVLTree::addBranch(right);
        }
    }
}

void AVLTree::printTree(Node *node)
{
    std::cout << node->getData() << std::endl;

    if(node->hasChildren())
    {
        Node* left = node->getLeft();
        Node* right = node->getRight();

        if(left)
        {
            AVLTree::printTree(left);
        }

        if(right)
        {
            AVLTree::printTree(right);
        }
    }
}

void AVLTree::display()
{
    if(root)
    {
        AVLTree::printTree(root);
    }
}
