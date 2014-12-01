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
        std::cout << "adding " << node->data << " (root)" << std:: endl;
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
                    return;
                }
            }
        }

        if(n > temp->data)
        {
            std::cout << "adding " << node->data << " (right) child of " << temp->data << std:: endl;
            temp->right = node;
        }
        else
        {
            std::cout << "adding " << node->data << " (left) child of " << temp->data << std:: endl;
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

    if(BinarySearchTree::hasChildren(node))
    {
        Node* right = temp->right;;
        Node* left = temp->left;;

        while(right)
        {
            right = BinarySearchTree::next(temp);
        }

        while(left)
        {
            left = BinarySearchTree::next(temp);
        }
    }

    if(temp)
    {
        std::cout << temp-> data << std::endl;
    }

    return temp;
}

void BinarySearchTree::del(int n)
{
}

void BinarySearchTree::display()
{
    Node *temp = root;

    while(temp)
    {
        temp = BinarySearchTree::next(temp);
    }

    std::cout << root->data << std::endl;
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
