#include <stdlib.h>
#include <stdio.h>
#include "binary_tree_debugger.h"
#include "noeud.h"

Arbre alloue_noeud(int val) {
    Noeud *n = malloc(sizeof(Noeud));
    if (!n)
        return NULL;
    n->valeur = val;
    n->fg = NULL;
    n->fd = NULL;
    return n;
}

void construit_arbre(Arbre *a, FILE *f) {
    int n = 0;
    fscanf(f, "%d", &n);
    if (n) {
        *a = alloue_noeud(n);
        construit_arbre(&(*a)->fg, f);
        construit_arbre(&(*a)->fd, f);
    }
}

void detruit_arbre(Arbre *a) {
    if (!*a)
        return ;
    detruit_arbre(&(*a)->fg);
    detruit_arbre(&(*a)->fd);
    free(*a);
    a = NULL;
}

void example() {
    Arbre a = NULL;

    FILE *f = fopen("arbre.txt", "r");
    construit_arbre(&a, f);
    fclose(f);

    btd_console_print(a);

    detruit_arbre(&a);
}
