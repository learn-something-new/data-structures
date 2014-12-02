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

void AVLTree::add(int n)
{
    Node *node;

    if(root == NULL)
    {
        node = new Node(n);
        root = node;
    }
    else
    {
        Node *temp = root;

        while(temp->hasChildren())
        {
            if(n > temp->getData())
            {
                if(temp->getRight())
                {
                    temp = temp->getRight();
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(temp->getLeft())
                {
                    temp = temp->getLeft();
                }
                else
                {
                    break;
                }
            }
        }

        node = new Node(n, temp);

        if(n > temp->getData())
        {
            temp->setRight(node);
        }
        else
        {
            temp->setLeft(node);
        }
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
