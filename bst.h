#include <iostream>
#include <cstdlib>
using namespace std;

struct tree_node
{
    tree_node * lo;
    tree_node * hi;
    tree_node * parent;
    double data;
};

class BinarySearchTree
{
    private:
        tree_node * root;
        int tsize (tree_node * node);
        double tmin (tree_node * node);
        double tmax (tree_node * node);
        void tmin_p (tree_node * node);
        void clear_node (tree_node * node);
    public:
        BinarySearchTree ()
        {
            root = nullptr;
        }
        ~BinarySearchTree ()
        {
            treeClear ();
        }
        void insert (double);
        void remove (double);
        int treeSize ();
        double treeMin ();
        double treeMax ();

        tree_node * getRoot ();
        tree_node * getNode (tree_node * node, double value);
        tree_node * treeMinTree ();
        tree_node * treeMaxTree ();
        tree_node * tminTree (tree_node * node);
        tree_node * tmaxTree (tree_node * node);

        tree_node * nextHi (tree_node * node);
        tree_node * nextLo (tree_node * node);

        void treeClear ();
};

void BinarySearchTree::insert (double d)
{
    tree_node * t = new tree_node;
    tree_node * parent;
    t->data = d;
    t->lo = nullptr;
    t->hi = nullptr;
    parent = nullptr;
    // is this a new tree?
    if (root == nullptr)
        root = t;
    else
    {
        tree_node * node;
        node = root;
        while (node != nullptr)
        {
            parent = node;
            if (t->data > node->data)
                node = node->hi;
            else
                node = node->lo;
        }

        t->parent = parent;
        if (t->data < parent->data)
            parent->lo = t;
        else
            parent->hi = t;
    }
}

void BinarySearchTree::remove (double d)
{
    if (root == nullptr)
        return;

    tree_node * node = getNode (root, d);
    tree_node * parent;
    if (node->parent != nullptr)
        parent = node->parent;

    // node has no children
    if ( node->lo == nullptr && node->hi == nullptr)
    {
        if (parent->lo == node)
            parent->lo = nullptr;
        else
            parent->hi = nullptr;
        delete node;
        return;
    }

    // Node has single child
    if ((node->lo == nullptr && node->hi != nullptr) ||
            (node->lo != nullptr && node->hi == nullptr))
    {
        if (node->lo == nullptr && node->hi != nullptr)
        {
            if (parent->lo == node)
            {
                parent->lo = node->hi;
                parent->lo->parent = parent;
                std::cout << "(" << parent->lo->data << ")" << std::endl;
                delete node;
            }
            else
            {
                std::cout << "***a2***" << parent->data << std::endl;
                if (node->hi == nullptr)
                    std::cout << "NULL hi" << std::endl;
                if (node->lo == nullptr)
                    std::cout << "NULL lo" << std::endl;
                parent->hi = node->hi;
                std::cout << "---[" << parent->hi->data << "]---" << std::endl;
                parent->hi->parent = parent;
                std::cout << "---[" << parent->hi->parent->data << "]---" << std::endl;
                delete node;
            }
        }
        else
        {
            if (parent->lo == node)
            {
                std::cout << "***a3***" << std::endl;
                parent->lo = node->lo;
                parent->lo->parent = parent;
                delete node;
            }
            else
            {
                std::cout << "***a4***" << std::endl;
                parent->hi = node->lo;
                parent->hi->parent = parent;
                delete node;
            }
        }
        return;
    }


    // Node has 2 children; replace with smallest value in hi subtree
    if (node->lo != nullptr && node->hi != nullptr)
    {
        std::cout << "***A***" << std::endl;
        tree_node * subtree;
        subtree = node->hi;
        if (subtree->lo == nullptr && subtree->hi == nullptr)
        {
            node = subtree;
            delete subtree;
            node->hi = nullptr;
        }
        else // hi child has children
        {
            if ((node->hi)->lo != nullptr)
            {
                tree_node * lnode = node->hi->lo;
                tree_node * lparent = node->hi;
                while (lnode->lo != nullptr)
                {
                    lparent = lnode;
                    lnode = lnode->lo;
                }
                node->data = lnode->data;
                lnode->hi->parent = node;
                delete lnode;
            }
            else
            {
                tree_node * temp = node->hi;
                node->data = temp->data;
                node->hi = temp->hi;
                node->parent = temp->parent;
                delete temp;
            }

        }
        return;
    }

}

int BinarySearchTree::treeSize ()
{
    return tsize (root);
}

int BinarySearchTree::tsize (tree_node * node)
{
    if (node == nullptr)
        return 0;
    else
        return tsize (node->lo) + 1 + tsize (node->hi);
}

void BinarySearchTree::tmin_p (tree_node * node)
{
    while (node->lo)
        node = node->lo;
}

double BinarySearchTree::treeMin ()
{
    return tmin (root);
}

double BinarySearchTree::tmin (tree_node * node)
{
    while (node->lo)
        node = node->lo;

    return node->data;
}

double BinarySearchTree::treeMax ()
{
    return tmax (root);
}

double BinarySearchTree::tmax (tree_node * node)
{
    while (node->hi)
        node = node->hi;

    return node->data;
}

tree_node * BinarySearchTree::treeMinTree ()
{
    return tminTree (root);
}

tree_node * BinarySearchTree::tminTree (tree_node * node)
{
    while (node->lo)
        node = node->lo;

    return node;
}

tree_node * BinarySearchTree::treeMaxTree ()
{
    return tmaxTree (root);
}

tree_node * BinarySearchTree::tmaxTree (tree_node * node)
{
    while (node->hi)
        node = node->hi;

    return node;
}

void BinarySearchTree::treeClear ()
{
    clear_node (root);
}

void BinarySearchTree::clear_node (tree_node * node)
{
    if (node != nullptr)
    {
        clear_node (node->lo);
        clear_node (node->hi);
        delete node;
    }
}

tree_node * BinarySearchTree::getRoot ()
{
    tree_node * node = root;
    return node;
}

tree_node * BinarySearchTree::getNode (tree_node * node, double value)
{
	if (value < node->data) 
		return getNode (node->lo, value);
	else if (value > node->data)
		return getNode (node->hi, value);
	else
		return node;
}

tree_node * BinarySearchTree::nextHi (tree_node * node)
{
    if (node->hi != nullptr)
        return tminTree (node->hi);

    tree_node * y = node->parent;
    while (y != nullptr && node == y->hi)
    {
        node = y;
        y = y->parent;
    }
    return y;
}

tree_node * BinarySearchTree::nextLo (tree_node * node)
{
    if (node->lo != nullptr)
        return tmaxTree (node->lo);

    tree_node * y = node->parent;
    while (y != nullptr && node == y->lo)
    {
        node = y;
        y = y->parent;
    }
    return y;
}
