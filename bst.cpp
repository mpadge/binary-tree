#include "bst.h"

#include <random>
#include <algorithm> // sort
#include <iostream>

void mktree (BinarySearchTree &b, std::vector <data_type> &d)
{
    for (size_t i = 0; i < d.size (); i++)
    {
        b.insert (d [i]);
    }
}

void del (BinarySearchTree &b)
{
    b.remove (b.treeMin ());
}

void test_delete_insert (BinarySearchTree &b)
{
    // delete some elements, tracking min values and tree sizes
    for (int i = 0; i < 20; i++)
    {
        del (b);
        std::cout << "min [" << i + 1 << "] = " << b.treeMin () << " / size = " <<
            b.treeSize () << std::endl;
    }
    // insert a new element
    b.insert (0.001);
    std::cout << "tree min after inserting 0.001 = " << b.treeMin () << std::endl;
    b.remove (0.001);
    std::cout << "tree min after deleting 0.001 = " << b.treeMin () << std::endl;
    std::cout << std::endl;
}

void test_trace_lowest (BinarySearchTree &b, unsigned int n)
{
    // trace the n smallest values of the tree
    data_type tmin = b.treeMin ();
    tree_node * tn = b.getRoot ();
    tn = b.getNode (tn, tmin);
    std::cout << std::endl << "sequence from lowest value:" << std::endl <<
        tn->data << std::endl;
    for (int i = 1; i < n; i++)
    {
        tn = b.nextHi (tn);
        std::cout << tn->data << std::endl;
    }
}

void test_trace_highest (BinarySearchTree &b, unsigned int n)
{
    data_type tmax = b.treeMax ();
    tree_node * tn = b.getRoot ();
    tn = b.getNode (tn, tmax);
    std::cout << "sequence from highest value:" << std::endl <<
        tn->data << std::endl;
    for (int i = 1; i < n; i++)
    {
        tn = b.nextLo (tn);
        std::cout << tn->data << std::endl;
    }
}

void test_nonexistent (BinarySearchTree &b, const data_type value)
{
    // try to get a non-existent node:
    std::cout << "searching for non-existent node: ";
    tree_node * tn = b.getRoot ();
    tn = b.getNode (tn, value);
}

void test_step_below_lowest (BinarySearchTree &b)
{
    // try to step below lowest node
    std::cout << "stepping below lowest node: ";
    tree_node * tn = b.getRoot ();
    tn = b.getNode (tn, b.treeMin ());
    tn = b.nextLo (tn);
}

void test_step_above_highest (BinarySearchTree &b)
{
    // try to step above highest node
    std::cout << "stepping above highest node: ";
    tree_node * tn = b.getRoot ();
    tn = b.getNode (tn, b.treeMax ());
    tn = b.nextHi (tn);
}


int main ()
{
    BinarySearchTree b;

    std::default_random_engine generator;
    // presumes data_type = double!
    std::uniform_real_distribution<double> distribution (0.0,1.0);

    unsigned int n = 1000;
    std::vector <data_type> d (n);
    for (size_t i = 0; i < n; i++)
        d [i] = distribution (generator);
    // This code works even with very mal-formed trees constructed from sorted
    // data:
    //std::sort (d.begin (), d.end ());
    mktree (b, d);

    std::cout << "tree size = " << b.treeSize () << std::endl;
    std::cout << "tree min = " << b.treeMin () << std::endl;
    std::cout << "tree max = " << b.treeMax () << std::endl;

    // a few sanity checks
    test_delete_insert (b);
    test_nonexistent (b, 1234.5);
    test_step_below_lowest (b);
    test_step_above_highest (b);

    // Then the tracing routines
    test_trace_lowest (b, n = 10);
    test_trace_highest (b, n = 10);
}
