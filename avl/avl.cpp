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

    if(node->data() < tree->data())
    {
        if(tree->left() == NULL)
        {
            tree->left(node);
            node->parent(tree);
            fixBalance = true;
        }
        else
        {
            addNode(tree->left(), node, fixBalance);
        }
    }
    else
    {
        if(tree->right() == NULL)
        {
            tree->right(node);
            node->parent(tree);
            fixBalance = true;
        }
        else
        {
            addNode(tree->right(), node, fixBalance);
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

    if(node->data() == n)
    {
        temp = node;
    }
    else
    {
        if(node->hasChildren())
        {
            Node* left = node->left();
            Node* right = node->right();

            if(left)
            {
                temp = AVLTree::find(n, left, del);

                if(del && temp == left)
                {
                    node->left(NULL);
                    AVLTree::reAddBranch(temp);
                }
            }

            if(!temp && right)
            {
                temp = AVLTree::find(n, right, del);

                if(del && temp == right)
                {
                    node->right(NULL);
                    AVLTree::reAddBranch(temp);
                }
            }
        }
    }

    return temp;
}

void AVLTree::reAddBranch(Node *node)
{
    if(node->right())
    {
        AVLTree::addBranch(node->right());
    }

    if(node->left())
    {
        AVLTree::addBranch(node->left());
    }

    delete node;
}

void AVLTree::addBranch(Node *node)
{
    AVLTree::add(node->data());

    if(node->hasChildren())
    {
        Node* left = node->left();
        Node* right = node->right();

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
    std::cout << node->data() << std::endl;

    if(node->hasChildren())
    {
        Node* left = node->left();
        Node* right = node->right();

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
