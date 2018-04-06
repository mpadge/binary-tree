# get nth element of binary search tree 

Extraction of extrema (min/max) from binary search trees is easy. Efficient
extraction of other elements (*n*-th smallest or largest) generally requires
modification of the underlying structure of the tree. In particular, pointers to
binary trees elements are commonly constructed as `"private"` class members.
These pointers need to be made `"public"` for efficient extraction of *n*-th
elements, so that positions can be iterated.

A further difference to traditional, simpler binary search tree structures is
that step-wise iteration requires additional pointers to the parents of each
element, whereas extrema can be extracted using pointers to children only.  Put
simply: extraction of extrema requires tree traversal in a single direction
only; extraction of *n*-th elements requires bi-directional traversal.

## This repo

The business end is contained in the two `bst.*` files. The whole thing can
loaded in a ([`tmux`](https://github.com/tmux/tmux/wiki)) terminal with `bash
tmux-start.bash`, and the code then run with `make`. A [`valgrind` check for
memory leaks](http://valgrind.org/docs/manual/mc-manual.html) can be run with
`make val`, demonstrating that all pointers are successfully deleted, and there
are no memory leaks.
