#ifndef EXAMPLE_H
#define EXAMPLE_H

typedef struct noeud {
    int valeur;
    struct noeud *fg;
    struct noeud *fd;
} Noeud , *Arbre;

#endif
