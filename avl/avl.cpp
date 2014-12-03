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
    if(node->data() <= tree->data())
    {
        if(tree->left() == NULL)
        {
            tree->left(node);
            node->parent(tree);
            std::cout << node->data() << " as left child of parent " << node->parent()->data() << ", parent should be " << tree->data() << std::endl;
            std::cout << tree->parent() << std::endl;
            fixBalance = true;
        }
        else
        {
            addNode(tree->left(), node, fixBalance);
        }

        if(fixBalance)
        {
            switch(tree->balanceFactor())
            {
                case -1:
                    fixLeftTree(tree, fixBalance);
                    AVLTree::display();
                    break;
                case 0:
                    tree->decrement();
                    std::cout << "node " << tree->data() << " has a balance of " << tree->balanceFactor() << std::endl;
                    fixBalance = true;
                    break;
                case 1:
                    tree->decrement();
                    std::cout << "node " << tree->data() << " has a balance of " << tree->balanceFactor() << std::endl;
                    fixBalance = false;
                    break;
            }
        }
    }
    else
    {
        if(tree->right() == NULL)
        {
            tree->right(node);
            node->parent(tree);
            std::cout << node->data() << " as right child of parent " << node->parent()->data() << ", parent should be " << tree->data() << std::endl;
            fixBalance = true;
        }
        else
        {
            addNode(tree->right(), node, fixBalance);
        }

        if(fixBalance)
        {
            switch(tree->balanceFactor())
            {
                case -1:
                    fixRightTree(tree, fixBalance);
                    AVLTree::display();
                    break;
                case 0:
                    tree->increment();
                    std::cout << "node " << tree->data() << " has a balance of " << tree->balanceFactor() << std::endl;
                    fixBalance = true;
                    break;
                case 1:
                    tree->increment();
                    std::cout << "node " << tree->data() << " has a balance of " << tree->balanceFactor() << std::endl;
                    fixBalance = false;
                    break;
            }
        }
    }
}

void AVLTree::add(int n)
{
    Node *node = new Node(n);

    if(root == NULL)
    {
        root = node;
        //std::cout << "adding root node " << root->data() << std::endl;
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

void AVLTree::leftRotation(Node *c)
{
    std::cout << "left rotation on " << c->data() << std::endl;
    Node *a = c->parent();

    if(a)
    {
        std::cout << a->data() << std::endl;
    }

    std::cout << a->parent() << std::endl;

    if(a->parent())
    {
        std::cout << a->parent()->data() << std::endl;

        if(a->parent()->left() == a)
        {
            a->parent()->left(c);
        }
        else
        {
            a->parent()->right(c);
        }
    }

    Node *d = c->left();
    c->left(a);
    a->right(d);

    if(d)
    {
        d->parent(a);
    }

    c->parent(a->parent());
    a->parent(c);

    a->balanceFactor(0);
    c->balanceFactor(0);
}

void AVLTree::rightRotation(Node *b)
{
    //std::cout << "right rotation on " << b->data() << std::endl;
    Node *a = b->parent();

    if(a->parent())
    {
        if(a->parent()->left() == a)
        {
            a->parent()->left(b);
        }
        else
        {
            a->parent()->right(b);
        }
    }

    Node *e = b->right();
    b->right(a);
    a->left(e);

    if(e)
    {
        e->parent(a);
    }

    b->parent(a->parent());
    a->parent(b);

    a->balanceFactor(0);
    b->balanceFactor(0);
}

void AVLTree::fixRightTree(Node *node, bool &fixBalance)
{
    leftRotation(node->right());
    fixBalance = false;

    if(node->parent()->parent() == NULL)
    {
        root = node->parent();
    }
}

void AVLTree::fixLeftTree(Node *node, bool &fixBalance)
{
    rightRotation(node->left());
    fixBalance = false;

    if(node->parent()->parent() == NULL)
    {
        root = node->parent();
    }
}
