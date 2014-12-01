// in bst.cpp
#include <iostream>
#include "bst.h"

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    if(root)
    {
        delete BinarySearchTree::deleteBranch(root);
    }
}

Node* BinarySearchTree::deleteBranch(Node *node)
{
    if(BinarySearchTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

        if(left)
        {
            delete BinarySearchTree::deleteBranch(left);
        }

        if(right)
        {
           delete BinarySearchTree::deleteBranch(right);
        }
    }

    return node;
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

Node* BinarySearchTree::find(int n)
{
    Node* temp = NULL;

    if(root)
    {
        temp = BinarySearchTree::find(n, root);
    }

    return temp;
}

void BinarySearchTree::del(int n)
{
    if(root)
    {
        Node *temp;

        temp = BinarySearchTree::find(n, root);

        if(temp)
        {
            if(BinarySearchTree::hasChildren(temp))
            {
            }
        }
    }
}

Node* BinarySearchTree::find(int n, Node *node)
{
    Node *temp = NULL;

    std::cout << node->data << std::endl;

    if(node->data == n)
    {
        temp = node;
    }
    else
    {
        if(BinarySearchTree::hasChildren(node))
        {
            Node* left = node->left;
            Node* right = node->right;

            if(left)
            {
               temp = BinarySearchTree::find(n, left);
            }

            if(!temp && right)
            {
                temp = BinarySearchTree::find(n, right);
            }
        }
    }

    return temp;
}

void BinarySearchTree::printTree(Node *node)
{
    std::cout << node->data << std::endl;

    if(BinarySearchTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

        if(left)
        {
            BinarySearchTree::printTree(left);
        }

        if(right)
        {
            BinarySearchTree::printTree(right);
        }
    }
}

void BinarySearchTree::display()
{
    if(root)
    {
        BinarySearchTree::printTree(root);
    }
}
