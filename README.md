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
