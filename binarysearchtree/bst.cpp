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
        Node *temp = root;

        while(BinarySearchTree::hasChildren(temp))
        {
            if(n > temp->data)
            {
                if(temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }
        }

        if(n > temp->data)
        {
            temp->right = node;
        }
        else
        {
            temp->left = node;
        }
    }
}

bool BinarySearchTree::hasChildren(Node *node)
{
    bool children = false;

    if(node->left || node->right)
    {
        children = true;
    }

    return children;
}

Node* BinarySearchTree::next(Node *node)
{
    Node* temp = NULL;

    std::cout << node->data << std::endl;

    if(BinarySearchTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

        if(left)
        {
            temp = left;
            BinarySearchTree::next(temp);
        }

        if(right)
        {
            temp = right;
            BinarySearchTree::next(temp);
        }
    }

    return temp;
}

void BinarySearchTree::del(int n)
{
}

void BinarySearchTree::display()
{
    Node *temp = root;

    /*
     *while(temp)
     *{
     *    temp = BinarySearchTree::next(temp);
     *}
     */

    BinarySearchTree::next(temp);
}

/*
 *    if(temp)
 *    {
 *        if(temp->right)
 *        {
 *            temp = root->right;
 *
 *            while(temp)
 *            {
 *                std::cout << temp->data << std::endl;
 *                temp = temp->right;
 *            }
 *        }
 *
 *        temp = root;
 *        std::cout << temp->data << std::endl;
 *
 *        if(temp->left)
 *        {
 *            temp = root->left;
 *
 *            while(temp)
 *            {
 *                std::cout << temp->data << std::endl;
 *                temp = temp->left;
 *            }
 *        }
 *    }
 */