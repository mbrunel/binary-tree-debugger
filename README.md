# Binary-tree-debugger

Binary tree debugging header-only library, written in C at the destination of UGE students.

## Usage

You should have somewhere in your code, a declaration that looks like this:

```
typedef struct noeud {
    int valeur; // only integer support as long as genericity isn't requested
    struct noeud *fg;
    struct noeud *fd;
} Noeud , *Arbre;
```

Below it, copy-paste this:
```
#define BINARY_TREE_DEBUGGER_IMPL
#include "binary_tree_debugger.h"
```

then include binary_tree_debugger.h normally in the files you want.

For more usage details, look at the examples folder, which contains a minimal working example.

## Features

Pretty print of binary tree in terminal.
