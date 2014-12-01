// in bst.cpp
#include <iostream>
#include "bst.h"

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::add(int n)
{
    Node *node = new Node();
    node->data = n;

    if(root == NULL)
    {
        root = node;
    }
    else
    {
        if(n < root->data)
        {
            root->right = node;
        }
        else
        {
            root->left = node;
        }
    }
}

void BinarySearchTree::del(int n)
{
}

void BinarySearchTree::display()
{
    Node *temp = root;

    if(temp)
    {
        if(temp->right)
        {
            temp = root->right;

            while(temp)
            {
                std::cout << temp->data << std::endl;
                temp = temp->right;
            }
        }

        temp = root;
        std::cout << temp->data << std::endl;

        if(temp->left)
        {
            temp = root->left;

            while(temp)
            {
                std::cout << temp->data << std::endl;
                temp = temp->left;
            }
        }
    }
}
