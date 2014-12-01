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

        BinarySearchTree::find(n, root, true);
    }
}

Node* BinarySearchTree::find(int n, Node *node, bool del)
{
    Node *temp = NULL;

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
               temp = BinarySearchTree::find(n, left, del);
            }

            if(!temp && right)
            {
                temp = BinarySearchTree::find(n, right, del);
            }

            if(del && temp)
            {
                if(temp == right)
                {
                    node->right = NULL;

                    if(temp->right)
                    {
                        BinarySearchTree::addBranch(temp->right);
                    }

                    if(temp->left)
                    {
                        BinarySearchTree::addBranch(temp->left);
                    }

                    delete temp;
                }
                else if(temp == left)
                {
                    node->left = NULL;

                    if(temp->right)
                    {
                        BinarySearchTree::addBranch(temp->right);
                    }

                    if(temp->left)
                    {
                        BinarySearchTree::addBranch(temp->left);
                    }

                    delete temp;
                }
            }
        }
    }

    return temp;
}

void BinarySearchTree::addBranch(Node *node)
{
    BinarySearchTree::add(node->data);

    if(BinarySearchTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

        if(left)
        {
            BinarySearchTree::addBranch(left);
        }

        if(right)
        {
            BinarySearchTree::addBranch(right);
        }
    }
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
