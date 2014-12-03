// in avl.cpp
#include <iostream>
#include "avl.h"

void printChildren(Node * node, bool parent = false)
{
    std::string strRText = "the right node was ";
    std::string strLText = "the left node was ";

    if(parent)
    {
        std::string strRText = "the parents right node was ";
        std::string strLText = "the parents left node was ";
    }
    else
    {
        std::cout << "the parent is " << node->parent()->data() << std::endl;
    }


    if(node->left())
    {
        std::cout << strLText << node->left()->data() << std::endl;
    }
    else
    {
        std::cout << strLText << "null" << std::endl;
    }

    if(node->right())
    {
        std::cout << strRText << node->right()->data() << std::endl;
    }
    else
    {
        std::cout << strRText << "null" << std::endl;
    }
}

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
            std::cout << "adding " << node->data() << std::endl;
            tree->left(node);
            node->parent(tree);
            std::cout << tree->left()->data() << " is the left child of " << tree->data() << std::endl;
            std::cout << node->data() << " is the child of " << node->parent()->data() << std::endl;
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
                    tree->decrement();
                    fixLeftTree(tree, fixBalance);
                    break;
                case 0:
                    tree->decrement();
                    fixBalance = true;
                    break;
                case 1:
                    tree->decrement();
                    fixBalance = false;
                    break;
            }
        }
    }
    else
    {
        if(tree->right() == NULL)
        {
            std::cout << "adding " << node->data() << std::endl;
            tree->right(node);
            node->parent(tree);
            std::cout << tree->right()->data() << " is the right child of " << tree->data() << std::endl;
            std::cout << node->data() << " is the child of " << node->parent()->data() << std::endl;
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
                    tree->increment();
                    fixRightTree(tree, fixBalance);
                    break;
                case 0:
                    tree->increment();
                    fixBalance = true;
                    break;
                case 1:
                    tree->increment();
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
        std::cout << "adding root node " << node->data() << std::endl;
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
    Node *a = c->parent();
    std::cout << "left rotate on " << c->data() << std::endl;

    printChildren(c);
    printChildren(a, true);

    if(a->parent())
    {
        std::cout << "parent's parent is " << a->parent()->data() << std::endl;
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

    if(c->left())
    {
        std::cout << "the left node is " << c->left()->data() << std::endl;
    }

    if(d->left())
    {
        std::cout << "the right node is " << d->left()->data() << std::endl;
    }

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
    Node *a = b->parent();

    std::cout << "right rotate on " << b->data() << std::endl;

    printChildren(b);
    printChildren(a, true);

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
    if(node->left()->balanceFactor() == -1)
    {
        leftRotation(node->right());
        fixBalance = false;
    }

    if(node->parent()->parent() == NULL)
    {
        root = node->parent();
    }
}

void AVLTree::fixLeftTree(Node *node, bool &fixBalance)
{
    if(node->right()->balanceFactor() == -1)
    {
        rightRotation(node->left());
        fixBalance = false;
    }

    if(node->parent()->parent() == NULL)
    {
        root = node->parent();
    }
}
