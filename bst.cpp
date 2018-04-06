#include "bst.h"

#include <random>
#include <algorithm> // sort
#include <iostream>

void mktree (BinarySearchTree &b, std::vector <double> &d)
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


int main ()
{
    BinarySearchTree b;

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution (0.0,1.0);

    unsigned int n = 1000;
    std::vector <double> d (n);
    for (size_t i = 0; i < n; i++)
        d [i] = distribution (generator);
    //std::sort (d.begin (), d.end ());
    mktree (b, d);

    std::cout << "tree size = " << b.treeSize () << std::endl;
    std::cout << "tree min = " << b.treeMin () << std::endl;
    std::cout << "tree max = " << b.treeMax () << std::endl;

    for (int i = 0; i < 20; i++)
    {
        del (b);
        std::cout << "min [" << i + 1 << "] = " << b.treeMin () << " / size = " <<
            b.treeSize () << std::endl;
    }
    b.insert (0.001);
    std::cout << "tree min = " << b.treeMin () << std::endl;
    b.remove (0.001);
    std::cout << "tree min = " << b.treeMin () << std::endl;

    double tmin = b.treeMin ();
    tree_node * tn = b.getRoot ();
    tn = b.getNode (tn, tmin);
    std::cout << "sequence from lowest value:" << std::endl <<
        tn->data << std::endl;
    for (int i = 0; i < 9; i++)
    {
        tn = b.nextHi (tn);
        std::cout << tn->data << std::endl;
    }

    double tmax = b.treeMax ();
    tn = b.getRoot ();
    tn = b.getNode (tn, tmax);
    std::cout << "sequence from highest value:" << std::endl <<
        tn->data << std::endl;
    for (int i = 0; i < 9; i++)
    {
        tn = b.nextLo (tn);
        std::cout << tn->data << std::endl;
    }

    //b.treeClear ();
}
