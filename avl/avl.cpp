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
        delete AVLTree::deleteBranch(root);
    }
}

Node* AVLTree::deleteBranch(Node *node)
{
    if(AVLTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

        if(left)
        {
            delete AVLTree::deleteBranch(left);
        }

        if(right)
        {
           delete AVLTree::deleteBranch(right);
        }
    }

    return node;
}

void AVLTree::add(int n)
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

        while(AVLTree::hasChildren(temp))
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

bool AVLTree::hasChildren(Node *node)
{
    bool children = false;

    if(node->left || node->right)
    {
        children = true;
    }

    return children;
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

    if(node->data == n)
    {
        temp = node;
    }
    else
    {
        if(AVLTree::hasChildren(node))
        {
            Node* left = node->left;
            Node* right = node->right;

            if(left)
            {
               temp = AVLTree::find(n, left, del);

               if(del && temp == left)
               {
                    node->left = NULL;
                    AVLTree::reAddBranch(temp);
               }
            }

            if(!temp && right)
            {
                temp = AVLTree::find(n, right, del);

                if(del && temp == right)
                {
                    node->right = NULL;
                    AVLTree::reAddBranch(temp);
                }
            }
        }
    }

    return temp;
}

void AVLTree::reAddBranch(Node *node)
{
    if(node->right)
    {
        AVLTree::addBranch(node->right);
    }

    if(node->left)
    {
        AVLTree::addBranch(node->left);
    }

    AVLTree::deleteBranch(node);
}

void AVLTree::addBranch(Node *node)
{
    AVLTree::add(node->data);

    if(AVLTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

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
    std::cout << node->data << std::endl;

    if(AVLTree::hasChildren(node))
    {
        Node* left = node->left;
        Node* right = node->right;

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
