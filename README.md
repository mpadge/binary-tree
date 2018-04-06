[![Build Status](https://travis-ci.org/mpadge/binary-tree.svg)](https://travis-ci.org/mpadge/binary-tree) 

# get nth element of binary search tree 

Extraction of extrema (min/max) from binary search trees is easy. Efficient
extraction of other elements (*n*-th smallest or largest) generally requires
modification of the underlying structure of the tree. Two main modifications are
necessary:

1. Conventional extraction of extrema requires traversing the tree in a single
   direction only, whereas step-wise iteration requires bi-directional traversal
   which necessitates additional pointers to the parents of each element.
2. Pointers to binary trees elements are commonly constructed as `"private"`
   class members, but step-wide iteration requires these to be exposed. This is
   potentially dangerous, and can readily result in memory leaks. The
   [`travis-ci` badge](https://travis-ci.org/mpadge/binary-tree) will only be
   green in the absence of memory leaks.


## This repo

The business end is contained in the two `bst.*` files. The whole thing can
loaded in a ([`tmux`](https://github.com/tmux/tmux/wiki)) terminal with `bash
tmux-start.bash`, and the code then run with `make`. A [`valgrind` check for
memory leaks](http://valgrind.org/docs/manual/mc-manual.html) can be run with
`make val`, demonstrating that all pointers are successfully deleted, and there
are no memory leaks. This is also run for the [`travis-ci` checks for this
repo](https://travis-ci.org/mpadge/binary-tree).

## How does it work?

Simply bundle the `bst.h` file into your code, then construct a tree with
```
BinarySearchTree b;
for (size_t i = 0; i < n; i++)
    b.insert (value [i]);
```
The usual functions exist, `b.treeSize()`, `b.TreeMin()`, `b.treeMax()`, and
`b.remove()`. Tracing sequential values first requires extracting a pointer to
the root of the tree, re-directing that pointer to one of the extrema, and then
iterating it. The following code demonstrates
```
tree_node * node = b.getRoot();
node = b.getNode (node, b.treeMin()); // now points to min node
double value = node->data; // the min value
node = b.nextHi (node);
value = node->data // the next minimal node
```
A `nextLo` function can be used to iterate along decreasing values. Checkout
[`bst.cpp`](https://github.com/mpadge/binary-tree/blob/master/bst.cpp) for more
detailed examples, along with the corresponding output shown on the [`travis`
build](https://travis-ci.org/mpadge/binary-tree).

